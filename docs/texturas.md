Texturas

Las texturas son imágenes cargadas en disco que se almacenan en memoria 
y contienen un búfer de datos de píxeles junto con información sobre la imagen, 
como la anchura, la altura y los bytes por píxel.

Las texturas por sí solas no se muestran en pantalla, 
sino que tienen que mostrarse utilizando [Images](./Images.md).
Para ello se puede utilizar la función `mlx_texture_to_image` 
que crea una imagen lo suficientemente grande como para almacenar la 
textura que luego se puede mostrar.

## Texturas vs Imágenes

Al principio puede haber un poco de confusión entre lo que es una imagen y una textura.

Texturas:
* Pueden interpretarse como la «paleta de colores» de un pintor.
* Se crean cargando un archivo de imagen DESDE el disco.
* Simplemente contienen la información de píxeles, anchura, altura y bytes por píxel.
* No se muestran directamente en la ventana.

Imágenes:
* Pueden interpretarse como el «lienzo» de un pintor.
* Pueden crearse A PARTIR de una textura o de un buffer vacío.
* Contiene más información que el buffer de imagen, como el número de instancias.
* También contiene datos de píxeles pero son compartidos entre sus instancias, no se cargan del disco sino que se almacenan en memoria.

## Ejemplo

Resumiendo, para mostrar una imagen de sprite en nuestra ventana: 
primero cargaríamos la textura desde disco a nuestra memoria 
y almacenamos la información en un `mlx_texture_t*`. 
Después creamos una nueva `mlx_image_t*`basado en la información dada por la textura 
y entonces podemos mostrar nuestra imagen en la ventana.

```C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42/MLX42.h"
#define WIDTH 512
#define HEIGHT 512

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Iniciar mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
        error();

	// Trata de cargar el archivo
	mlx_texture_t* texture = mlx_load_png("./temp/sus.png");
	if (!texture)
        error();
	
	// Convierte la textura en una imagen visualizable
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
        error();

	// Muestra la imaagen
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop(mlx);

	// Opcional, terminar limpiará cualquier sobrante, esto es sólo para demostrar.
	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}