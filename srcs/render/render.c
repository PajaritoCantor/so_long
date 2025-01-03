/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:27:21 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/31 01:29:59 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, char tile, int x, int y)
{
	void	*img;

	if (tile == '1')
		img = game->textures->wall_img;
	else if (tile == 'C')
		img = game->textures->caracter_img;
	else if (tile == 'P')
		img = game->textures->player_img;
	else if (tile == 'E')
		img = game->textures->exit_img;
	else
		img = game->textures->background_img;
	mlx_image_to_window(game->window->mlx, img, x * TILE_SIZE, y * TILE_SIZE);
}
void	render_map(t_game *game)
{
	int x;
	int y;

	y = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			render_tile(game, game->map->matrix[y][x], x, y);
			x++;
		}
		y++;
	}
}