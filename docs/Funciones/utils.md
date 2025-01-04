```C

#include "MLX42/MLX42_Int.h"

//= Private =//

bool mlx_equal_image(void* lstcontent, void* value)
{
	const mlx_image_t* lcontent = lstcontent;
	const mlx_image_t* lvalue = value;

	return (lcontent == lvalue);
}

bool mlx_equal_inst(void* lstcontent, void* value)
{
	const draw_queue_t* lcontent = lstcontent;
	const mlx_image_t* lvalue = value;

	return (lcontent->image == lvalue);
}
#include "MLX42/MLX42_Int.h"

//= Private =//

// English description of the error codes.
static const char* mlx_errors[MLX_ERRMAX] = {
	"No Errors",
	"File has invalid extension",
	"Failed to open the file",
	"PNG file is invalid or corrupted",
	"XPM42 file is invalid or corrupted",
	"The specified X or Y positions are out of bounds",
	"The specified Width or Height dimensions are out of bounds",
	"The provided image is invalid, might indicate mismanagement of images",
	"Failed to compile the vertex shader.",
	"Failed to compile the fragment shader.",
	"Failed to compile the shaders.",
	"Failed to allocate memory",
	"Failed to initialize GLAD",
	"Failed to initialize GLFW",
	"Failed to create window",
	"String is too big to be drawn",
};

/**
 * Funciones para establecer el número de error, simplemente por comodidad.
 * 
 * @param val EL valor de error.
 * @return Siempre falso
 */
bool mlx_error(mlx_errno_t val)
{
	mlx_errno = val;
#ifndef NDEBUG
	fprintf(stderr, "MLX42: %s", mlx_strerror(mlx_errno));
#endif
	return (false);
}
/**
 * Obtiene la descripción en inglés del código de error.
 * @param[in] val El código de error.
 * @return La cadena de error que describe el código de error.
 */

//= Public =//

const char* mlx_strerror(mlx_errno_t val)
{
	MLX_ASSERT(val >= 0, "Index must be positive");
	MLX_ASSERT(val < MLX_ERRMAX, "Index out of bounds");

	return (mlx_errors[val]);
}

//= mlx_list =//

int32_t mlx_lstsize(mlx_list_t* lst)
{
	int32_t	i;

	for (i = 0; lst != NULL; i++)
		lst = lst->next;
	return (i);
}

static void mlx_lstdelone(mlx_list_t* lst, void (*del)(void *))
{
	if (del != NULL)
		del(lst->content);
	free(lst);
}

void mlx_lstclear(mlx_list_t** lst, void (*del)(void*))
{
	mlx_list_t* next_lst;

	while (*lst != NULL)
	{
		next_lst = (*lst)->next;
		mlx_lstdelone(*lst, del);
		*lst = next_lst;
	}
}

mlx_list_t* mlx_lstnew(void* content)
{
	mlx_list_t* out = NULL;

	if ((out = malloc(sizeof(mlx_list_t))))
	{
		out->content = content;
		out->next = NULL;
		out->prev = NULL;
	}
	return (out);
}

mlx_list_t* mlx_lstlast(mlx_list_t* lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void mlx_lstadd_back(mlx_list_t** lst, mlx_list_t* new)
{
	if (!lst || !new)
		return;
	if (!*lst)
		*lst = new;
	else
	{
		mlx_list_t* temp = mlx_lstlast(*lst);
		new->prev = temp;
		temp->next = new;
	}
}

void mlx_lstadd_front(mlx_list_t** lst, mlx_list_t* new)
{
	if (!lst || !new)
		return;
	if ((*lst) != NULL)
		(*lst)->prev = new;
	new->next = *lst;
	new->prev = NULL;
	*lst = new;
}

/**
 * Elimina el contenido especificado de la lista, si se encuentra.
 * También corrige cualquier reenlace que pueda ser necesario.
 * @param[in] lst La lista
 * @param[in] comp Función para comprobar si el contenido y el valor son iguales.
 * @returns El elemento eliminado, limpie como desee.
 */
mlx_list_t* mlx_lstremove(mlx_list_t** lst, void* value, bool (*comp)(void*, void*))
{
	mlx_list_t* lstcpy = *lst;

	while (lstcpy && !comp(lstcpy->content, value))
		lstcpy = lstcpy->next;
	if (lstcpy == NULL)
		return (NULL);
	if (lstcpy == *lst)
		*lst = lstcpy->next;
	if (lstcpy->next != NULL)
		lstcpy->next->prev = lstcpy->prev;
	if (lstcpy->prev != NULL)
		lstcpy->prev->next = lstcpy->next;
	return (lstcpy);
}

// Recupera el valor Z de la cola.
static int32_t mlx_getzdata(mlx_list_t* entry)
{
	const draw_queue_t* queue = entry->content;

	return (queue->image->instances[queue->instanceid].z);
}

// Vuelve a introducir la entrada en el encabezamiento ordenado.
static void mlx_insertsort(mlx_list_t** head, mlx_list_t* new)
{
	mlx_list_t* current;

	if (*head == NULL)
		*head = new;
	else if (mlx_getzdata(*head) >= mlx_getzdata(new))
	{
		new->next = *head;
		new->next->prev = new;
		*head = new;
	}
	else
	{
		current = *head;

		// Find insertion location.
		while (current->next != NULL && mlx_getzdata(current->next) < mlx_getzdata(new))
			current = current->next;
		new->next = current->next;

		// Insert at the end
		if (current->next != NULL)
			new->next->prev = new;
		current->next = new;
		new->prev = current;
	}
}

/**
 * Algoritmo de ordenación para ordenar la cola de renderizado / lista doblemente enlazada.
 * Necesitamos hacer esto para arreglar la transparencia.
 *
 * @param lst La cola de renderizado.
 */
void mlx_sort_renderqueue(mlx_list_t** lst)
{
	mlx_list_t* sorted = NULL;
	mlx_list_t* lstcpy = *lst;

	while (lstcpy != NULL)
	{
		mlx_list_t* next = lstcpy->next;

		// Separate entry out of list and insert it back but sorted.
		lstcpy->prev = lstcpy->next = NULL;
		mlx_insertsort(&sorted, lstcpy);
		lstcpy = next;
	}
	*lst = sorted;
}
//= mlx_utils =//

#include «MLX42/MLX42_Int.h»

//= Privado =//

/**
 * Función para leer un fichero línea a línea, reutilizando el mismo puntero de salida.
 * Dado que se reutiliza el mismo puntero de salida, sólo debe ser liberado una vez, ya sea en caso de éxito o de fracaso.
 * Esta función es similar a getline.
 * Getline no puede usarse directamente ya que no es estándar y por lo tanto no está disponible en todas las plataformas.
 * @param out Puntero para almacenar la cadena de salida.
 * @param out_size Puntero para almacenar la longitud de la cadena de salida.
 * @param file Flujo de ficheros del que leer.
 * @return True si se leyó la línea, false si se alcanzó EOF o se produjo un error.
 */

bool mlx_getline(char** out, size_t* out_size, FILE* file)
{
	MLX_NONNULL(out);
	MLX_NONNULL(out_size);
	MLX_NONNULL(file);

	size_t size = 0;
	char* temp = NULL;
	static char BUFF[GETLINE_BUFF + 1]; // Add space for '\0'

	if (*out) *out[0] = '\0';

	while (fgets(BUFF, sizeof(BUFF), file))
	{
		size += strlen(BUFF);
		if (!(temp = realloc(*out, sizeof(char) * size + 1)))
			return (false);
		if (*out == NULL)
			memset(temp, '\0', size);
		temp[size] = '\0';

		*out = temp;
		*out_size = size;

		strncat(*out, BUFF, size);
		if (strrchr(BUFF, '\n'))
			return (true);
		memset(BUFF, '\0', sizeof(BUFF));
	}
	return (size);
}
/**
 * String hashing algorithm using FNV-1a.
 * Source: https://bit.ly/3JcRGHa
 * 
 * @param str The string to hash
 * @param len The length of the string.
 * @return The hashed output.
 */
uint64_t mlx_fnv_hash(char* str, size_t len)
{
	const uint64_t fnv_prime = 0x100000001b3;
	const uint64_t fnv_offset = 0xcbf29ce484222325;
	uint64_t hash = fnv_offset;

	for (size_t i = 0; i < len; i++)
	{
		hash ^= str[i];
		hash *= fnv_prime;
	}
	return (hash);
}
/**
 * Utility function that lets you free x amount of pointers.
 * 
 * @param count The amount of args provided.
 * @param ... Any form of pointer.
 * @return False, this is simply for convenience when necessary.
 */
bool mlx_freen(int32_t count, ...)
{
	va_list	args;

	va_start(args, count);
	for (int32_t i = 0; i < count; i++)
		free(va_arg(args, void*));
	va_end(args);
	return (false);
}

/**
 * Converts an RGBA value to a monochrome/grayscale value.
 * It does so using specific weights for each channel.
 * 
 * @see https://goodcalculators.com/rgb-to-grayscale-conversion-calculator/
 * 
 * @param color The input RGBA value.
 * @return The rgba value converted to a grayscale color.
 */
uint32_t mlx_rgba_to_mono(uint32_t color)
{
	const uint8_t r = 0.299f * ((color >> 24) & 0xFF);
	const uint8_t g = 0.587f * ((color >> 16) & 0xFF);
	const uint8_t b = 0.114f * ((color >> 8) & 0xFF);
	const uint8_t y = r + g + b;

	return (y << 24 | y << 16 | y << 8 | (color & 0xFF));
}
//= Public =//
/**
 * Obtiene el tiempo transcurrido desde que MLX fue inicializado.
 * @return La cantidad de tiempo transcurrido en segundos.
 */
double mlx_get_time(void)
{
	return (glfwGetTime());
}
/**
 * Esta función trae la ventana especificada al frente y establece el foco de entrada.
 * No use esta función para robar el foco de otras aplicaciones a menos que esté seguro de que es lo que el usuario quiere.
 * que esté seguro de que eso es lo que quiere el usuario. Robar el foco puede ser
 * extremadamente perjudicial.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_focus(mlx_t* mlx)
{
	MLX_NONNULL(mlx);

	glfwFocusWindow(mlx->window);
}
