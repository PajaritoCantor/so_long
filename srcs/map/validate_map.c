/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 01:37:07 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/22 15:58:24 by jurodrig         ###   ########.fr       */
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
    char    c;

    row = 0;
    col = 0;
    while (col < map->cols)
    {
        while (col < map->cols)
        {
            c = map->matrix[row][col];
            if (c != '#' && c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
                return (0);
            col++;
        }
        row++;
    }
    return (1);
}

int is_map_surrounded_by_walls(t_game_map *map)
{
    int col;

    col = 0;
    while (col < map->cols)
    {
        if (map->matrix[0][col] != '#')
            return (0);
        col++;
    }
    while (col < map->cols)
    {
        if (map->matrix[map->rows -1][col] != '#')
            return (0);
        col++;
    }
    return (1);
}

int validate_map(t_game_map *map)
{
    if (!is_rectangular(map))
    {
        write(2, "Map error: not rectangular\n", 26);
        return (0);
    }
    if (!is_map_surrounded_by_walls(map))
    {
        write(2, "Map error: not surrounded by walls\n", 34);
        return (0);
    }
    if (!check_valid_characters(map))
    {
        write(2, "Map error: invalid characters or incorrect sets", 47);
        return (0);
    }
    return (1);
}