/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/13 18:14:57 by jurodrig         ###   ########.fr       */
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
# define PLAYER_LEFT_TEXTURE_1 "./textures/player_walk_left_1.xpm42"
# define PLAYER_LEFT_TEXTURE_2 "./textures/player_walk_left_2.xpm42"
# define PLAYER_LEFT_TEXTURE_3 "./textures/player_walk_left_3.xpm42"
# define PLAYER_RIGHT_TEXTURE_1 "./textures/player_walk_right_1.xpm42"
# define PLAYER_RIGHT_TEXTURE_2 "./textures/player_walk_right_2.xpm42"
# define PLAYER_RIGHT_TEXTURE_3 "./textures/player_walk_right_3.xpm42"
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
}				t_direction;

typedef struct s_position
{
	int			position_x;
	int			position_y;
	t_direction	facing;
	int			collected;
	int			is_jumping;
	int			velocity_y;
	int			on_ground;
	int			moves;
	int			animation_frame;
	void		*current_texture;
}				t_position;

typedef struct s_map
{
	char		**matrix;
	int			cols;
	int			rows;
	int			num_exits;
	int			num_collectibles;
}				t_map;

typedef struct s_textures
{
	void		*static_map_img;
	void		*wall_img;
	void		*background_img;
	void		*player_img;
	void		*enemy_img;
	void		*exit_img;
	void		*caracter_img;
	void		*player_img_left[2];
	void		*player_img_right[2];
}				t_textures;

typedef struct s_window
{
	mlx_t		*mlx;
	int			win_width;
	int			win_height;
}				t_window;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_textures	*textures;
	t_position	*player;
	int			gravity_timer;
	int			jump_height;
}				t_game;

t_map			*read_map(char *file_path);
t_map			*init_map(void);
char			*read_all_lines(char *file_path);
int				open_file(char *file_path);
int				set_map_data(t_map *map, char **lines);
int				allocate_lines(char ***matrix, char **lines, int *rows);
int				count_lines(char **lines);
int				allocate_matrix(char ***matrix, int rows);
int				copy_lines_to_matrix(char **matrix, char **lines, int rows, t_map *map);
int				validate_map(t_map *map);
int				check_valid_characters(t_map *map);
int				valid_essential_characters(t_map *map);
void			count_essentials(char *row, int cols, int *essentials);
int				is_rectangular(t_map *map);
int				is_map_surrounded_by_walls(t_map *map);
bool			find_start_point(t_map *map);
void			flood_fill(t_map *map, int x, int y);
bool			check_all_collectible(t_map *map);
bool			is_exit_reachable(t_map *map);
char			**copy_map_matrix(t_map *map);
bool			validate_path(t_map *map, int start_x, int start_y);
// game
void			init_game(t_game *game);
void			load_textures(t_game *game);
void			convert_textures(t_game *game);
void			convert_textures_two(t_game *game, void *temp);
void			check_textures_error(t_game *game);
void			update_texture_vertical(t_game *game, int dy);
void			update_texture_right(t_game *game);
void			update_texture_left(t_game *game;
void			search_player_and_collectibles(t_game *game);
void			render_map(t_game *game);
void			render_tile(t_game *game, char tile, int x, int y);
void			draw_player(t_game *game);
// controls
void			handle_keypress(mlx_key_data_t keydata, void *param);
void			close_handler(void *param);
void			end_game(t_game *game, const char *message);
void			move_player(t_game *game, int dx, int dy);
void			detect_position(t_game *game, int x, int y);
void			display_moves(t_game *game);

void			freedom(void **p, void **p2);
void			free_map(t_map *map);
void			free_matrix(char **new_matrix, int filled_rows);
void			free_double_pointer(char **matrix);
int				verificity_ber(char *file_name);
void			print_map(t_map *map);
void			free_images(t_game *game);
void			free_textures(t_game *game);

#endif