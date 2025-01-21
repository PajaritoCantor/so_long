/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_characters_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:59:23 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/21 18:48:33 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_essential_characters(t_map *map, int *essentials)
{
	int	row;
	int	col;
	int	c;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			c = map->matrix[row][col];
			if (c == 'P')
				essentials[0]++;
			else if (c == 'E')
				essentials[1]++;
			else if (c == 'C')
				essentials[2]++;
			else if (c == 'X')
				essentials[3]++;
			col++;
		}
		row++;
	}
}

int	valid_essential_characters(t_map *map)
{
	int	essentials[4];

	essentials[0] = 0;
	essentials[1] = 0;
	essentials[2] = 0;
	essentials[3] = 0;
	count_essential_characters(map, essentials);
	return (essentials[0] == 1 && essentials[1] == 1 && essentials[2] > 0
		&& essentials[3] > 0);
}
