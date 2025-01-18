/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:34:47 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/18 22:48:52 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_map *map)
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
	if (len <= 4)
		return (1);
	return (ft_strncmp(file_name + len - 4, ".ber", 4) != 0 || file_name[len
			- 5] == '/');
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	t_game	*game;

	if (argc != 2)
		return (ft_error(USAGE, 1));
	if (verificity_ber(argv[1]))
		return (ft_error(USAGE, 1));
	map = read_map(argv[1]);
	if (!map)
		return (ft_printfd(1, ERROR_MAP));
	if (!find_start_point(map))
		return (free_map(map), ft_printfd(1, ERROR_START_POINT));
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_printfd(1, ERROR_MEMORY_ALLOCATION));
	game->map = map;
	init_game(game);
	render_map(game);
	mlx_close_hook(game->window->mlx, close_handler, game);
	mlx_loop(game->window->mlx);
	end_game(game, NULL);
	return (1);
}
