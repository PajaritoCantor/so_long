/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:02:46 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/31 11:03:20 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int allocate_lines(char ***matrix, char **lines, int *rows)
{
    *rows = count_lines(lines);
    if (!allocate_matrix(matrix, *rows))
        return (0);
    return (1);
} 

int duplicate_lines(char **new_matrix, char **lines, int rows, t_game_map *map)
{
    int i;

    i = 0;
    while (i < rows)
    {
        new_matrix[i] = ft_strdup(lines[i]);
        if (!new_matrix[i])
        {
            printf("duplicate_lines: failed at row %d\n", i);
            free_matrix(new_matrix, i);
            free(map->matrix);
            return (0);
        }
        printf("duplicate_lines: copied row %d\n", i);
        i++;
    }
    return (1);
}

int set_map_data(t_game_map *map, char **lines)
{
    char    **new_matrix;
    int     new_rows;

    if (!lines || !lines[0])
        return (0);
    if (!allocate_lines(&new_matrix, lines, &new_rows))
        return (0);
    if (!duplicate_lines(new_matrix, lines, new_rows, map))
        return (0);
    new_matrix[new_rows] = NULL;
    free(map->matrix);
    map->matrix = new_matrix;
    map->rows = new_rows;

    if (new_matrix[0] != NULL)
        map->cols = ft_strlen(new_matrix[0]);
    else
        map->cols = 0;
    return (1);
}

