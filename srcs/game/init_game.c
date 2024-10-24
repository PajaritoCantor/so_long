/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:41:11 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 12:42:04 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int    init_game(t_vars *vars, t_game_map *game)
{
	int width_win;
	int height_win;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (ft_error(ERROR_MLX, 0));
	width_win = game->cols * TILE_SIZE;
	height_win = game->rows * TILE_SIZE;
	vars->mlx_win = mlx_new_window(vars->mlx, width_win, height_win, "so_long");
	if (!vars->mlx_win)
		return (ft_error(ERROR_WINDOW, 0));
	//render_map(vars, game);
	return (ft_success(SUCCESS, 0));
}