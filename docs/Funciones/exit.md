```C
#include "MLX42/MLX42_Int.h"

//= Private =//

static void mlx_free_image(void* content)
{
	mlx_image_t* img = content;

	mlx_freen(4, img->context, img->pixels, img->instances, img);
}

//= Public =//
/**
 * Notifica a MLX que debe dejar de renderizar y salir del bucle principal.
 * Esto no es lo mismo que terminar, esto simplemente le dice a MLX que cierre la ventana.
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_close_window(mlx_t* mlx)
{
	MLX_NONNULL(mlx);
	glfwSetWindowShouldClose(mlx->window, true);
}

/**
 * Termina MLX y limpia cualquiera de sus recursos usados.
 * El uso posterior de cualquier función que requiera mlx se considerará un comportamiento indefinido.
 * se considerará comportamiento indefinido, cuidado con los segfaults.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_terminate(mlx_t* mlx)
{
	MLX_NONNULL(mlx);

	mlx_ctx_t *const mlxctx = mlx->context;

	glUseProgram(0);
	glLinkProgram(mlxctx->shaderprogram);
	glDeleteProgram(mlxctx->shaderprogram);
	glfwTerminate();
	mlx_lstclear((mlx_list_t**)(&mlxctx->hooks), &free);
	mlx_lstclear((mlx_list_t**)(&mlxctx->render_queue), &free);
	mlx_lstclear((mlx_list_t**)(&mlxctx->images), &mlx_free_image);
	mlx_freen(2, mlxctx, mlx);
}
