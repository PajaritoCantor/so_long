/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 21:02:56 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/04 21:11:49 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_map(t_game_map *map)
{
    char    **matrix;
    int     rows;

    if (!map)
        return ;
    matrix = map->matrix;
    rows = map->rows;
    if (rows > 0)
    {
        free(matrix[--rows]);
    }
    free(matrix);
    free(map);
}