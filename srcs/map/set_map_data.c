/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 16:02:46 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/30 23:35:28 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_new_matrix(char **new_matrix, int filled_rows)
{
    while (--filled_rows >= 0)
        free(new_matrix[filled_rows]);
    free(new_matrix);
}

int allocate_matrix(char ***new_matrix, int new_rows)
{
    *new_matrix = calloc(new_rows + 1, sizeof(char *));
    return (*new_matrix != NULL);
} 

int count_lines(char **lines)
{
    int count;

    count = 0;
    while (lines[count])
        count++;
    return (count);
}

int set_map_data(t_game_map *map, char **lines)
{
    char    **new_matrix;
    int     new_rows;
    int     i;

    if (!lines || !lines[0])
        return (0);

    new_rows = count_lines(lines);
    if (!allocate_matrix(&new_matrix, new_rows))
        return (0);

    i = 0;
    while (i < new_rows)
    {
        new_matrix[i] = ft_strdup(lines[i]);
        if (!new_matrix[i])
        {
            free_new_matrix(new_matrix, i);
            free(map->matrix);
            return (0);
        }
        i++;
    }
    new_matrix[new_rows] = NULL;

    free(map->matrix);
    map->matrix = new_matrix;
    map->rows = new_rows;

    // Impresiones de Depuración
    if (new_matrix != NULL) {
        if (new_matrix[0] != NULL) {
            map->cols = ft_strlen(new_matrix[0]);
            printf("map->cols se ha establecido correctamente a %d\n", map->cols);
        } else {
            printf("new_matrix[0] es NULL\n");
            map->cols = 0;
        }
    } else {
        printf("new_matrix es NULL\n");
        map->cols = 0;
    }

    return (1);
}

