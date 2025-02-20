/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/23 12:39:44 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <bits/types.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define TILE_SIZE 32
# define MAX_MAP_AREA 2000

# define USAGE "\nUsage:./so_long [map.ber]"
# define ERROR_MAP "\nInvalid map"
# define ERROR_MAP_FILE_EXTENSION "\nInvalid map file extension.\n"
# define ERROR_MAP_READ "Reading map\n"
# define ERROR_START_POINT "Start point not found\n"
# define ERROR_COLLECTIBLE_NOT_FOUND "collectible not found\n"
# define ERROR_EXIT_NOT_FOUND "exit not found\n"
# define EXIT_FOUND "exit found\n"
# define ERROR_MEMORY_ALLOCATION "Memory allocation error\n"
# define ERROR_MLX "initialing MLX"
# define ERROR_LOAD_TEXTURES "load textures\n"
# define ERROR_CONVERT_TEXTURES "missing textures\n"
# define ERROR_ASSIGN_TEXTURES "assigning textures\n"
# define ERROR_WINDOW "creating window"

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

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_position
{
	int			position_x;
	int			position_y;
	int			collected;
	int			is_jumping;
	int			velocity_y;
	int			on_ground;
	int			moves;
	void		*current_texture;
	int			prev_position_x;
	int			prev_position_y;
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
	void		*wall_img;
	void		*background_img;
	void		*player_img;
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

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_game
{
	t_window	*window;
	t_map		*map;
	t_textures	*textures;
	t_position	*player;
}				t_game;

t_map			*read_map(char *file_path);
t_map			*init_map(void);
char			*read_all_lines(char *file_path);
int				open_file(char *file_path);
int				validate_map_dimensions(char **lines, int *rows, int *cols);
t_map			*initialize_map_with_validation(char *file_path, char ***lines);
int				set_map_data(t_map *map, char **lines);
int				allocate_lines(char ***matrix, char **lines, int *rows);
int				count_lines(char **lines);
int				allocate_matrix(char ***matrix, int rows);
int				copy_lines_to_matrix(char **map_matrix, char **lines,
					int map_rows);
int				validate_map(t_map *map);
void			count_essential_characters(t_map *map, int *essentials);
int				check_valid_characters(t_map *map);
int				valid_essential_characters(t_map *map);
int				valid_essential_characters(t_map *map);
int				is_rectangular(t_map *map);
int				is_map_surrounded_by_walls(t_map *map);
bool			find_start_point(t_map *map);
void			flood_fill(t_map *map, int x, int y);
bool			check_all_collectible(t_map *map);
bool			is_exit_reachable(t_map *map);
char			**copy_map_matrix(t_map *map);
bool			validate_path(t_map *map, int start_x, int start_y);

void			init_game(t_game *game);
void			load_textures(t_game *game);
void			convert_textures(t_game *game);
void			search_player_and_collectibles(t_game *game);
void			render_map(t_game *game);
void			render_tile(t_game *game, char tile, int x, int y);
void			draw_player(t_game *game);

void			handle_keypress(mlx_key_data_t keydata, void *param);
void			update_sprite_vertical(t_game *game, int dy);
void			update_sprite_right(t_game *game);
void			update_sprite_left(t_game *game);
void			detect_position(t_game *game, int x, int y);
void			move_player(t_game *game, int dx, int dy);
void			close_handler(void *param);
void			end_game(t_game *game, const char *message);
void			move_player(t_game *game, int dx, int dy);
void			detect_position(t_game *game, int x, int y);

void			freedom(void **p, void **p2);
void			free_map(t_map *map);
void			free_matrix(char **new_matrix, int filled_rows);
void			free_double_pointer(char **matrix);
int				verificity_ber(char *file_name);
void			print_map(t_map *map);
void			free_textures(t_game *game);
void			free_images(t_game *game);
void			check_textures_error(t_game *game);

#endif