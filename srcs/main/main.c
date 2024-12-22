/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:34:47 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/22 15:18:21 by jurodrig         ###   ########.fr       */
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
	t_game_map *map;

	if (ag != 2)
	{
		ft_error(USAGE, 1);
	}
	if (verificity_ber(av[1]))
		return (0);
	map = read_map(av[1]);
	if (!map)
	{
		ft_printfd(2, "Error: Failed to load map or map is invalid.\n");
		return (1);
	}
	print_map(map);
	free_map(map);
	return (0);
}