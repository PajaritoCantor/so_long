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
