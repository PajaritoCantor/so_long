/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:28 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/28 18:37:20 by jurodrig         ###   ########.fr       */
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
	if (!set_map_data(map, lines))
		return (ft_free_strs(lines), free_map(map), NULL);
	ft_free_strs(lines);
	if (!validate_map(map))
		return (free_map(map), NULL);
	return (map);
}
