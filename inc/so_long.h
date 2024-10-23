/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 11:05:03 by danpalac         ###   ########.fr       */
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

# define WALL_TEXTURE "texture/Wall.xpm"
# define FLOOR_TEXTURE "textures/floor.xpm"
# define PLAYER_TEXTURE "textures/collectible.xpm"
# define COLLECTIBLE_TEXTURE "texture/collectibe.xpm"
# define EXIT_TEXTURE "textures/exit.xpm"
# define TILE_SIZE 32

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

t_game_map		*read_map(char *file_path);
t_game_map		*init_map(void);
void			free_map(t_game_map *map);
int				open_file(char *file_path);
char			*read_file(int fd);
int				fill_matrix(t_game_map *map, char **lines);

void			render_tile(t_vars *vars, int x, int y, char tile);
int				validate_map(t_game_map *map);
int				is_map_surrounded_by_walls(t_game_map *map);
int				is_rectangular(t_game_map *map);

void			move_player(t_vars *vars, int x_offset, int y_offset);
void			init_game(t_vars *vars, t_game_map *game);
void			render_map(t_vars *vars, t_game_map *game);
void			draw_tile(t_vars *vars, int x, int y, char *texture_path);

#endif