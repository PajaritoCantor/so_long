//=mlx_images=//
```C
//= Public =//
/**
* Establece el valor del eje Z/profundidad de una instancia.
* NOTA: Ten en cuenta que las imágenes que están en la misma capa Z se cortan entre sí.
* Por lo tanto, si ya no ves tu imagen, asegúrate de que no esté en conflicto por estar
* en la misma capa que otra imagen.
* @param[in] instance La instancia en la que se cambiará la profundidad.
* @param[in] zdepth El nuevo valor de profundidad.
*/
void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth)
{
	MLX_NONNULL(instance);

	if (instance->z == zdepth)
		return;
	instance->z = zdepth;

	/**
	 * NOTE: The reason why we don't sort directly is that
	 * the user might call this function multiple times in a row and we don't
	 * want to sort for every change. Pre-loop wise that is.
	 */
	sort_queue = true;
}
/**
* Dibuja una nueva instancia de una imagen, que luego compartirá el mismo
* búfer de píxeles que la imagen.
* NOTA: Tenga en cuenta que la matriz de instancias se reasigna, intente
* almacenar el valor de retorno en la instancia.
* ¡NO el puntero! ¡Se volverá inválido!
* ADVERTENCIA: Intente mostrar la menor cantidad posible de imágenes en la ventana,
* ¡dibujar demasiadas imágenes provocará una pérdida de rendimiento!
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] img La imagen que se dibujará en la pantalla.
* @param[in] x La posición X.
* @param[in] y La posición Y.
* @return Índice a la instancia, o -1 en caso de error.
*/
int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(img);

	// Allocate buffers...
	img->count++;
	bool did_realloc;
	mlx_instance_t* instances = mlx_grow_instances(img, &did_realloc);
	draw_queue_t* queue = calloc(1, sizeof(draw_queue_t));
	if (!instances || !queue)
	{
		if (did_realloc)
			free(instances);
		return (free(queue), mlx_error(MLX_MEMFAIL), -1);
	}

	// Set data...
	queue->image = img;
	int32_t index = queue->instanceid = img->count - 1;
	img->instances = instances;
	img->instances[index].x = x;
	img->instances[index].y = y;

	// NOTE: We keep updating the Z for the convenience of the user.
	// Always update Z depth to prevent overlapping images by default.
	img->instances[index].z = ((mlx_ctx_t*)mlx->context)->zdepth++;
	img->instances[index].enabled = true;

	// Add draw call...
	sort_queue = true;
	mlx_list_t* templst;
	if ((templst = mlx_lstnew(queue)))
	{
		mlx_lstadd_front(&((mlx_ctx_t*)mlx->context)->render_queue, templst);
		return (index);
	}
	return (mlx_freen(2, instances, queue), mlx_error(MLX_MEMFAIL), -1);
}
/**
* Crea y asigna un nuevo buffer de imagen.
*
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] width El ancho deseado de la imagen.
* @param[in] height La altura deseada de la imagen.
* @return Puntero al buffer de imagen, si no se pudo asignar, entonces NULL.
*/
mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height)
{
	MLX_NONNULL(mlx);

	if (!width || !height || width > INT16_MAX || height > INT16_MAX)
		return ((void*)mlx_error(MLX_INVDIM));

	const mlx_ctx_t* mlxctx = mlx->context;
	mlx_image_t* newimg = calloc(1, sizeof(mlx_image_t));
	mlx_image_ctx_t* newctx = calloc(1, sizeof(mlx_image_ctx_t));
	if (!newimg || !newctx)
	{
		mlx_freen(2, newimg, newctx);
		return ((void *)mlx_error(MLX_MEMFAIL));
	}
	newimg->enabled = true;
	newimg->context = newctx;
	(*(uint32_t*)&newimg->width) = width;
	(*(uint32_t*)&newimg->height) = height;
	if (!(newimg->pixels = calloc(width * height, sizeof(int32_t))))
	{
		mlx_freen(2, newimg, newctx);
		return ((void *)mlx_error(MLX_MEMFAIL));
	}

	mlx_list_t* newentry;
	if (!(newentry = mlx_lstnew(newimg)))
	{
		mlx_freen(3, newimg->pixels, newimg->context, newimg);
		return ((void *)mlx_error(MLX_MEMFAIL));
	}

	// Generate OpenGL texture
	glGenTextures(1, &newctx->texture);
	glBindTexture(GL_TEXTURE_2D, newctx->texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	mlx_lstadd_front((mlx_list_t**)(&mlxctx->images), newentry);
	return (newimg);
}
/**
* Eliminar una imagen la quitará de la cola de renderizado, así como todas y cada una de las
* instancias que pueda tener. Además, como medida adicional, establece todos los
* datos en NULL.
* Si simplemente desea detener el renderizado de una imagen sin desasignarla
* establezca el booleano 'habilitado' en la estructura de la imagen.
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] image La imagen que se eliminará.
*/

void mlx_delete_image(mlx_t* mlx, mlx_image_t* image)
{
	MLX_NONNULL(mlx);
	MLX_NONNULL(image);

	mlx_ctx_t* mlxctx = mlx->context;

	// Delete all instances in the render queue
	mlx_list_t* quelst;
	while ((quelst = mlx_lstremove(&mlxctx->render_queue, image, &mlx_equal_inst)))
		mlx_freen(2, quelst->content, quelst);

	mlx_list_t* imglst;
	if ((imglst = mlx_lstremove(&mlxctx->images, image, &mlx_equal_image)))
	{
		glDeleteTextures(1, &((mlx_image_ctx_t*)image->context)->texture);
		mlx_freen(5, image->pixels, image->instances, image->context, imglst, image);
	}
}
/**
* Le permite cambiar el tamaño de una imagen, se asigna un nuevo búfer de píxeles
* para ajustar y los datos anteriores se escalan para ajustarse al nuevo tamaño.
* @param[in] img La imagen a cambiar de tamaño.
* @param[in] nwidth El nuevo ancho.
* @param[in] nheight La nueva altura.
* @return True si se cambió el tamaño de la imagen o false en caso de error.
*/
bool mlx_resize_image(mlx_image_t* img, uint32_t nwidth, uint32_t nheight)
{
	MLX_NONNULL(img);

	if (!nwidth || !nheight || nwidth > INT16_MAX || nheight > INT16_MAX)
		return (mlx_error(MLX_INVDIM));
	if (nwidth != img->width || nheight != img->height)
	{
		uint32_t* origin = (uint32_t*)img->pixels;
		float wstep = (float)img->width / nwidth;
		float hstep = (float)img->height / nheight;

		uint8_t* tempbuff = calloc(nwidth * nheight, BPP);
		if (!tempbuff)
			return (mlx_error(MLX_MEMFAIL));
		img->pixels = tempbuff;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, nwidth, nheight, 0, GL_RGBA, GL_UNSIGNED_BYTE, img->pixels);

		uint32_t* destin = (uint32_t*)img->pixels;
		for (uint32_t j = 0; j < nheight; j++)
			for (uint32_t i = 0; i < nwidth; i++)
				destin[j * nwidth + i] = origin[(uint32_t)(j * hstep) * img->width + (uint32_t)(i * wstep)];
		(*(uint32_t*)&img->width) = nwidth;
		(*(uint32_t*)&img->height) = nheight;
		free(origin);
	}
	return (true);
}
