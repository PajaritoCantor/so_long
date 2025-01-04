```C
//= Private =//

/**
 * Recalculate the view projection matrix, used by images for screen pos
 * Reference: https://bit.ly/3KuHOu1 (Matrix View Projection)
 */
void mlx_update_matrix(const mlx_t* mlx)
{
	const mlx_ctx_t* mlxctx = mlx->context;
	const float depth = mlxctx->zdepth;

	/**
	 * In case the setting to stretch the image is set, we maintain the width and height but not
	 * the depth.
	 */
	const float width = mlx_settings[MLX_STRETCH_IMAGE] ? mlxctx->initialWidth : mlx->width;
	const float height = mlx_settings[MLX_STRETCH_IMAGE] ? mlxctx->initialHeight : mlx->height;

	const float matrix[16] = {
		2.f / width, 0, 0, 0,
		0, 2.f / -(height), 0, 0,
		0, 0, -2.f / (depth - -depth), 0,
		-1, -(height / -height),
		-((depth + -depth) / (depth - -depth)), 1
	};

	glUniformMatrix4fv(glGetUniformLocation(mlxctx->shaderprogram, "ProjMatrix"), 1, GL_FALSE, matrix);
}

static void mlx_resize_callback(GLFWwindow* window, int32_t width, int32_t height)
{
	const mlx_t* mlx = glfwGetWindowUserPointer(window);
	const mlx_ctx_t* mlxctx = mlx->context;

	if (mlxctx->resize_hook.func)
		mlxctx->resize_hook.func(width, height, mlxctx->resize_hook.param);
}

static void mlx_close_callback(GLFWwindow* window)
{
	const mlx_t* mlx = glfwGetWindowUserPointer(window);
	const mlx_close_t close_hook = ((mlx_ctx_t*)mlx->context)->close_hook;

	close_hook.func(close_hook.param);
}

//= Public =//
/**
* Esta función establece el callback de cierre, que se llama en el intento de cerrar
* el dispositivo de ventana, como un widget de ventana de cierre utilizado en la barra de ventanas.
* @param[in] mlx El manejador de instancia MLX.
* @param[in] func La función de llamada de retorno de cierre.
* @param[in] param Parámetro adicional opcional.
*/
void mlx_close_hook(mlx_t* mlx, mlx_closefunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* mlxctx = mlx->context;
	mlxctx->close_hook.func = func;
	mlxctx->close_hook.param = param;
	glfwSetWindowCloseCallback(mlx->window, mlx_close_callback);
}
/**
 * Esta función establece el callback de redimensionamiento, que es llamado cuando la ventana es
 * redimensionada
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] func La función de redimensionamiento.
 * @param[in] param Parámetro adicional opcional.
 */
void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(func);

	mlx_ctx_t* mlxctx = mlx->context;
	mlxctx->resize_hook.func = func;
	mlxctx->resize_hook.param = param;
	glfwSetWindowSizeCallback(mlx->window, mlx_resize_callback);
}
/**
 * Permite establecer una imagen personalizada como icono del programa.
 * NOTA: En MacOS esta función no hace nada, debes usar el icono de bundles para establecer el icono de la barra dock.
 * @ver: https://9to5mac.com/2021/11/08/change-mac-icons/
 * @ver: https://github.com/glfw/glfw/issues/2041
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] image La imagen a usar como icono.
 */
void mlx_set_icon(mlx_t* mlx, mlx_texture_t* image)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(image);

	const GLFWimage icon = {
		.width = image->width,
		.height = image->height,
		.pixels = image->pixels
	};

	glfwSetWindowIcon(mlx->window, 1, &icon);
}
/**
 * Establece la posición de la ventana.
 * No utilice esta función para mover una ventana ya visible a menos que tenga buenas razones para hacerlo, ya que confundirá y molestará al usuario.
 * tenga muy buenas razones para hacerlo, ya que confundirá y molestará al usuario.
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] xpos La posición x.
 * @param[in] ypos La posición y.
 */
void mlx_set_window_pos(mlx_t* mlx, int32_t xpos, int32_t ypos)
{
	MLX_NONNULL(mlx);

	glfwSetWindowPos(mlx->window, xpos, ypos);
}
/**
* Obtiene la posición de la ventana.
* @param[in] mlx El manejador de la instancia MLX.
* @param[out] xpos La posición x.
* @param[out] ypos La posición y.
*/
void mlx_get_window_pos(mlx_t* mlx, int32_t* xpos, int32_t* ypos)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(xpos);
	MLX_NONNULL(ypos);

	glfwGetWindowPos(mlx->window, xpos, ypos);
}
/**
 * Cambia el tamaño de la ventana a los nuevos valores especificados.
 * Use esto para actualizar los valores de ancho y alto de la ventana en el manejador mlx.
 * 
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] new_width La nueva anchura deseada.
 * @param[in] new_height La nueva altura deseada.
 */
void mlx_set_window_size(mlx_t* mlx, int32_t new_width, int32_t new_height)
{
	MLX_NONNULL(mlx);

	mlx->width = new_width;
	mlx->height = new_height;
	glfwSetWindowSize(mlx->window, new_width, new_height);
}
/**
 * Establece los límites de tamaño de la ventana especificada.
 * Forzará a la ventana a no ser redimensionable más allá o por debajo de los valores dados.
 * 
 * Pase -1 para ningún límite a cualquiera de los parámetros min/max para ignorar ese límite.
 * Por ejemplo, si desea un tamaño de ventana mínimo, pero el tamaño máximo de la ventana puede ser cualquiera.
 *
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] min_w La anchura mínima de la ventana.
 * @param[in] max_w Ancho máximo de la ventana.
 * @param[in] min_h Altura mínima de la ventana.
 * @param[in] max_h Altura máxima de la ventana.
 */
void mlx_set_window_limit(mlx_t* mlx, int32_t min_w, int32_t min_h, int32_t max_w, int32_t max_h)
{
	MLX_NONNULL(mlx);

	glfwSetWindowSizeLimits(mlx->window, min_w, min_h, max_w, max_h);
}
/**
 * Establece el título de la ventana.
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] title El título de la ventana.
 */
void mlx_set_window_title(mlx_t* mlx, const char* title)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(title);

	glfwSetWindowTitle(mlx->window, title);
}