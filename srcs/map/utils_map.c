/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 01:01:29 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/30 09:45:29 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}
void	freedom(void **p, void **p2)
{
	if (p && *p)
	{
		free(*p);
		*p = NULL;
	}
	if (p2 && *p2)
	{
		free(*p2);
		*p2 = NULL;
	}
}
void	free_matrix(char **matrix, int rows)
{
	while (--rows >= 0)
		free(matrix[rows]);
	free(matrix);
}
void	free_p2(char **matrix)
{
	int	rows;

	rows = -1;
	while (matrix[++rows])
		free(matrix[rows]);
	free(matrix);
}
void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_matrix(map->matrix, map->rows);
	free(map);
}