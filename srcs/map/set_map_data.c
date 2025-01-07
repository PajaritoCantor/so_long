/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:32:30 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/06 22:23:41 by jurodrig         ###   ########.fr       */
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
		ft_printf("Error: invalid number of rows: %d\n", map_rows);
		return (0);
	}
	*map_matrix = ft_calloc(map_rows + 1, sizeof(char *));
	return (*map_matrix != NULL);
}
int	allocate_lines(char ***map_matrix, char **lines, int *map_rows)
{
	*map_rows = count_lines(lines);
	if (!allocate_matrix(map_matrix, *map_rows))
		return (0);
	return (1);
}
int	copy_lines_to_matrix(char **map_matrix, char **lines, int map_rows,
		t_map *map)
{
	int	i;

	i = 0;
	while (i < map_rows)
	{
		map_matrix[i] = ft_strdup(lines[i]);
		if (!map_matrix[i])
		{
			ft_printf("duplicate_lines: failed at row %d\n", i);
			free_matrix(map_matrix, i);
			free(map->matrix);
			return (0);
		}
		i++;
	}
	return (1);
}
int	set_map_data(t_map *map, char **lines)
{
	char **map_matrix;
	int map_rows;

	if (!lines || !lines[0])
		return (0);
	if (!allocate_lines(&map_matrix, lines, &map_rows))
		ft_error("Error, Memory allocation failed\n", 1);
	if (!copy_lines_to_matrix(map_matrix, lines, map_rows, map))
		return (0);
	map_matrix[map_rows] = NULL;
	free(map->matrix);
	map->matrix = map_matrix;
	map->rows = map_rows;
	if (map_matrix[0] != NULL)
		map->cols = ft_strlen(map_matrix[0]);
	else
		map->cols = 0;
	return (1);
}