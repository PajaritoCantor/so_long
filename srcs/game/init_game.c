/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:07 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/26 16:16:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_window *window, t_game_map *game)
{
	int width_win;
	int height_win;

	width_win = game->cols * TILE_SIZE;
	height_win = game->rows * TILE_SIZE;
	window->mlx = mlx_init(width_win, height_win, "SO_LONG", true);
	if (!window->mlx)
	{
		ft_error(ERROR_MLX, 1);
		return ;
	}
	mlx_loop(window->mlx);
	if (!window->mlx)
	{
		ft_error(ERROR_WINDOW, 1);
		return ;
	}
	return ;
}