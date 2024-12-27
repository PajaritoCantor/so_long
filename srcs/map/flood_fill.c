/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:05:59 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/27 12:50:52 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_start_point(t_game_map *map, int *start_x, int *start_y)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->matrix[y][x] == 'P')
			{
				*start_x = x;
				*start_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_error("Error: No se encontré el punto de inicio 'P.\n", 1);
}

void	flood_fill(t_game_map *map, int x, int y, char to_fill)
{
	if (x < 0 || x >= map->cols || y < 0 || y >= map->rows
		|| (map->matrix[y][x] != '0' && map->matrix[y][x] != 'C'
			&& map->matrix[y][x] != 'P') || map->matrix[y][x] == 'F')
		return ;
	map->matrix[y][x] = 'F';
	printf("Llenando celda: (%d, %d)\n", x, y);
	flood_fill(map, x - 1, y, to_fill);
	flood_fill(map, x + 1, y, to_fill);
	flood_fill(map, x, y - 1, to_fill);
	flood_fill(map, x, y + 1, to_fill);
}

void	start_flood_fill(t_game_map *map)
{
	int start_x;
	int start_y;

	// Encuentra el punto de inicio 'P'
	find_start_point(map, &start_x, &start_y);

	// Si el punto de inicio es válido, comienza el llenado por inundación
	if (map->matrix[start_y][start_x] == 'P')
		map->matrix[start_y][start_x] = 'F';

	// Realiza el llenado por inundación
	flood_fill(map, start_x, start_y, map->matrix[start_y][start_x]);
}