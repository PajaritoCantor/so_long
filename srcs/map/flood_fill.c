/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:05:59 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/12 22:45:44 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	find_start_point(t_map *map)
{
	int	start_x;
	int	start_y;
	int	y;
	int	x;

	{
		if (!map || !map->matrix)
		{
			ft_error("Error: Mapa no inicializado.\n", 1);
			return (false);
		}
	}
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->matrix[y][x] == 'P')
			{
				start_x = x;
				start_y = y;
				return (validate_path(map, start_x, start_y));
			}
			x++;
		}
		y++;
	}
	ft_error("Error: No se encontré el punto de inicio 'P.\n", 1);
	return (true);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (map->matrix[y][x] == '1' || map->matrix[y][x] == 'F'
		|| map->matrix[y][x] == 'X')
	{
		printf("[%d, %d]\n", x, y);
		return ;
	}
	map->matrix[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}
