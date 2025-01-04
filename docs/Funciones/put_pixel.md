```C
#include "MLX42/MLX42_Int.h"

// BUG: Linux may experience a red hue instead due to endianness
void mlx_draw_pixel(uint8_t* pixel, uint32_t color)
{
	*(pixel++) = (uint8_t)(color >> 24);
	*(pixel++) = (uint8_t)(color >> 16);
	*(pixel++) = (uint8_t)(color >> 8);
	*(pixel++) = (uint8_t)(color & 0xFF);
}

//= Public =//
/**
* Establece/pone un píxel en una imagen.
* NOTA: Se considera un comportamiento indefinido cuando se coloca un píxel
* más allá de los límites de una imagen.
* @param[in] image El identificador de la instancia MLX.
* @param[in] x La posición de la coordenada X.
* @param[in] y La posición de la coordenada Y.
* @param[in] color El valor de color que se colocará.
*/
void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color)
{
	MLX_NONNULL(image);
	MLX_ASSERT(x < image->width, "Pixel is out of bounds");
	MLX_ASSERT(y < image->height, "Pixel is out of bounds");

	uint8_t* pixelstart = &image->pixels[(y * image->width + x) * BPP];
	mlx_draw_pixel(pixelstart, color);
}