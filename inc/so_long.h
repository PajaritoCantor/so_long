/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/22 16:00:39 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h> 
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"


# define WALL_TEXTURE "texture/Wall.xpm"
# define FLOOR_TEXTURE "textures/floor.xpm"
# define PLAYER_TEXTURE "textures/collectible.xpm"
# define COLLECTIBLE_TEXTURE "texture/collectibe.xpm"
# define EXIT_TEXTURE "textures/exit.xpm"
# define TILE_SIZE 32

typedef struct s_map
{
    char    **matrix;
    int     cols;
    int     rows;
    int     num_players;
    int     num_exits;
    int     num_collectibles;
} t_game_map;

typedef struct s_vars
{
    void    *mlx;
    void    *mlx_win;
    t_game_map  *game;
    int     win_width;
    int     win_height;
    int    wall_img;
}   t_vars;

bool        check_ber(char *argv);

t_game_map  *read_map(char *file_path);
t_game_map  *init_map(void);
void        free_map(t_game_map *map);
int         open_file(char *file_path);
char         *read_file(int fd);
int         fill_matrix(t_game_map *map, char **lines);

int         validate_map(t_game_map *map);
int         is_map_surrounded_by_walls(t_game_map *map);
int         is_rectangular(t_game_map *map);

void    init_game(t_vars *vars, t_game_map *game);
void    render_map(t_vars *vars, t_game_map *game);
void    draw_tile(t_vars *vars, int x, int y, char *texture_path);

#endif 