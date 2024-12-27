/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:34:47 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/27 00:50:35 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_game_map *map)
{
	int	row;

	row = 0;
	while (row < map->rows)
	{
		if (map->matrix[row])
		{
			ft_putstr(map->matrix[row]);
			ft_putchar('\n');
		}
		else
			ft_printfd(2, "Error: Null row encountered in map.\n");
		row++;
	}
}
int	verificity_ber(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 4)
		return (1);
	return (ft_strncmp(file_name + len - 4, ".ber", 4));
}

int	main(int ag, char *av[])
{
	t_game_map	*map;
	t_window	*game;
	int			start_x;
	int			start_y;

	if (ag != 2)
		ft_error(USAGE, 1);
	if (verificity_ber(av[1]))
		return (0);
	map = read_map(av[1]);
	find_start_point(map, &start_x, &start_y);
	validate_path(map, start_x, start_y);
	game = ft_calloc(1, sizeof(t_game_map));
	init_game(game, map);
	print_map(map);
	free_map(map);
	return (0);
}
