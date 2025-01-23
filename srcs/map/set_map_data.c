/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:32:30 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/22 05:36:15 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char **lines)
{
	int	count;

	count = 0;
	while (lines[count])
		count++;
	return (count);
}

int	allocate_matrix(char ***map_matrix, int map_rows)
{
	if (map_rows <= 0)
	{
		ft_printf("Error: Map dimensions are invalid\n");
		return (0);
	}
	*map_matrix = ft_calloc(map_rows + 1, sizeof(char *));
	if (!*map_matrix)
	{
		ft_printf("Error: Memory allocation for matrix failed\n");
		return (0);
	}
	return (1);
}

int	copy_lines_to_matrix(char **map_matrix, char **lines, int map_rows)
{
	int	i;

	i = 0;
	while (i < map_rows)
	{
		map_matrix[i] = ft_strdup(lines[i]);
		if (!map_matrix[i])
		{
			ft_printf("Error: Memory allocation failed at row %d\n", i);
			free_matrix(map_matrix, i);
			return (0);
		}
		i++;
	}
	map_matrix[map_rows] = NULL;
	return (1);
}

int	set_map_data(t_map *map, char **lines)
{
	char	**map_matrix;
	int		map_rows;

	if (!lines || !lines[0])
	{
		ft_printf("Error: Invalid map data\n");
		return (0);
	}
	map_rows = count_lines(lines);
	if (!allocate_matrix(&map_matrix, map_rows))
		return (0);
	if (!copy_lines_to_matrix(map_matrix, lines, map_rows))
	{
		free(map_matrix);
		return (0);
	}
	free(map->matrix);
	map->matrix = map_matrix;
	map->rows = map_rows;
	map->cols = ft_strlen(lines[0]);
	return (1);
}
