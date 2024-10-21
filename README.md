# SO_LONG

* **Orden de desarrollo de funciones**

1. **Leer el archivo .ber:** // Usar gnl propio
* **read_map():** Leer el archivo y guardarlo en un array 2D.
*  **validate map():** Validar la estructura del mapa (rectangular, cerrado, etc.)

2. **Inicialización de gráficos:**
* **init_game():** Inicializa la ventana, carga texturas y muestra la pantalla inicial.
* **render_map():** Renderiza los elementos del mapa en la ventana.

3. **Control de movimiento:**
* **handle_input():** Controla las entradas del teclado (WASD, flechas, direccionales).
* **move_player()** Actualiza la posición del jugador y renderiza el nuevo estado.

4. **Comprobación de colisiones y condiciones de victoria:**
* **check_collisions():** Verifica si el jugadoir ha recolectado todos los objetos y si puede salir.
* **check_valid_path():** Implementa un algoritmo para verificar que haya un camino válido en el mapa.

5. **Interacción y cierre:**
* **exit_game():** Maneja el cierre del juego (tecla ESC o clic en la cruz roja).

6. **Mensaje de error:**
* **error_message():** Muestra los errores con mensajes adecuados.

## Funciones

### Leer el archivo .ber

* **t_game_map * read_map(char * file_path)** Esta función se encarga de leer un archivo de mapa, utilizando **open_file** para abrir el archivo y **read_file** para obtener su contenido, dividiéndolo en líneas y validando la estructura del mapa, retornando un puntero a la estructura llena o **NULL** si hay un error.

* **t_game_map * init_map(void)** Esta función inicializa una nueva estructura **t_game_map**, reservando memoria para ella y estableciendo sus campos en cero, retornando un puntero a la estructura o **NULL** si falla la asignación.
  
* **int open_file(char * file_path)** Esta función abre un archivo en modo de solo lectura, retornando un **descriptor de archivo** o **-1** si hay un error.

* **void free_map(t_game_map * map)** Esta función libera la memoria utilizada por la estructura **t_game_map**, incluyendo su matriz de caracteres, asegurándose de no intentar liberar un puntero nulo.w

* **char * read_file(int fd)** Esta función lee el contenido de un archivo hassta alcanzar el final, acumulando el contenido en una cadena y retornándola, o liberando la memoria y retornando **NULL** si ocurre un error durante la lectura.

* **int fill_matrix(t_game_map * map, char ** lines)** Esta función llena la matriz de la estructura con líneas del mapa, duplicando las cadenas y almacenándolas, retornando **1** en caso de éxito o **0** si ocurre un error.

* **int validate_map(t_game_map * map)** Esta función valida la estructura del mapa utilizando las funciones anteriores para comprobar si el mapa es rectangular, está rodeado de paredes y contiene solo caracteres válidos retornando **1** si es válido o **0** si se encuentra algún error.

* **int is rectangular(t_game_map * map)** Esta función verifica si el mapa es rectangular comparando la longitud de cada fila en la matriz con la longitud de la primera fila, retornando **1** si es rectangular o **0** en caso contrario.

* **int is_map_surrounded_by_walls(t_game_map * map)** Esta función comprueba que el mapa esté rodeado de paredes verificando que la primera y última filas contengan sólo el carácter de pared, retornando **1** si están bien o **0** en caso contrario.
  
* **int check_valid_characters(tgame_map * map)** Esta función comprueba que el mapa esté rodeado de paredes, verificando que la primera y última filas contengan solo el carácter de pared, retornando **1** si están bien o **0** en caso contrario.

### Inicialización de gráficos

* **void draw_tile(t_vars * vars, int x, int y, void * img)** Esta función se encarga de cargar una imagen de tipo XPM en la memoria (a través de **mlx_xpm_file_to_image** y luego colocarla en las coordenadas especificadas dentro de la ventana del juego usando **mlx_put_image_to_window**. Si la imagen no se puede cargar, no realiza ninguna acción. Esta función está vinculada a la representación visual de cada tile del mapa, que fue previamente definido y validado en las funciones de manejo de mapas como **read_map** y **fill_matrix**.
  
* **void render_tile(t_vars * vars int x, int y, char tile)** Aquí, según el carácter **tile** que representa cada celda del mapa (1, 0, P, E, C), se llama a **draw_tile** para dibujar la imaagen correspondiente (pared, espacio vacío, jugador, salida o coleccionable). Está directamente relacionada con la función **fill_matrix** y **validate_map**, ya que utiliza el contenido del mapa previamente cargado  validado para seleccionar qué imagen debe dibujarse en pantalla.

* **void init_game(t_vars * vars, t_game_map * game)** Esta función inicia los elementos necesarios del juego: inicializa la conexión con la librería gráfica MLX(mlx_init), crea la ventana del juego con el tamaño basado en las dimensiones del mapa(en función de game->rows y game->cols), y carga las imágenes que se utilizarán para cada tipo de tile (pared, vacío, jugador, etc). Luego llama a **render_game+* para dibujar el mapa completo en la pantalla. Esta función tiene relación con **read_map**, ya que el mapa se necesita correctamente cargado y validado para que las imágenes puedan ser colocadas en la ventana del juego.
