/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:28 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/25 02:21:38 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map	*init_map(void)
{
	t_game_map	*map;

	map = ft_calloc (1, sizeof(t_game_map));
	if (!map)
		return (NULL);
	map->matrix = NULL;
	map->rows = 0;
	map->cols = 0;
	map->num_players = 0;
	map->num_collectibles = 0;
	return (map);
}

void	free_map(t_game_map *map)
{
	int		rows;

	if (!map)
		return ;
	rows = map->rows;
	if (map->matrix)
	{
		while (rows > 0)
		{
			free(map->matrix[--rows]);
		}
		free(map->matrix);
	}
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
		if (!new_matrix[i])
		{
			while (--i >= 0)
				free(new_matrix[i]);
			free(new_matrix);
			return (0);
		}
		i++;
	}
	new_matrix[new_rows] = NULL;
	free(map->matrix);
	map->matrix = new_matrix;
	map->rows = new_rows;
	return (1);
}
// es una buena practica hacer que devuelva NULL porque asi en el otro lado puedes comprobar si funciono la funcion o no; con (!variable);
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
	file_content = get_next_line(fd);
	close(fd);
	if (!file_content)
		return (free_map(map), NULL);
	lines = ft_split(file_content, '\n');
	free(file_content);
	if (!lines)
		return (free_map(map), NULL);
	if (!fill_matrix(map, lines))
		return (ft_free_strs(lines), free_map(map), NULL);
	ft_free_strs(lines);
	if (!validate_map(map))
		return (free_map(map), NULL);
	return (map);
}
