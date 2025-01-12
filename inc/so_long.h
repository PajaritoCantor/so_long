/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/12 22:32:35 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// mensajes para usar en ft_error y ft_success
# define USAGE "Error\nUsage: ./so_long [map.ber], 36"
# define ERROR_MAP "Error\nInvalid map"
# define ERROR_MAP_READ "Reading map\n"
# define ERROR_MLX "Error initialing MLX"
# define ERROR_WINDOW "Error creating window"
# define SUCCESS "\033[1;32m✅ Success: Funtion finished well!\n\033[0m" // Verde
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m"         // Rojo
# define WARNING "\033[1;33m⚠️ Warning: Warning in function!\n\033[0m"

# define WALL_TEXTURE "./textures/wall.xpm42"
# define FLOOR_TEXTURE "./textures/floor.xpm42"
# define PLAYER_TEXTURE "./textures/player.xpm42"
# define COLLECTIBLE_TEXTURE "./textures/collectible.xpm42"
# define EXIT_TEXTURE "./textures/exit.xpm42"
# define ENEMY_TEXTURE "./textures/enemy.xpm42"
# define TILE_SIZE 32

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define ENEMY 'X'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef enum e_direction
{
	STILL,
	UP,
	DOWN,
	LEFT,
	RIGHT
}		t_direction;

typedef struct s_position
{
	int position_x;     // Posición X actual del jugador
	int position_y;     // Posición Y actual del jugador
	t_direction facing; // Dirección hacia la que mira el jugador
	int collected;      // Número de coleccionables recogidos
	int is_jumping;     // Indicador de si el jugador está saltando
	int velocity_y;     // Velocidad vertical del jugador
	int	on_ground;
	int	moves;
}		t_position;

typedef struct s_map
{
	char **matrix;        // Matriz del mapa
	int cols;             // Número de columnas
	int rows;             // Número de filas
	int num_exits;        // Número de salidas
	int num_collectibles; // Número de coleccionables
}		t_map;

typedef struct s_textures
{
	void *wall_img;       // Imagen del muro
	void *background_img; // Imagen del fondo
	void *player_img;     // Imagen del jugador
	void *enemy_img;      // Imagen del enemigo
	void *exit_img;       // Imagen de la salida
	void *caracter_img;   // Imagen de los coleccionables
}		t_textures;

typedef struct s_window
{
	mlx_t *mlx;     // Contexto de MLX
	int win_width;  // Ancho de la ventana
	int win_height; // Alto de la ventana
}		t_window;

typedef struct s_game
{
	t_window *window;     // Información de la ventana
	t_map *map;           // Información del mapa
	t_textures *textures; // Texturas del juego
	t_position *player;   // Información del jugador
	int gravity_timer;    // Temporizador para gravedad
	int jump_height;      // Altura máxima del salto
}		t_game;

// map
t_map	*read_map(char *file_path);
t_map	*init_map(void);
char	*read_all_lines(char *file_path);
int		open_file(char *file_path);
int		set_map_data(t_map *map, char **lines);
int		allocate_lines(char ***matrix, char **lines, int *rows);
int		count_lines(char **lines);
int		allocate_matrix(char ***matrix, int rows);
int		copy_lines_to_matrix(char **matrix, char **lines, int rows, t_map *map);
int		validate_map(t_map *map);
int		check_valid_characters(t_map *map);
int		valid_essential_characters(t_map *map);
int		is_rectangular(t_map *map);
int		is_map_surrounded_by_walls(t_map *map);
bool	find_start_point(t_map *map);
void	flood_fill(t_map *map, int x, int y);
bool	check_all_collectible(t_map *map);
bool	is_exit_reachable(t_map *map);
char	**copy_map_matrix(t_map *map);
bool	validate_path(t_map *map, int start_x, int start_y);
// game
void	init_game(t_game *game);
void	load_textures(t_game *game);
void	convert_textures(t_game *game);
void	search_player_and_collectibles(t_game *game);
void	render_map(t_game *game);
void	render_tile(t_game *game, char tile, int x, int y);
void	draw_player(t_game *game);
// controls
void	handle_keypress(mlx_key_data_t keydata, void *param);
void	close_handler(void *param);
void	end_game(t_game *game, const char *message);
void	move_player(t_game *game, int dx, int dy);
void	detect_position(t_game *game, int x, int y);
void	display_moves(t_game *game);

// void	apply_gravity(t_game *game);

// free
void	freedom(void **p, void **p2);
void	free_map(t_map *map);
void	free_matrix(char **new_matrix, int filled_rows);
void	free_double_pointer(char **matrix);
int		verificity_ber(char *file_name);
void	print_map(t_map *map);
void	free_images(t_game *game);
void	free_textures(t_game *game);

#endif