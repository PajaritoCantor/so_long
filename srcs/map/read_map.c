/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:08:36 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/22 22:40:49 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*init_map(void)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	return (map);
}

char	*read_all_lines(char *file_path)
{
	int		fd;
	char	*file_content;
	char	*line;
	char	*temp;

	file_content = ft_strdup("");
	fd = open_file(file_path);
	while (file_content)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 0 || line[0] == '\n')
		{
			(freedom(NULL, (void *)&line), free(file_content));
			return (NULL);
		}
		temp = file_content;
		file_content = ft_strjoin(file_content, line);
		(freedom(NULL, (void *)&line), free(temp));
		if (!file_content)
			return (close(fd), NULL);
	}
	return (close(fd), file_content);
}

t_map	*initialize_map_with_validation(char *file_path, char ***lines)
{
	t_map	*map;
	char	*content;

	map = init_map();
	if (!map)
		return (NULL);
	content = read_all_lines(file_path);
	if (!content)
		return (free_map(map), NULL);
	*lines = ft_split(content, '\n');
	free(content);
	if (!*lines)
		return (free_map(map), NULL);
	return (map);
}

int	validate_map_dimensions(char **lines, int *rows, int *cols)
{
	*rows = count_lines(lines);
	if (lines[0])
		*cols = ft_strlen(lines[0]);
	if (*rows * *cols > MAX_MAP_AREA)
	{
		ft_printf("Error: Map area exceeds the maximum allowed (%d)\n",
			MAX_MAP_AREA);
		return (0);
	}
	return (1);
}

t_map	*read_map(char *file_path)
{
	t_map	*map;
	char	**lines;
	int		rows;
	int		cols;

	lines = NULL;
	rows = 0;
	cols = 0;
	map = initialize_map_with_validation(file_path, &lines);
	if (!map)
		return (NULL);
	if (!validate_map_dimensions(lines, &rows, &cols))
		return (ft_free_strs(lines), free_map(map), NULL);
	if (!set_map_data(map, lines))
		return (ft_free_strs(lines), free_map(map), NULL);
	if (!validate_map(map))
		return (ft_free_strs(lines), free_map(map), NULL);
	ft_free_strs(lines);
	return (map);
}
