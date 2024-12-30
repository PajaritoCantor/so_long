/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:27:21 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/30 12:53:07 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			render_tile(game, game->map.matrix[y][x], x, y);
			x++;
		}
		y++;
	}
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	int pixel_x;
	int pixel_y;
	mlx_image_t *image;

	pixel_x = x * TILE_SIZE;
	pixel_y = y * TILE_SIZE;
	image = NULL;
	if (tile == '1')
		image = game->textures->wall_img;
	else if (tile == '0')
		image = game->textures->background_img;
	else if (tile == 'P')
		image = game->textures->player_img;
	else if (tile == 'E')
		image = game->textures->exit_img;
	else if (tile == 'C')
		image = game->textures->caracter_img;
	if (image)
	{
		if (mlx_image_to_window(game->window.mlx, image, pixel_x, pixel_y) < 0)
		{
			ft_printf("Error al renderizar tile en (%d, %d)\n", x, y);
		}
	}
}