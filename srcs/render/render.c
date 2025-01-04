/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:27:21 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/04 14:20:49 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, char tile, int x, int y)
{
	mlx_image_t	*img;

	img = NULL;
	if (!game->window->mlx)
		ft_error("Error: MLX not initialized", 1);
	if (tile != '1' && tile != 'C' && tile != 'P' && tile != 'E' && tile != '0')
		ft_error("Error: invalid tile detected in map", 1);
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
	if (!img)
		ft_error("Error: Texture is NULL", 1);
	printf("Rendering Tile '%c' at (%d, %d) with dimensions %d x %d\n", tile, x,
		y, img->width, img->height);
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