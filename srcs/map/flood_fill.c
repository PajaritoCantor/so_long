/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 23:05:59 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/15 19:53:40 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	find_start_point(t_map *map)
{
	int	start_x;
	int	start_y;
	int	y;
	int	x;

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
	ft_error(ERROR_START_POINT, 1);
	return (true);
}

void	flood_fill(t_map *map, int x, int y)
{
	if (map->matrix[y][x] == '1' || map->matrix[y][x] == 'F'
		|| map->matrix[y][x] == 'X')
		return ;
	map->matrix[y][x] = 'F';
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
}
