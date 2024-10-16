# SO_LONG

* **Orden de desarrollo de funciones**

1. **Leer el archivo .ber:**
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

* **t_game_map * init_map(void)** Esta función inicializa una nueva estructura **t_game_map**, reservando memoria para ella y estableciendo sus campos en cero, retornando un puntero a la estructura o **NULL** si falla la asignación.
  
* **int open_file(char * file_path)** Esta función abre un archivo en modo de solo lectura, retornando un **descriptor de archivo** o **-1** si hay un error.

* **char * read_file(int fd)** Esta función lee el contenido de un archivo hassta alcanzar el final, acumulando el contenido en una cadena y retornándola, o liberando la memoria y retornando **NULL** si ocurre un error durante la lectura.

* **t_game_map * read_map(char * file_path)** Esta función se encarga de leer un archivo de mapa, utilizando **open_file** para abrir el archivo y **read_file** para obtener su contenido, dividiéndolo en líneas y validando la estructura del mapa, retornando un puntero a la estructura llena o **NULL** si hay un error.

* **int fill_matrix(t_game_map * map, char ** lines)** Esta función llena la matriz de la estructura con líneas del mapa, duplicando las cadenas y almacenándolas, retornando **1** en caso de éxito o **0** si ocurre un error.

* **void free_map(t_game_map * map)** Esta función libera la memoria utilizada por la estructura **t_game_map**, incluyendo su matriz de caracteres, asegurándose de no intentar liberar un puntero nulo.

* **int is rectangular(t_game_map * map)** Esta función verifica si el mapa es rectangular comparando la longitud de cada fila en la matriz con la longitud de la primera fila, retornando **1** si es rectangular o **0** en caso contrario.

* **int check_valid_characters(tgame_map * map)** Esta función comprueba que el mapa esté rodeado de paredes, verificando que la primera y última filas contengan solo el carácter de pared, retornando **1** si están bien o **0** en caso contrario.

* **int is_map_surrounded_by_walls(t_game_map * map)** Esta función comprueba que el mapa esté rodeado de paredes verificando que la primera y última filas contengan sólo el carácter de pared, retornando **1** si están bien o **0** en caso contrario.

* **int validate_map(t_game_map * map)** Esta función valida la estructura del mapa utilizando las funciones anteriores para comprobar si el mapa es rectangular, está rodeado de paredes y 
