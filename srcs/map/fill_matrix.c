/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 01:17:58 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/05 18:16:12 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int fill_matrix(t_game_map *map, char **lines)
{
    int new_rows;
    char    **new_matrix;
    int     i;

    new_rows = 0;
    while (lines[new_rows] != NULL)
            new_rows++;
    new_matrix = malloc(sizeof(char *) * (new_rows + 1));
    if (!new_matrix)
        return (0);
    i = 0;
    while (i < new_rows)
    {
        new_matrix[i] = ft_strdup(lines[i]);
        i++;
    }
    new_matrix[new_rows] = NULL;
    free(map->matrix);
    map->matrix = new_matrix;
    map->rows = new_rows;

    return (1);
}