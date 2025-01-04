# Basics

Antes de empezar, lea la [página de índice](./index.md).
Comenzar con MLX42 es muy sencillo. Aquí haremos un programa simple que usará un makefile y compilará
MLX42.

## Makefile Example

Si tiene curiosidad de como configurar un makefile con MLX42 aquí tiene un ejemplo de Makefile de un proyecto.
Use esto como guía de como compilar MLX42 y usarlo en su aplicación.

En primer lugar necesitamos un makefile que pueda compilar nuestro programa, a continuación puedes ver un makefile de ejemplo:

```makefile
NAME	:= Game
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX	:= ./lib/MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS	:= $(shell find ./src -iname "*.c")
OBJS	:= ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
```

## Main

A continuación se muestra un simple principal en el inicio de una ventana. MLX42 tiene varias características agradables que le permiten predefinir cómo debe comportarse durante el tiempo de ejecución como `MLX_HEADLESS` ejecutándolo sin abrir una ventana o `MLX_STRETCH_IMAGE` que estira el contenido de la ventana con el tamaño de la ventana.

La estructura exacta `mlx_init()` es básicamente un manejador que almacena información importante sobre la ventana.
relativa a la ventana y tiene el siguiente aspecto:

```c
/**
 * Main MLX handle, carries important data in regards to the program.
 * @param window The window itself.
 * @param context Abstracted opengl data.
 * @param width The width of the window.
 * @param height The height of the window.
 * @param delta_time The time difference between the previous frame and the current frame.
 */
typedef struct mlx
{
	void*		window;
	void*		context;
	int32_t		width;
	int32_t		height;
	double		delta_time;
}	mlx_t;
```

Entre las inicializaciones se puede hacer todo lo necesario, como dibujar la imagen o abrir archivos.
Una vez que se alcanza `mlx_loop()` el programa permanece abierto hasta que se solicita el cierre de alguna manera, por ejemplo: cerrando la ventana.

Como queremos que los programas sean interactivos y hagan cosas es muy útil engancharse al proceso de bucle de `mlx_loop()`.
Para conseguir esto usamos [hooks](./Hooks.md).

NOTA: Compile MLX42 con DEBUG=1 para ver aserciones y añadir banderas de depuración. ¡Esto puede ayudarle a encontrar errores críticos durante el desarrollo!

```c
// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/MLX42.h"
#define WIDTH 256
#define HEIGHT 256

// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{

	// MLX permite definir su comportamiento básico antes del arranque.
	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Crear y mostrar la imagen.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	// Incluso después de que la imagen se está mostrando, todavía podemos modificar el buffer.
	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

	// Registra un hook y pasa mlx como param opcional.
	// NOTA: ¡Haga esto antes de llamar a mlx_loop!
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
```