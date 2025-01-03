TRADUCCIÓN

MLX42 es una librería multiplataforma de gráficos simples y de bajo nivel.
 * escrita en C y utiliza OpenGL y GLFW para su sistema de ventanas y renderizado.
 * 
 * Es una alternativa mucho más actualizada a la miniLibX que ha demostrado ser frágil, sin mantenimiento, obsoleta y simplemente dolorosamente mala para trabajar. También la calidad de su código es dudosa.
 * 
 * Algunos structs contienen void* potenciales que deben ser ignorados ya que simplemente representan puntos de abstracción a la cabecera interna oculta.
 * Esta abstracción es crucial ya que el objetivo de esta librería es ocultar todas las campanas y silbatos del «motor». La mayoria de los usuarios no necesitan el funcionamiento interno (shaders, vertex buffer, ...). 

Traducción realizada con la versión gratuita del traductor DeepL.com


mlx_init(int32_t width, int32_t heigth, const char *title, bool resize)

Inicializa una nueva instancia MLX42 

Parámetros:
width - El ancho de la ventana
heigth - El alto de la ventana
title - El título de la ventana 
resize - Activar el redimensionamiento de ventanas

/**
 * Modificadores de teclas, como shift, control o alt.
 * Estas teclas son indicadores, lo que significa que puedes combinarlas para detectar
 * combinaciones de teclas como CTRL + ALT así CTRL | ALT.
 * 
 * @param SHIFT La tecla shift.
 * @param CONTROL La tecla de control.
 * @param ALT La tecla alt.
 * @param SUPERKEY La supertecla como la tecla Windows o Command.
 * @param CAPSLOCK La tecla capslock.
 * @param NUMLOCK La tecla numlock.
 */
ypedef enum modificador_clave
{
	MLX_SHIFT = 0x0001,
	MLX_CONTROL = 0x0002,
	MLX_ALT = 0x0004,
	MLX_SUPERKEY = 0x0008,
	MLX_CAPSLOCK = 0x0010,
	MLX_NUMLOCK = 0x0020,
} modifier_key_t;

/**
 * Los keycodes de los botones del ratón.
 * @param LEFT El botón izquierdo del ratón.
 * @param RIGHT El botón derecho del ratón.
 * @param MIDDLE El botón central del ratón, también conocido como Scrollwheel.
 */
typedef enum mouse_key
{
	MLX_MOUSE_BUTTON_LEFT = 0,
	MLX_MOUSE_BUTTON_RIGHT = 1,
	MLX_MOUSE_BUTTON_MIDDLE = 2,
} mouse_key_t;

/**
 * Varios estados del ratón/cursor.
 * @param NORMAL Cursor simple visible por defecto.
 * @param HIDDEN El cursor no se muestra pero sigue funcionando.
 * @param DISABLED El cursor no se renderiza, ni es funcional.
 */
typedef enum mouse_mode
{
	MLX_MOUSE_NORMAL = 0x00034001,
	MLX_MOUSE_HIDDEN = 0x00034002,
	MLX_MOUSE_DISABLED = 0x00034003,
} mouse_mode_t;

/**
 * Varios cursores que son estándar.
 * @param ARROW El cursor de flecha normal.
 * @param IBEAM La forma del cursor I-beam de entrada de texto.
 * @param CROSSHAIR El cursor en forma de cruz.
 * @param HAND El cursor con forma de mano.
 * @param HRESIZE La forma horizontal de la flecha.
 * @param VRESIZE La forma vertical de la flecha.
 */
typedef enum cursor
{
	MLX_CURSOR_ARROW = 0x00036001,
	MLX_CURSOR_IBEAM = 0x00036002,
	MLX_CURSOR_CROSSHAIR = 0x00036003,
	MLX_CURSOR_HAND = 0x00036004,
	MLX_CURSOR_HRESIZE = 0x00036005,
	MLX_CURSOR_VRESIZE = 0x00036006,
} cursor_t;

/**
 * Todo tipo de códigos de teclado.
 * 
 * KP = Teclado.
 */
/**
 * Objeto base para texturas cargadas en disco.
 * Contiene información básica sobre la textura.
 * 
 * @param width La anchura de la textura.
 * @param height La altura de la textura.
 * @param pixels Los datos literales de los píxeles.
 * @param bytes_per_pixel La cantidad de bytes en un píxel, siempre 4.
 */
 typedef struct mlx_texture
{
	uint32_t	width;
	uint32_t	height;
	uint8_t		bytes_per_pixel;
	uint8_t*	pixels;
}	mlx_texture_t;
/**
 * All sorts of keyboard keycodes.
 * 
 * KP = Keypad.
 */
typedef enum keys
{
	MLX_KEY_SPACE			= 32,
	MLX_KEY_APOSTROPHE		= 39,
	MLX_KEY_COMMA			= 44,
	MLX_KEY_MINUS			= 45,
	MLX_KEY_PERIOD			= 46,
	MLX_KEY_SLASH			= 47,
	MLX_KEY_0				= 48,
	MLX_KEY_1				= 49,
	MLX_KEY_2				= 50,
	MLX_KEY_3				= 51,
	MLX_KEY_4				= 52,
	MLX_KEY_5				= 53,
	MLX_KEY_6				= 54,
	MLX_KEY_7				= 55,
	MLX_KEY_8				= 56,
	MLX_KEY_9				= 57,
	MLX_KEY_SEMICOLON		= 59,
	MLX_KEY_EQUAL			= 61,
	MLX_KEY_A				= 65,
	MLX_KEY_B				= 66,
	MLX_KEY_C				= 67,
	MLX_KEY_D				= 68,
	MLX_KEY_E				= 69,
	MLX_KEY_F				= 70,
	MLX_KEY_G				= 71,
	MLX_KEY_H				= 72,
	MLX_KEY_I				= 73,
	MLX_KEY_J				= 74,
	MLX_KEY_K				= 75,
	MLX_KEY_L				= 76,
	MLX_KEY_M				= 77,
	MLX_KEY_N				= 78,
	MLX_KEY_O				= 79,
	MLX_KEY_P				= 80,
	MLX_KEY_Q				= 81,
	MLX_KEY_R				= 82,
	MLX_KEY_S				= 83,
	MLX_KEY_T				= 84,
	MLX_KEY_U				= 85,
	MLX_KEY_V				= 86,
	MLX_KEY_W				= 87,
	MLX_KEY_X				= 88,
	MLX_KEY_Y				= 89,
	MLX_KEY_Z				= 90,
	MLX_KEY_LEFT_BRACKET	= 91,
	MLX_KEY_BACKSLASH		= 92,
	MLX_KEY_RIGHT_BRACKET	= 93,
	MLX_KEY_GRAVE_ACCENT	= 96,
	MLX_KEY_ESCAPE			= 256,
	MLX_KEY_ENTER			= 257,
	MLX_KEY_TAB				= 258,
	MLX_KEY_BACKSPACE		= 259,
	MLX_KEY_INSERT			= 260,
	MLX_KEY_DELETE			= 261,
	MLX_KEY_RIGHT			= 262,
	MLX_KEY_LEFT			= 263,
	MLX_KEY_DOWN			= 264,
	MLX_KEY_UP				= 265,
	MLX_KEY_PAGE_UP			= 266,
	MLX_KEY_PAGE_DOWN		= 267,
	MLX_KEY_HOME			= 268,
	MLX_KEY_END				= 269,
	MLX_KEY_CAPS_LOCK		= 280,
	MLX_KEY_SCROLL_LOCK		= 281,
	MLX_KEY_NUM_LOCK		= 282,
	MLX_KEY_PRINT_SCREEN	= 283,
	MLX_KEY_PAUSE			= 284,
	MLX_KEY_F1				= 290,
	MLX_KEY_F2				= 291,
	MLX_KEY_F3				= 292,
	MLX_KEY_F4				= 293,
	MLX_KEY_F5				= 294,
	MLX_KEY_F6				= 295,
	MLX_KEY_F7				= 296,
	MLX_KEY_F8				= 297,
	MLX_KEY_F9				= 298,
	MLX_KEY_F10				= 299,
	MLX_KEY_F11				= 300,
	MLX_KEY_F12				= 301,
	MLX_KEY_F13				= 302,
	MLX_KEY_F14				= 303,
	MLX_KEY_F15				= 304,
	MLX_KEY_F16				= 305,
	MLX_KEY_F17				= 306,
	MLX_KEY_F18				= 307,
	MLX_KEY_F19				= 308,
	MLX_KEY_F20				= 309,
	MLX_KEY_F21				= 310,
	MLX_KEY_F22				= 311,
	MLX_KEY_F23				= 312,
	MLX_KEY_F24				= 313,
	MLX_KEY_F25				= 314,
	MLX_KEY_KP_0			= 320,
	MLX_KEY_KP_1			= 321,
	MLX_KEY_KP_2			= 322,
	MLX_KEY_KP_3			= 323,
	MLX_KEY_KP_4			= 324,
	MLX_KEY_KP_5			= 325,
	MLX_KEY_KP_6			= 326,
	MLX_KEY_KP_7			= 327,
	MLX_KEY_KP_8			= 328,
	MLX_KEY_KP_9			= 329,
	MLX_KEY_KP_DECIMAL		= 330,
	MLX_KEY_KP_DIVIDE		= 331,
	MLX_KEY_KP_MULTIPLY		= 332,
	MLX_KEY_KP_SUBTRACT		= 333,
	MLX_KEY_KP_ADD			= 334,
	MLX_KEY_KP_ENTER		= 335,
	MLX_KEY_KP_EQUAL		= 336,
	MLX_KEY_LEFT_SHIFT		= 340,
	MLX_KEY_LEFT_CONTROL	= 341,
	MLX_KEY_LEFT_ALT		= 342,
	MLX_KEY_LEFT_SUPER		= 343,
	MLX_KEY_RIGHT_SHIFT		= 344,
	MLX_KEY_RIGHT_CONTROL	= 345,
	MLX_KEY_RIGHT_ALT		= 346,
	MLX_KEY_RIGHT_SUPER		= 347,
	MLX_KEY_MENU			= 348,
}	keys_t;
/**
 * Objeto base para texturas cargadas en disco.
 * Contiene información básica sobre la textura.
 * 
 * @param width La anchura de la textura.
 * @param height La altura de la textura.
 * @param pixels Los datos literales de los píxeles.
 * @param bytes_per_pixel La cantidad de bytes en un píxel, siempre 4.
 */
 typedef struct mlx_texture
{
	uint32_t	width;
	uint32_t	height;
	uint8_t		bytes_per_pixel;
	uint8_t*	pixels;
}	mlx_texture_t;
/**
 * Estructura que contiene datos relativos a una imagen XPM.
 * 
 * @param texture Los datos de textura del XPM.
 * @param color_count La cantidad de colores disponibles.
 * @param cpp La cantidad de caracteres por píxel.
 * @param mode El modo de color, ya sea (c)olor o (m)onocromo.
 */
 typedef struct xpm
{
	mlx_texture_t	texture;
	int32_t			color_count;
	int32_t			cpp;
	char			mode;
}	xpm_t;
/**
 * Una instancia de imagen se puede resumir en una simple
 * coordenadas x, y & z.
 * 
 * Las coordenadas comienzan desde la parte superior izquierda de la pantalla en 0,0 y aumentan
 * hacia la parte inferior derecha.
 * 
 * NOTA: Para cambiar el valor de z, use mlx_set_instance_depth.
 * 
 * @param x La posición x.
 * @param y La ubicación y.
 * @param z La profundidad z, controla si la imagen está en primer o segundo plano.
 * @param enabled Si es true, la instancia se dibuja, si no, no.
 */
typedef struct mlx_instance
{
	int32_t x
	int32_t y
	int32_t z;
	bool enabled;
} mlx_instance_t

/**
 * Datos relacionados con la función mlx_key_hook.
 * Datos relacionados con la función mlx_key_hook.
 * 
 * @param key La tecla que fue presionada.
 * @param action La acción que se realizó con la tecla.
 * @param os_key La os_key es única para cada tecla, y tendrá un 
 * valor/keycode diferente dependiendo de la plataforma. 
 * Pueden ser consistentes en diferentes plataformas.
 * @param modifier La tecla modificadora que se pulsó, 0 si no se pulsó ninguna tecla.
 */
typedef struct mlx_key_data
{
	keys_t tecla;
	action_t acción;
	int32_t os_key;
	modificador_clave_t modificador;
} mlx_key_data_t;
/**
 * Una imagen con un buffer individual que puede ser renderizada.
 * Se puede modificar cualquier valor excepto la anchura/altura y el contexto.
 * 
 * @param width El ancho de la imagen.
 * @param height La altura de la imagen.
 * @param pixels Los datos literales de los píxeles.
 * @param instances Instancia que contiene los datos de localización X, Y y Z.
 * @param count El número de elementos de la matriz de instancias.
 * @param enabled Si es true la imagen se dibuja en la pantalla, si no, no.
 * @param context Datos OpenGL abstractos.
 */
typedef struct mlx_image
{
	const uint32_t anchura;
	const uint32_t altura;
	uint8_t* píxeles
	mlx_instance_t* instances;
	size_t count;
	bool enabled;
	void* context;
} mlx_image_t;

// Los códigos de error utilizados para identificar el mensaje de error correcto.
typedef enum mlx_errno
{
	MLX_SUCCESS = 0, // Ningún error
	MLX_INVEXT, // Archivo tiene una extensión inválida
	MLX_INVFILE, // El archivo no era válido / no existe.
	MLX_INVPNG, // Algo va mal con el archivo PNG dado.
	MLX_INVXPM, // El fichero XPM indicado no es correcto.
	MLX_INVPOS, // Las posiciones X/Y especificadas están fuera de los límites.
	MLX_INVDIM, // Las dimensiones W/H especificadas están fuera de los límites.
	MLX_INVIMG, // La imagen proporcionada no es válida, puede indicar una mala gestión de las imágenes.
	MLX_VERTFAIL, // Fallo al compilar el sombreador de vértices.
	MLX_FRAGFAIL, // Fallo al compilar el fragment shader.
	MLX_SHDRFAIL, // Error al compilar los shaders.
	MLX_MEMFAIL, // Fallo en la asignación de memoria dinámica.
	MLX_GLADFAIL, // Ha fallado el cargador OpenGL.
	MLX_GLFWFAIL, // Ha fallado la inicialización de GLFW.
	MLX_WINFAIL, // Fallo al crear una ventana.
	MLX_STRTOOBIG, // La cadena es demasiado grande para ser dibujada.
	MLX_ERRMAX, // Recuento de errores.
} mlx_errno_t;

// Código de error global de la librería MLX42, 0 si no hay error.
extern mlx_errno_t mlx_errno;

//= Configuración Global =//

// Establezca estos valores, si es necesario, antes de llamar a `mlx_init` ya que definen el comportamiento de MLX42.
typedef enum mlx_settings
{
	MLX_STRETCH_IMAGE = 0, // ¿Deben las imágenes cambiar de tamaño con la ventana o no? Por defecto: false
	MLX_FULLSCREEN, // En caso de que la ventana esté en pantalla completa, tenga en cuenta que lo hará a la resolución dada. Por defecto: false
	MLX_MAXIMIZED, // Inicia la ventana en estado maximizado, sobreescribe el estado de pantalla completa si este es verdadero. Por defecto: false
	MLX_DECORATED, // Que la ventana sea decorada con una barra de ventana. Por defecto: true
	MLX_HEADLESS, // Ejecutar en modo headless, no se crea ninguna ventana. (NOTA: Aún requiere algún tipo de gestor de ventanas como xvfb)
	MLX_SETTINGS_MAX, // Recuento de ajustes.
} mlx_settings_t;

**
 * Función de devolución de llamada utilizada para manejar el desplazamiento.
 * 
 * @param[in] xdelta El delta x del ratón.
 * @param[in] ydelta El delta y del ratón.
 * @param[in] param Parámetro adicional para pasar a la función.
 */
typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

**
 * Función de devolución de llamada utilizada para manejar el desplazamiento.
 * 
 * @param[in] xdelta El delta x del ratón.
 * @param[in] ydelta El delta y del ratón.
 * @param[in] param Parámetro adicional para pasar a la función.
 */
typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

/**
 * Función Callback utilizada para manejar las acciones del ratón.
 * 
 * @param[in] button El botón/tecla del ratón pulsado.
 * @param[in] action La acción del ratón que ha tenido lugar.
 * @param[in] mods Las teclas modificadoras pulsadas junto con la tecla del ratón.
 * @param[in] param Parámetro adicional a pasar a la función.
 */
typedef void (*mlx_mousefunc)(mouse_key_t button, action_t action, modifier_key_t mods, void* param);

/**
 * Función de llamada de retorno utilizada para manejar el movimiento del ratón.
 * 
 * @param[in] xpos La posición x del ratón.
 * @param[in] ypos La posición y del ratón.
 * @param[in] param Parámetro adicional para pasar a la función.
 */
typedef void (*mlx_cursorfunc)(double xpos, double ypos, void* param);
/**
 * Función de devolución de llamada utilizada para manejar la pulsación de teclas.
 * 
 * @param[in] keydata Los datos de la llamada de retorno, contiene información sobre la tecla, acción, ...
 * @param[in] param Parámetro adicional para pasar a la función.
 */
typedef void (*mlx_keyfunc)(mlx_key_data_t keydata, void* param);

/**
 * Función de devolución de llamada utilizada para gestionar el cambio de tamaño de la ventana.
 * 
 * ADVERTENCIA: La función es llamada cada frame durante el cual la ventana está siendo redimensionada.
 * redimensionada, ¡tenga cuidado!
 * 
 * @param[in] width La nueva anchura de la ventana.
 * @param[in] height La nueva altura de la ventana. 
 * @param[in] param Parámetro adicional para pasar a la función.
 */
typedef void (*mlx_resizefunc)(int32_t anchura, int32_t altura, void* param);

/**
 * Función de devolución de llamada utilizada para manejar el cierre de la ventana que se llama cuando 
 * el usuario intenta cerrar la ventana, por ejemplo haciendo clic en el widget 
 * en la barra de título.
 * 
 * @param[in] param Parámetro adicional para pasar a la función.
 */
typedef void (*mlx_closefunc)(void* param);
/** 
 * Typedef para un objeto cursor de ventana, estos eventualmente se expanden a
 * el objeto cursor nativo, pero están ocultos para el usuario.
 * 
 * Bajo GLFW se llaman GLFWcursor y tienen un wrapper para cada implementación.
 * Puedes encontrar el cursor ACTUAL en los siguientes archivos en GLFW nombrados bajo *_platform.h
 */
typedef void mlx_win_cursor_t;

//= Funciones de Error =//

/**
 * Obtiene la descripción en inglés del código de error.
 * 
 * @param[in] val El código de error.
 * @return La cadena de error que describe el código de error.
 */
const char* mlx_strerror(mlx_errno_t val);

//= Funciones Genéricas =//

/**
 * Inicializa una nueva Instancia MLX42.
 * 
 * @param[in] width Ancho de la ventana.
 * @param[in] height Altura de la ventana.
 * @param[in] title Título de la ventana.
 * @param[in] resize Habilita el cambio de tamaño de la ventana.
 * @returns Ptr to the MLX handle or null on failure.
 */
mlx_t* mlx_init(int32_t width, int32_t height, const char* title, bool resize);

/**
 * Establece una configuración para MLX42.
 * La configuración puede manipular el comportamiento central del motor.
 * 
 * @param[in] setting Valor de configuración, Ver tipo mlx_settings_t.
 * @param[in] value Valor de configuración para determinar el estado de la configuración. Puede ser un booleano o un enum / macro.
 */
void mlx_set_setting(mlx_settings_t setting, int32_t value);

/**
 * Notifica a MLX que debe dejar de renderizar y salir del bucle principal.
 * Esto no es lo mismo que terminar, esto simplemente le dice a MLX que cierre la ventana.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_close_window(mlx_t* mlx);

/**
 * Inicializa el renderizado de MLX, esta función no retornará hasta que
 * mlx_close_window sea llamada, lo que significa que hará un bucle hasta que el usuario solicite que
 * que la ventana se cierre.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_loop(mlx_t* mlx);

/**
 * Permite establecer una imagen personalizada como icono del programa.
 * 
 * NOTA: En MacOS esta función no hace nada, debes usar el icono de bundles para establecer el icono de la barra dock.
 * @ver: https://9to5mac.com/2021/11/08/change-mac-icons/
 * @ver: https://github.com/glfw/glfw/issues/2041
 *
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] image La imagen a usar como icono.
 */
void mlx_set_icon(mlx_t* mlx, mlx_texture_t* image);

/**
 * Termina MLX y limpia cualquiera de sus recursos usados.
 * El uso posterior de cualquier función que requiera mlx se considerará un comportamiento indefinido.
 * se considerará comportamiento indefinido, cuidado con los segfaults.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_terminate(mlx_t* mlx);

/**
 * Obtiene el tiempo transcurrido desde que MLX fue inicializado.
 * 
 * @return La cantidad de tiempo transcurrido en segundos.
 */
double mlx_get_time(void);

//= Funciones de ventana/monitor =//

/**
 * Esta función trae la ventana especificada al frente y establece el foco de entrada.
 * 
 * No use esta función para robar el foco de otras aplicaciones a menos que esté seguro de que es lo que el usuario quiere.
 * que esté seguro de que eso es lo que quiere el usuario. Robar el foco puede ser
 * extremadamente perjudicial.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 */
void mlx_focus(mlx_t* mlx);

/**
 * Obtiene el tamaño del monitor especificado.
 * 
 * @param[in] index Normalmente se puede especificar 0, en caso de múltiples ventanas.
 * @param[in] width La anchura de la ventana.
 * @param[in] height La altura de la ventana.
 */
void mlx_get_monitor_size(int32_t index, int32_t* width, int32_t* height);

/**
 * Establece la posición de la ventana.
 * 
 * No utilice esta función para mover una ventana ya visible a menos que tenga buenas razones para hacerlo, ya que confundirá y molestará al usuario.
 * tenga muy buenas razones para hacerlo, ya que confundirá y molestará al usuario.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] xpos La posición x.
 * @param[in] ypos La posición y.
 */
void mlx_set_window_pos(mlx_t* mlx, int32_t xpos, int32_t ypos);

/**
 * Cambia el tamaño de la ventana a los nuevos valores especificados.
 * Use esto para actualizar los valores de ancho y alto de la ventana en el manejador mlx.
 * 
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] new_width La nueva anchura deseada.
 * @param[in] new_height La nueva altura deseada.
 */
void mlx_set_window_size(mlx_t* mlx, int32_t new_width, int32_t new_height);

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
void mlx_set_window_limit(mlx_t* mlx, int32_t min_w, int32_t min_h, int32_t max_w, int32_t max_h);

/**
 * Establece el título de la ventana.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] title El título de la ventana.
 */
void mlx_set_window_title(mlx_t* mlx, const char* title);


//= Funciones de Entrada =//

/**
 * Devuelve true o false si la tecla está pulsada o no.
 * 
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] key El código de la tecla a comprobar, use MLX_KEY_... para especificarlo.
 * @devuelve True o false si la tecla está caída o no.
 */
bool mlx_is_key_down(mlx_t* mlx, keys_t key);

/**
 * Comprueba si un botón del ratón está pulsado o no.
 * 
 * @param[in] mlx El manejador de la instancia MLX. 
 * @param[in] key Una tecla específica del ratón. e.g MLX_MOUSE_BUTTON_0
 * @returns Verdadero o falso si la tecla del ratón está pulsada o no.
 */
bool mlx_is_mouse_down(mlx_t* mlx, mouse_key_t key);

/**
 * Devuelve la posición actual, relativa, del cursor del ratón en la ventana, empezando
 * desde la esquina superior izquierda.
 * 
 * Valores negativos o mayores que el ancho o alto de la ventana 
 * indican que está fuera de la ventana.
 * 
 * @param[in] mlx El manejador de la instancia MLX. 
 * @param[out] x La posición.
 * @param[out] y La posición.
 */

void mlx_get_mouse_pos(mlx_t* mlx, int32_t* x, int32_t* y);

* Establece la posición del ratón.
* 
* @param[in] mlx El manejador de la instancia MLX.
* @param[in] pos La posición.
*/
void mlx_set_mouse_pos(mlx_t* mlx, int32_t x, int32_t y);

* Establece la posición del ratón.
* 
* @param[in] mlx El manejador de la instancia MLX.
* @param[in] pos La posición.
*/
void mlx_set_mouse_pos(mlx_t* mlx, int32_t x, int32_t y);

* Establece la posición del ratón.
* 
* @param[in] mlx El manejador de la instancia MLX.
* @param[in] pos La posición.
*/
void mlx_set_mouse_pos(mlx_t* mlx, int32_t x, int32_t y);

* Destruye el objeto cursor dado.
*
* @param[in] cursor El objeto cursor a destruir.
*/
void mlx_destroy_cursor(mlx_win_cursor_t* cursor);

* Establece el cursor actual al cursor personalizado dado. 
*
* @param[in] mlx El manejador de instancia MLX.
* @param[in] cursor El objeto cursor a mostrar, si se selecciona cursor por defecto null.
 */
void mlx_set_cursor(mlx_t* mlx, mlx_win_cursor_t* cursor);

/= Ganchos =//

/**
* Esta función establece el callback de desplazamiento, que es llamado cuando un dispositivo de desplazamiento es usado, como una rueda de ratón.
* 
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] func Función de llamada de retorno de la rueda de desplazamiento.
 * @param[in] param Parámetro adicional opcional.
 */
void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);

/**
 * Esta función establece la llamada de retorno del ratón, que se llama cuando un ratón
* realiza cualquier tipo de acción como pulsar una tecla.
 * 
* @param[in] mlx El manejador de instancia MLX.
 * @param[in] func La función de llamada de retorno del ratón.
 * @param[in] param Parámetro adicional opcional.
 */
void mlx_mouse_hook(mlx_t* mlx, mlx_mousefunc func, void* param);

**
 * Esta función establece el callback del cursor, que es llamado cuando cambia la posición del ratón. La posición es relativa a la ventana.
* 
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] func Función de llamada al cursor.
 * @param[in] param Parámetro adicional opcional.
 */
void mlx_cursor_hook(mlx_t* mlx, mlx_cursorfunc func, void* param);

/**
 * This function sets the key callback, which is called when a key is pressed on the keyboard. Useful for single keypress detection.
 * 
 * @param[in] mlx The MLX instance handle.
 * @param[in] func The keypress callback function.
 * @param[in] param An additional optional parameter.
 */
void mlx_key_hook(mlx_t* mlx, mlx_keyfunc func, void* param);

Esta función establece el callback de redimensionamiento, que es llamado cuando la ventana es
 * redimensionada
 * 
 * @param[in] mlx El manejador de instancia MLX.
 * @param[in] func La función de redimensionamiento.
 * @param[in] param Parámetro adicional opcional.
 */
void mlx_resize_hook(mlx_t* mlx, mlx_resizefunc func, void* param);

/**
 * Gancho de bucle genérico para cualquier gancho personalizado a añadir al bucle principal. 
 * Ejecuta una función por fotograma, así que ten cuidado.
 * 
 * @param[in] mlx El manejador de la instancia MLX.
 * @param[in] f La función.
 * @param[in] param El parámetro a pasar a la función.
 * @returns Si el hook se ha añadido correctamente. 
 */
bool mlx_loop_hook(mlx_t* mlx, void (*f)(void*), void* param);

//= Funciones de textura =//

/**
 * Decodificar/cargar un archivo PNG en un buffer.
 * 
 * @param[in] path Ruta al archivo PNG.
 * @return Si tiene éxito se devuelven los datos de textura, si no NULL.
 */
mlx_texture_t* mlx_load_png(const char* path);

/**
* Carga una textura XPM42 desde la ruta de archivo indicada.
*
* @param[in] path La ruta de archivo a la textura XPM.
* @returns La estructura de la textura XPM que contiene su información.
*/
xpm_t* mlx_load_xpm42(const char* path);

/**
* Elimina una textura liberando los datos asignados.
*
* @param[in] texture La textura que se liberará.
*/
void mlx_delete_texture(mlx_texture_t* texture);

/**
* Elimina una textura XPM42 liberando sus datos asignados.
*
* Esto no eliminará ningún XPM ya dibujado, simplemente
* elimina el buffer XPM.
*
* @param[in] xpm La textura xpm que se eliminará.
*/
void mlx_delete_xpm42(xpm_t* xpm);

/**
* Convierte una textura dada en una imagen.
*
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] texture La textura que se usará para crear la imagen.
* @return mlx_image_t* La imagen creada a partir de la textura.
*/
mlx_image_t* mlx_texture_to_image(mlx_t* mlx, mlx_texture_t* texture);


//= Funciones de imagen =//

/**
* Establece/pone un píxel en una imagen.
*
* NOTA: Se considera un comportamiento indefinido cuando se coloca un píxel
* más allá de los límites de una imagen.
*
* @param[in] image El identificador de la instancia MLX.
* @param[in] x La posición de la coordenada X.
* @param[in] y La posición de la coordenada Y.
* @param[in] color El valor de color que se colocará.
*/
void mlx_put_pixel(mlx_image_t* image, uint32_t x, uint32_t y, uint32_t color);

/**
* Crea y asigna un nuevo buffer de imagen.
*
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] width El ancho deseado de la imagen.
* @param[in] height La altura deseada de la imagen.
* @return Puntero al buffer de imagen, si no se pudo asignar, entonces NULL.
*/
mlx_image_t* mlx_new_image(mlx_t* mlx, uint32_t width, uint32_t height);

/**
* Dibuja una nueva instancia de una imagen, que luego compartirá el mismo
* búfer de píxeles que la imagen.
*
* NOTA: Tenga en cuenta que la matriz de instancias se reasigna, intente
* almacenar el valor de retorno en la instancia.
* ¡NO el puntero! ¡Se volverá inválido!
*
* ADVERTENCIA: Intente mostrar la menor cantidad posible de imágenes en la ventana,
* ¡dibujar demasiadas imágenes provocará una pérdida de rendimiento!
*
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] img La imagen que se dibujará en la pantalla.
* @param[in] x La posición X.
* @param[in] y La posición Y.
* @return Índice a la instancia, o -1 en caso de error.
*/
int32_t mlx_image_to_window(mlx_t* mlx, mlx_image_t* img, int32_t x, int32_t y);

**
* Eliminar una imagen la quitará de la cola de renderizado, así como todas y cada una de las
* instancias que pueda tener. Además, como medida adicional, establece todos los
* datos en NULL.
*
* Si simplemente desea detener el renderizado de una imagen sin desasignarla
* establezca el booleano 'habilitado' en la estructura de la imagen.
*
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] image La imagen que se eliminará.
*/
void mlx_delete_image(mlx_t* mlx, mlx_image_t* image);

/**
* Le permite cambiar el tamaño de una imagen, se asigna un nuevo búfer de píxeles
* para ajustar y los datos anteriores se escalan para ajustarse al nuevo tamaño.
*
* @param[in] img La imagen a cambiar de tamaño.
* @param[in] nwidth El nuevo ancho.
* @param[in] nheight La nueva altura.
* @return True si se cambió el tamaño de la imagen o false en caso de error.
*/
bool mlx_resize_image(mlx_image_t* img, uint32_t nwidth, uint32_t nheight);

/**
* Establece el valor del eje Z/profundidad de una instancia.
*
* NOTA: Ten en cuenta que las imágenes que están en la misma capa Z se cortan entre sí.
* Por lo tanto, si ya no ves tu imagen, asegúrate de que no esté en conflicto por estar
* en la misma capa que otra imagen.
*
* @param[in] instance La instancia en la que se cambiará la profundidad.
* @param[in] zdepth El nuevo valor de profundidad.
*/
void mlx_set_instance_depth(mlx_instance_t* instance, int32_t zdepth);

//= Funciones de strings =//

/**
* Dibuja una cadena en una imagen y luego la muestra en la ventana.
*
* @param[in] mlx El identificador de la instancia MLX.
* @param[in] str La cadena que se dibujará.
* @param[in] x La ubicación X.
* @param[in] y La ubicación Y.
* @return Puntero de imagen a la cadena.
*/
mlx_image_t* mlx_put_string(mlx_t* mlx, const char* str, int32_t x, int32_t y);

/**
* Recupera los datos de textura para la fuente incorporada.
*
* @return Puntero a la textura de la fuente incorporada.
*/
const mlx_texture_t* mlx_get_font(void);

/**
* Esta función le permite recuperar el desplazamiento X
* del carácter dado en la textura de la fuente.
*
* NOTA: ¡Un solo carácter tiene 10 * 20 píxeles!
*
* @param[in] c El carácter del que se obtendrá el desplazamiento.
* @return No negativo si se encuentra o -1 si no se encuentra.
*/
int32_t mlx_get_texoffset(char c);

# ifdef __cplusplus
}
# endif
#endif
