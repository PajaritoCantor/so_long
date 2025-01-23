# SO_LONG
 **Orden de desarrollo de funciones**

1. **Leer el archivo .ber** 
* **init_map** Inicializar la struct del mapa.
* **read_all_lines** Leer el archivo y guardarlo en un array 2D. Usar get_next_line. Luego usar split. 
*  **set_map_data** Alocar memoria para la matrix del mapa e introducir los elementos del mapa dentro de dicha matrix.
*  **validate map** Validar la estructura del mapa (rectangular, cerrado, caracteres)
*  **validate_path** Ubicar la posición del player, hacer una copia del mapa y utilizar **flood_fill** para verificar que el mapa es válido, es decir, para cerciorarse que el jugador puede recoger todos los coleccionables y acceder al exit sin problema.

2. **Inicialización de gráficos:**
* **init_game** Es la función principal donde se irá alocando memoria para cada elemento del juego (window, textures, player). Se inicializa la ventana, se cargan las texturas, se convierten a instancias de imagen.
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

