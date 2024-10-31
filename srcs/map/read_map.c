/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:28 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/31 11:50:54 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map	*init_map(void)
{
	t_game_map	*map;

	map = ft_calloc (1, sizeof(t_game_map));
	if (!map)
		return (NULL);
	printf("init_map: map created\n");
	map->matrix = NULL;
	map->rows = 0;
	map->cols = 0;
	map->num_players = 0;
	map->num_collectibles = 0;
	return (map);
}

void	free_map(t_game_map *map)
{
	if (!map)
		return ;
	if (map->matrix)
		free_matrix(map->matrix, map->rows);
    printf("free_map: freeing map\n");
	free(map);
}

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

// es una buena practica hacer que devuelva NULL porque asi en el otro lado puedes comprobar si funciono la funcion o no; con (!variable);
char    *read_all_lines(char *file_path)
{
    int     fd;
    char    *file_content;
    char    *line;
    char    *temp;

    file_content = ft_strdup("");
    fd = open_file(file_path);
    if (fd < 0 || !file_content)
        return (NULL);
    while ((line = get_next_line(fd)))
    {
        temp = file_content;
        file_content = ft_strjoin(file_content, line);
        free(temp);
        free(line);
        if (!file_content)
    	{
		close(fd);
		return (NULL);
		}
	}
	close(fd);
	return (file_content);
}

t_game_map *read_map(char *file_path)
{
    t_game_map *map;
    char *content;
    char **lines;

    map = init_map();
    if (!map) 
    {
        printf("read_map: init_map failed\n");
        return (NULL);
    }
    printf("read_map: init_map successful\n");
    content = read_all_lines(file_path);
    if (!content) 
    {
        printf("read_map: read_all_lines failed\n");
        free_map(map);
        return (NULL);
    }
    printf("read_map: read_all_lines successful\n");
    lines = ft_split(content, '\n');
    free(content);
    if (!lines) 
    {
        printf("read_map: ft_split failed\n");
        free_map(map);
        return (NULL);
    }
    printf("read_map: ft_split successful\n");
    if (!set_map_data(map, lines)) {
        printf("read_map: set_map_data failed\n");
        ft_free_strs(lines);
        free_map(map);
        return (NULL);
    }
    printf("read_map: set_map_data successful\n");
    ft_free_strs(lines);
    printf("read_map: completed successful\n");
    return (map);
}