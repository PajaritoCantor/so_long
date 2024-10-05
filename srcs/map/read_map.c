/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:12:58 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/05 17:58:38 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
