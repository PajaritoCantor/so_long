/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 01:59:42 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/27 12:32:03 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

bool	check_all_collectible(t_game_map *map)
{
	int	x;
	int	y;

	// Recorremos todas las filas
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		// Recorremos todas las columnas de cada fila
		while (x < map->cols)
		{
			// Si encontramos un coleccionable 'C', devolvemos false
			if (map->matrix[y][x] == 'C')
			{
				printf("Coleccionable no recogido en (%d, %d)\n", x, y);
				return (false); // no todos han sido recogidos
			}
			x++;
		}
		y++;
	}
	// Si no hay más coleccionables, todos han sido recogidos
	printf("Todos los coleccionables han sido recogidos.\n");
	return (true);
}
bool	is_exit_reachable(t_game_map *map)
{
	int	x;
	int	y;

	// Recorremos todas las filas
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		// Recorremos todas las columnas de cada fila
		while (x < map->cols)
		{
			// Si encontramos la salida 'E', devolvemos true
			if (map->matrix[y][x] == 'E')
			{
				printf("La salida se encuentra en (%d, %d)\n", x, y);
				return (true); // Si encontramos la salida, está alcanzable
			}
			x++;
		}
		y++;
	}
	// Si no encontramos la salida en todo el mapa
	printf("No se encuentra la salida.\n");
	return (false); // Si no encontramos la salida, no está alcanzable
}
char	**copy_map_matrix(t_game_map *map)
{
	char	**copy;
	int		y;
	int		x;

	y = 0;
	copy = ft_calloc(map->rows, sizeof(char *));
	if (!copy)
		return (NULL);
	while (y < map->rows)
	{
		copy[y] = ft_calloc(map->cols + 1, sizeof(char));
		if (!copy[y])
		{
			while (--y >= 0)
				(freedom(NULL, (void *)&copy[y]), free(copy));
		}
		x = 0;
		while (x < map->cols)
		{
			copy[y][x] = map->matrix[y][x];
			x++;
		}
		copy[y][x] = '\0';
		y++;
	}
	return (copy);
}
bool	validate_path(t_game_map *map, int start_x, int start_y)
{
	t_game_map	map_copy;
	char		**matrix_copy;
	bool		valid;
	int			y;

	matrix_copy = copy_map_matrix(map);
	if (!matrix_copy)
		return (false);
	map_copy = *map;
	map_copy.matrix = matrix_copy;
	flood_fill(&map_copy, start_x, start_y, map->matrix[start_y][start_x]);
	valid = check_all_collectible(&map_copy) && is_exit_reachable(&map_copy);
	y = 0;
	while (y < map->rows)
		free(matrix_copy[y++]);
	free(matrix_copy);
	return (valid);
}
