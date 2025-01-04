# XPM42

XPM42 es un formato de archivo personalizado hecho para MLX42 
para proporcionar un formato de archivo de imagen fácil de usar y entender 
para aprender cómo almacenar imágenes. 
El formato está basado en el formato actual [XPM3](https://en.wikipedia.org/wiki/X_PixMap).

Un archivo XPM básicamente almacena una tabla de búsqueda en su interior 
para obtener qué carácter corresponde a qué color. 
Además, en la cabecera hay un recuento de caracteres por píxel, 
esto se debe a la limitación de la cantidad de caracteres. 
Cada 'Pixel' en los datos XPM puede ser representado por múltiples caracteres.

Por ejemplo `*.` se vería como un único píxel 
si el recuento de caracteres por píxel fuera 2.

## Disposición

El formato del fichero es el siguiente

```
!XPM42 <- Declaración de fichero
16 7 2 1 c <- Anchura | Altura | Recuento de colores | Caracteres por píxel | Modo (C: Color o M: Monocromo).
* #FF0000FF <- Entrada siempre: <Char> <Space> <Hexadecimal> Los colores DEBEN tener los cuatro canales (RGBA)
. #00000000
**..*...........  <- Datos de píxel literales
*.*.*...........
**..*..**.**..**
*.*.*.*.*.*..*.*
**..*..**.*...**
...............*
.............**.
```

## Funcionamiento interno

Leer un XPM42 hace un montón de cosas pero en esencia: 
lee la cabecera del archivo e inserta cada entrada de color en una tabla hash 
para búsquedas rápidas del valor de color, el hash usado es FNV-1a. 
¿Por qué? porque es un hash fácil de usar y también mi favorito. 
Después de leer la cabecera e insertar los valores de color en la tabla, 
se lee cada línea, se procesa cada carácter y se inserta en el búfer de píxeles del XPM. 
No hay comprobación de colisiones en la tabla de búsqueda, 
por lo que puede haber artefactos.

## Herramientas

En la raíz del repositorio hay un directorio de herramientas 
en el que un script python puede convertir un fichero XPM3 existente a XPM42.
Utilice este script si desea utilizar el formato de archivo XPM42.

## Example

```C
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
	// Inicia mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();

	// Trata de cargar el archivo
	xpm_t* xpm = mlx_load_xpm42("./temp/42.xpm42");
	if (!xpm)
		error();
	
	// Convierte la textura a una imagen visualizable
	mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();

	// Muestra la imagen
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);

	// Opcional, terminar limpiará cualquier sobrante, esto es sólo para demostrar.
	mlx_delete_image(mlx, img);
	mlx_delete_xpm42(xpm);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}