/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/30 18:32:17 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
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
# define ERROR "\033[1;31m❌ Error: Error in function!\n\033[0m" // Rojo
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
	int			num_players;
	int			num_exits;
	int			num_collectibles;
}				t_game_map;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_game_map	*game;
	int			win_width;
	int			win_height;
	void		*wall_img;
    int         player_x;
    int         player_y;
}				t_vars;

bool			check_ber(char *argv);
void			check_valid_map(t_game_map *game);
void			ft_print_game(t_game_map *map);

t_game_map	*read_map(char *file_path);
t_game_map	*init_map(void);
t_game_map	*cleanup(t_game_map *map, char **lines);
char		*read_all_lines(char *file_path);
void		free_map(t_game_map *map);
int 		verificity_ber(char *file_name);

int 			set_map_data(t_game_map *map, char **lines);
int 			count_lines(char **lines);
int 			allocate_matrix(char ***new_matrix, int new_rows);
void			render_tile(t_vars *vars, int x, int y, char tile);
void    		free_new_matrix(char **new_matrix, int filled_rows);

int				validate_map(t_game_map *map);
int				is_map_surrounded_by_walls(t_game_map *map);
int				is_rectangular(t_game_map *map);

void			move_player(t_vars *vars, int x_offset, int y_offset);
int				init_game(t_vars *vars, t_game_map *game);
void			render_map(t_vars *vars, t_game_map *game);
void			draw_tile(t_vars *vars, int x, int y, char *texture_path);

#endif