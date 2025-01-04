# Imágenes

Las imágenes son como un lienzo para una pintura, 
se utilizan para mostrar información de píxeles en la ventana 
y trabajar con algo llamado instancias.

Las instancias: son copias del lienzo 
y te permiten mostrar una imagen varias veces a lo largo de la ventana. 
La idea detrás de esto es que ya tienes la información de píxeles en la memoria 
y puedes crear duplicados en todas partes.

Cada instancia tiene un parámetro X, Y y Z para determinar su posición y profundidad.
Un cambio en el buffer de la imagen 
resulta en un cambio para todas las instancias mostradas actualmente.

Una imagen por sí sola es muy sencilla:
```c
/**
 * Una imagen con un buffer individual que puede ser renderizada.
 * Se puede modificar cualquier valor excepto la anchura/altura y el contexto.
 * 
 * @param width El ancho de la imagen.
 * @param height La altura de la imagen.
 * @param pixels Los datos literales de los píxeles.
 * @param instances Una instancia lleva los datos de localización X, Y, Z.
 * @param count Número de elementos de la matriz de instancias.
 * @param enabled Si es true la imagen se dibuja en la pantalla, si no, no.
 * @param context Datos OpenGL abstractos.
 */
typedef struct mlx_image
{
	const uint32_t anchura;
	const uint32_t altura;
	uint8_t* píxeles
	mlx_instance_t* instances;
	int32_t count;
	bool enabled;
	void* context;
	mlx_image_t;
}
```

Para mostrar la imagen: 
todo lo que se necesita es llamar a la función `mlx_image_to_window` 
para crear una nueva copia/instancia:

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#include "MLX42/MLX42.h"
#define WIDTH 5120
#define HEIGHT 2880

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

	// Crear una nueva imagen
	mlx_image_t* img = mlx_new_image(mlx, 512, 512);
	if (!img)
		error();

	// Poner cada pixel en blanco
	memset(img->pixels, 255, img->width * img->height * sizeof(int32_t));

	// Mostrar una instancia de la imagen
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();

	mlx_loop(mlx);

	// Opcional, terminar limpiará cualquier sobrante, esto es sólo para demostrar
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
