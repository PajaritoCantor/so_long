/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:10:57 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/04 23:21:23 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map *init_map(void)
{
   t_game_map *map = ft_calloc(1, sizeof(t_game_map));
   if (!map)
        return (NULL);
    map->matrix = NULL;
    map->rows = 0;
    map->cols = 0;
    map->num_players = 0;
    map->num_exits = 0;
    map->num_collectibles = 0;
    return (map);
}