/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 11:41:11 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/21 19:52:56 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_vars *vars, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, WALL_TEXTURE, x, y);
}

void	init_game(t_vars *vars, t_game_map *game)
{
	int width_win;
	int height_win;

	vars->mlx = mlx_init();
	if (!vars->mlx)
		ft_printfd(2, "Error initialing MLX", 20);
	width_win = game->cols * TILE_SIZE;
	height_win = game->rows * TILE_SIZE;
	vars->mlx_win = mlx_new_window(vars->mlx, width_win, height_win, "so_long");
	if (!vars->mlx_win)
		ft_printfd(2, "Error creating window", 21);
	//render_map(vars, game);
}