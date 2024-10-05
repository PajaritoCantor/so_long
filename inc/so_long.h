/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/05 18:10:33 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <stdio.h> 
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_map
{
    char    **matrix;
    int     cols;
    int     rows;
    int     num_players;
    int     num_exits;
    int     num_collectibles;
} t_game_map;

t_game_map  *read_map(char *file_path);
t_game_map  *init_map(void);
void        free_map(t_game_map *map);
int         open_file(char *file_path);
char         *read_file(int fd);
int         fill_matrix(t_game_map *map, char **lines);
int         validate_map(t_game_map *map);
int         is_map_surrounded_by_walls(t_game_map *map);
int         is_rectangular(t_game_map *map);
int         is_map_surrounded_by_walls(t_game_map *map);


/*int         validate_map(t_game_map *map);
int         is_map_surrounded_by_walls(t_game_map *map);
int         check_valid_characters(t_game_map * map);
int         is_rectangular(t_game_map *map);
*/
#endif 