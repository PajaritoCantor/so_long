/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 01:37:07 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/30 22:33:20 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_rectangular(t_game_map *map)
{
    size_t expected_length;
    int row;

    expected_length = ft_strlen(map->matrix[0]);
    row = 0;
    while (row < map->rows)
    {
        if (ft_strlen(map->matrix[row]) != expected_length)
            return(0);
        row++;
    }
    return (1);
}

int check_valid_characters(t_game_map *map)
{
    int row;
    int col;
    char c;

    row = 0;
    while (row < map->rows)
    {
        if (!map->matrix[row])  // Verificación de punteros nulos
            return (0);

        col = 0;
        while (col < map->cols)
        {
            c = map->matrix[row][col];  // Línea 43
            if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
                return (0);
            col++;
        }
        row++;
    }
    return (1);
}

int is_map_surrounded_by_walls(t_game_map *map)
{
    if (map->rows <= 0 || map->cols <= 0 || !map->matrix)
        return (0);

    int col = 0;
    while (col < map->cols)
    {
        if (map->matrix[0][col] != '1' || map->matrix[map->rows - 1][col] != '1')
            return (0);
        col++;
    }
    int row = 0;
    while (row < map->rows)
    {
        if (map->matrix[row][0] != '1' || map->matrix[row][map->cols - 1] != '1')
            return (0);
        row++;
    }
    return (1);
}


int validate_map(t_game_map *map)
{
    if (!is_rectangular(map))
    {
        write(2, "Map error: not rectangular \n", 28);
        return (0);
    }
    if (!is_map_surrounded_by_walls(map))
    {
        write(2, "Map error: not surrounded by walls\n", 35);
        return (0);
    }
    if (!check_valid_characters(map))
    {
        write(2, "Map error: invalid characters or incorrect sets\n", 47);
        return (0);
    }
    return (1);
}