/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 00:08:36 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/10 17:59:35 by jurodrig         ###   ########.fr       */
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
	if (fd < 0 || !file_content)
		return (NULL);
	while (file_content)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = file_content;
		file_content = ft_strjoin(file_content, line);
		(freedom(NULL, (void *)&line), free(temp));
		if (!file_content)
			return (close(fd), NULL);
	}
	return (close(fd), file_content);
}

t_map	*read_map(char *file_path)
{
	t_map	*map;
	char	*content;
	char	**lines;

	map = init_map();
	if (!map)
		return (NULL);
	content = read_all_lines(file_path);
	if (!content)
		return (free_map(map), NULL);
	lines = ft_split(content, '\n');
	free(content);
	if (!lines)
		return (free_map(map), NULL);
	if (!set_map_data(map, lines))
		return (ft_free_strs(lines), free_map(map), NULL);
	if (!validate_map(map))
		return (ft_free_strs(lines), free_map(map), NULL);
	ft_free_strs(lines);
	return (map);
}
