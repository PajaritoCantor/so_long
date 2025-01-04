
```C
/**
 * Decodificar/cargar un archivo PNG en un buffer.
 * @param[in] path Ruta al archivo PNG.
 * @return Si tiene éxito se devuelven los datos de textura, si no NULL.
 */

#include "MLX42/MLX42_Int.h"

mlx_texture_t* mlx_load_png(const char* path)
{
	MLX_NONNULL(path);

	mlx_texture_t* image;
	if (!(image = malloc(sizeof(mlx_texture_t))))
		return ((void*)mlx_error(MLX_MEMFAIL));

	uint32_t error;
	image->bytes_per_pixel = BPP;
	if ((error = lodepng_decode32_file(&image->pixels, &image->width, &image->height, path)))
	{
		free(image);
		// Imprimir error explícitamente a propósito
		fprintf(stderr, "MLX42: LodePNG: %s\n", lodepng_error_text(error));
		return ((void*)mlx_error(MLX_INVPNG));
	}
	return (image);
}
/**
* Convierte una textura dada en una imagen.
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] texture La textura que se usará para crear la imagen.
* @return mlx_image_t* La imagen creada a partir de la textura.
*/

#include "MLX42/MLX42_Int.h"

mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(texture);

	mlx_image_t* image = mlx_new_image(mlx, texture->width, texture->height);
	if (image == NULL)
		return (NULL);

	uint8_t* pixelx;
	uint8_t* pixeli;
	for (uint32_t i = 0; i < texture->height; i++)
	{
		pixelx = &texture->pixels[(i * texture->width) * texture->bytes_per_pixel];
		pixeli = &image->pixels[(i * image->width) * texture->bytes_per_pixel];
		memmove(pixeli, pixelx, texture->width * texture->bytes_per_pixel);
	}
	return (image);
}
/**
* Elimina una textura liberando los datos asignados.
* @param[in] texture La textura que se liberará.
*/

void mlx_delete_texture(mlx_texture_t* texture)
{
	MLX_NONNULL(texture);

	mlx_freen(2, texture->pixels, texture);
}

#include «MLX42/MLX42_Int.h»

/**
 
Esto puede enfadar a algunos pero en su lugar decidí escribir mi propio formato de imagen, muy similar a XPM2, que parece ser la mejor opción entre las 3 versiones. La única diferencia está en la cabecera que lleva el tipo de archivo, anchura, altura, número de colores y finalmente el tipo de color aka 'c' para RGBA8 o 'm' para salida monocroma.
 
Los cambios, en mi opinión, simplifican mucho el formato XPM en algo que literalmente cualquiera puede usar sin muchas conjeturas sobre qué hace qué.

Adicionalmente con el formato estilo C, la idea es que simplemente lo incluyas directamente en la compilación del programa (ya que es solo C). 

Tan conveniente como esto es, lo encuentro horrible especialmente la variante XPM3. Si nos ceñimos al formato estilo XPM, la conversión debería ser muy fácil y directa a este formato sin embargo.
//= Private =//

/**
 * Parses HEX color channel e.g: "0F"
 *
 * @param channel The 2 character string to parse.
 * @return Int value of the channel.
 */
static uint8_t	mlx_parse_hex_channel(char *channel)
{
	char	temp_chan[] = {channel[0], channel[1], '\0'};

	return (strtol(temp_chan, NULL, 16));
}

/**
 * Parses the XPM color value entry e.g: ".X #00FF00FF"
 * into the color table while also verifying the format.
 * @param xpm The XPM.
 * @param line The line to parse.
 * @param ctable The color hash table.
 * @param s Size of the hash table
 * @return True or false depending on if it successfully parsed the line.
 */
static bool	mlx_insert_xpm_entry(xpm_t *xpm, char *line, uint32_t *ctable,
		size_t s)
{
	uint32_t	color;
	size_t		start_offset;
	int32_t		index;

	// NOTE: uintptr because windows likes to complain...
	// Verify the length of the Pixel string by checking backwards for the first
	// occurrence of a space and then check the distance by comparing with cpp.
	if (((uintptr_t)strrchr(line, ' ') - (uintptr_t)line) != (uint64_t)xpm->cpp)
		return (false);
	if (!isspace(line[xpm->cpp]) || line[xpm->cpp + 1] != '#'
		|| !isalnum(line[xpm->cpp + 2]))
		return (false);
	color = 0;
	start_offset = xpm->cpp + 2;
	color |= mlx_parse_hex_channel(line + start_offset) << 24;
	color |= mlx_parse_hex_channel(line + start_offset + 2) << 16;
	color |= mlx_parse_hex_channel(line + start_offset + 4) << 8;
	color |= mlx_parse_hex_channel(line + start_offset + 6);
	index = mlx_fnv_hash(line, xpm->cpp) % s;
	ctable[index] = xpm->mode == 'm' ? mlx_rgba_to_mono(color) : color;
	return (true);
}

/**
 * Retrieves the pixel data line by line and then processes each pixel
 * by hashing the characters and looking it up from the color table.
 * @param xpm The XPM.
 * @param file The filepath to the XPM42 file.
 * @param ctable The color hash table.
 * @param s Size of the hash table.
 * @return True or false depending on if it successfully parsed the line.
 */
static bool	mlx_read_data(xpm_t *xpm, FILE *file, uint32_t *ctable, size_t s)
{
	size_t	line_len;
	char	*line;
	uint8_t	*pixelstart;

	line = NULL;
	for (int64_t y_xpm = 0; y_xpm < xpm->texture.height; y_xpm++)
	{
		if (!mlx_getline(&line, &line_len, file))
			return (free(line), false);
		if (line[line_len - 1] == '\n')
			line_len--;
		if (line_len != xpm->texture.width * xpm->cpp)
			return (free(line), false);
		// NOTE: Copy pixel by pixel as we need to retrieve the hash table.
		for (int64_t x_xpm = 0, x_line = 0; x_xpm < xpm->texture.width; x_xpm++,
			x_line += xpm->cpp)
		{
			pixelstart = &xpm->texture.pixels[(y_xpm * xpm->texture.width
					+ x_xpm) * BPP];
			mlx_draw_pixel(pixelstart, ctable[mlx_fnv_hash(&line[x_line],
					xpm->cpp) % s]);
		}
	}
	free(line);
	return (true);
}

/**
 * For quick lookups we basically create a stack allocated lookup
 * table with every ascii character in it. This should help avoid a O(n)
 * case and give us a O(1) for very fast look ups.
 * Downside is we still need to iterate over each pixel to solve its color.
 * So I hope this makes it at least a bit faster.
 * TODO: This buffer might be way to big! Do actual collision checks,
 * for now just straight up raw dog this.
 */
static bool	mlx_read_table(xpm_t *xpm, FILE *file)
{
	char		*line;
	size_t		line_len;
	uint32_t	ctable[UINT16_MAX] = {0};

	line = NULL;
	for (int32_t i = 0; i < xpm->color_count; i++)
	{
		if (!mlx_getline(&line, &line_len, file))
			return (free(line), false);
		if (!mlx_insert_xpm_entry(xpm, line, ctable, (sizeof(ctable) / BPP)))
			return (free(line), false);
	}
	free(line);
	return (mlx_read_data(xpm, file, ctable, (sizeof(ctable) / BPP)));
}

/**
 * Reads the XPM42 file header which usually consists of a
 * file type declaration of "!XPM42" followed by the next line
 * containing image information such as width, height, unique color
 * count and finally the color mode. Which is either c for Color or
 * m for Monochrome.
 */
static bool	mlx_read_xpm_header(xpm_t *xpm, FILE *file)
{
	int32_t	flagc;
	char	buffer[64] = {0};

	// Check file type dec...
	if (!fgets(buffer, sizeof(buffer), file))
		return (false);
	if (strncmp(buffer, "!XPM42\n", sizeof(buffer)) != 0)
		return (false);
	// Get header info ...
	if (!fgets(buffer, sizeof(buffer), file))
		return (false);
	flagc = sscanf(buffer, "%i %i %i %i %c\n", &xpm->texture.width,
			&xpm->texture.height, &xpm->color_count, &xpm->cpp, &xpm->mode);
	if (flagc < 4 || xpm->texture.width > INT16_MAX
		|| xpm->texture.height > INT16_MAX || !(xpm->mode == 'c'
			|| xpm->mode == 'm') || xpm->cpp > 10)
		return (false);
	xpm->texture.bytes_per_pixel = BPP;
	xpm->texture.pixels = calloc(xpm->texture.width * xpm->texture.height,
			sizeof(int32_t));
	return (xpm->texture.pixels != NULL ? mlx_read_table(xpm, file) : false);
}

*/
/**
 * Carga una textura XPM42 desde la ruta de archivo indicada.
 * @param[in] path La ruta de archivo a la textura XPM.
 * @returns La estructura de la textura XPM que contiene su información.
 */

xpm_t	*mlx_load_xpm42(const char *path)
{
	FILE	*file;
	xpm_t	*xpm;

	xpm = NULL;
	MLX_NONNULL(path);
	if (!strstr(path, ".xpm42"))
		return ((void *)mlx_error(MLX_INVEXT));
	if (!(file = fopen(path, "r")))
		return ((void *)mlx_error(MLX_INVFILE));
	if (!(xpm = calloc(1, sizeof(xpm_t))))
		return ((void *)mlx_error(MLX_MEMFAIL));
	if (!mlx_read_xpm_header(xpm, file))
	{
		mlx_freen(2, xpm->texture.pixels, xpm);
		mlx_error(MLX_INVXPM);
		xpm = NULL;
	}
	fclose(file);
	return (xpm);
}
/**
* Elimina una textura XPM42 liberando sus datos asignados.
* Esto no eliminará ningún XPM ya dibujado, simplemente
* elimina el buffer XPM.
* @param[in] xpm La textura xpm que se eliminará.
*/

void	mlx_delete_xpm42(xpm_t *xpm)
{
	MLX_NONNULL(xpm);
	free(xpm->texture.pixels);
	free(xpm);
}