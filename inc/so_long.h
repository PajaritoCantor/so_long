/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/27 01:08:45 by jurodrig         ###   ########.fr       */
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

# define WALL_TEXTURE "texture/Wall.xpm"
# define FLOOR_TEXTURE "textures/floor.xpm"
# define PLAYER_TEXTURE "textures/collectible.xpm"
# define COLLECTIBLE_TEXTURE "texture/collectibe.xpm"
# define EXIT_TEXTURE "textures/exit.xpm"
# define TILE_SIZE 32

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'

typedef struct s_map
{
	char		**matrix;
	int			cols;
	int			rows;
	int			start_x;
	int			start_y;
	int			num_players;
	int			num_exits;
	int			num_collectibles;
}				t_game_map;

typedef struct s_textures
{
	void		*wall_img;
	void		*background_img;
	void		*player_img;
	void		*exit_img;
	void		*caracter_img;
}				t_textures;

typedef struct s_window
{
	void		*mlx;
	void		*mlx_win;
	int			win_width;
	int			win_height;
}				t_window;

typedef struct s_position
{
	int			player_x;
	int			player_y;
}				t_position;

typedef struct s_game
{
	t_window	*window;
	t_game_map	*map;
	t_textures	*textures;
	t_position	*player_pos;
}				t_game;

void			freedom(void **p, void **p2);
void			free_map(t_game_map *map);
void			free_matrix(char **new_matrix, int filled_rows);
void			free_p2(char **matrix);
int				verificity_ber(char *file_name);
void			print_map(t_game_map *map);
// map
t_game_map		*read_map(char *file_path);
t_game_map		*init_map(void);
char			*read_all_lines(char *file_path);
int				open_file(char *file_path);
int				set_map_data(t_game_map *map, char **lines);
int				allocate_lines(char ***matrix, char **lines, int *rows);
int				count_lines(char **lines);
int				allocate_matrix(char ***matrix, int rows);
int				copy_lines_to_matrix(char **matrix, char **lines, int rows,
					t_game_map *map);
int				validate_map(t_game_map *map);
int				check_valid_characters(t_game_map *map);
int				valid_essential_characters(t_game_map *map);
int				is_rectangular(t_game_map *map);
int				is_map_surrounded_by_walls(t_game_map *map);
void			find_start_point(t_game_map *map, int *start_x, int *start_y);
void			flood_fill(t_game_map *map, int x, int y, char to_fill);
void			start_flood_fill(t_game_map *map);
bool			check_all_collectible(t_game_map *map);
bool			is_exit_reachable(t_game_map *map);
char			**copy_map_matrix(t_game_map *map);
bool			validate_path(t_game_map *map, int start_x, int start_y);

void			init_game(t_window *window, t_game_map *game);
// t_game_map		*cleanup(t_game_map *map, char **lines);

#endif