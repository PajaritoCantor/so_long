/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:59:42 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/12 22:58:11 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	check_all_collectible(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->matrix[y][x] == 'C')
			{
				ft_printf("Coleccionable no recogido en (%d, %d)\n", x, y);
				return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}

bool	is_exit_reachable(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->matrix[y][x] == 'E')
			{
				printf("No se encuentra la salida (%d, %d)\n", x, y);
				return (false);
			}
			x++;
		}
		y++;
	}
	printf("Salida encontrada\n");
	return (true);
}
char	**copy_map_matrix(t_map *map)
{
	char	**copy;
	int		y;

	copy = ft_calloc(map->rows, sizeof(char *));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < map->rows)
	{
		copy[y] = ft_strdup(map->matrix[y]);
		if (!copy[y])
		{
			while (--y >= 0)
				(freedom(NULL, (void *)&copy[y]), free(copy));
		}
		y++;
	}
	return (copy);
}

bool	validate_path(t_map *map, int start_x, int start_y)
{
	t_map	map_copy;
	char	**matrix_copy;
	bool	valid;
	int		y;

	matrix_copy = copy_map_matrix(map);
	if (!matrix_copy)
		return (false);
	map_copy = *map;
	map_copy.matrix = matrix_copy;
	flood_fill(&map_copy, start_x, start_y);
	print_map(&map_copy);
	printf("check_all_collectible: %d\n", check_all_collectible(&map_copy));
	printf("is_exit_reachable: %d\n", is_exit_reachable(&map_copy));
	valid = (check_all_collectible(&map_copy) && is_exit_reachable(&map_copy));
	y = 0;
	while (y < map->rows)
		free(matrix_copy[y++]);
	free(matrix_copy);
	printf("valid: %d\n", valid);
	return (valid);
}
