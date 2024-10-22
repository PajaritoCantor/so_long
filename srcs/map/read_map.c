/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:28 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/22 15:57:57 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map	*init_map(void)
{
	t_game_map	*map;

	map = ft_calloc (1, sizeof(t_game_map));
	if (!map)
		return (NULL);
	ft_memset(map, 0, sizeof(t_game_map));
	return (map);
}

void	free_map(t_game_map *map)
{
	char	**matrix;
	int		rows;

	if (!map)
		return ;
	matrix = map->matrix;
	rows = map->rows;
	if (rows > 0)
	{
		free(matrix[--rows]);
	}
	free(matrix);
	free(map);
}

int	fill_matrix(t_game_map *map, char **lines)
{
	int		new_rows;
	char	**new_matrix;
	int		i;

	new_rows = 0;
	while (lines[new_rows] != NULL)
		new_rows++;
	new_matrix = malloc(sizeof(char *) * (new_rows + 1));
	if (!new_matrix)
		return (0);
	i = 0;
	while (i < new_rows)
	{
		new_matrix[i] = ft_strdup(lines[i]);
		i++;
	}
	new_matrix[new_rows] = NULL;
	free(map->matrix);
	map->matrix = new_matrix;
	map->rows = new_rows;
	return (1);
}

t_game_map	*read_map(char	*file_path)
{
	int			fd;
	char		*file_content;
	char		**lines;
	t_game_map	*map;

	map = init_map();
	if (!map)
		return (NULL);
	fd = open_file(file_path);
	if (fd < 0)
		return (free_map(map), NULL);
	file_content = read_file(fd);
	close(fd);
	if (!file_content)
		return (free_map(map), NULL);
	lines = ft_split(file_content, '\n');
	free(file_content);
	if (!lines)
		return (free_map(map), NULL);
	if (!fill_matrix(map, lines))
		return (free(lines), free_map(map), NULL);
	free(lines);
	if (!validate_map(map))
		return (free_map(map), NULL);
	return (map);
}
