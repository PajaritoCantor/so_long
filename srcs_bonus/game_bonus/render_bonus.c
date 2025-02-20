/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 21:09:25 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/21 18:47:25 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_player(t_game *game)
{
	if (mlx_image_to_window(game->window->mlx, game->player->current_texture,
			game->player->position_x * TILE_SIZE, game->player->position_y
			* TILE_SIZE) < 0)
		ft_error("Error: mlx_image_to_window failed.", 1);
}

void	render_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '1')
		mlx_image_to_window(game->window->mlx, game->textures->wall_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_image_to_window(game->window->mlx, game->textures->caracter_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->window->mlx, game->textures->exit_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'X')
		mlx_image_to_window(game->window->mlx, game->textures->enemy_img, x
			* TILE_SIZE, y * TILE_SIZE);
	else
		mlx_image_to_window(game->window->mlx, game->textures->background_img, x
			* TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	x;
	int	y;

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
	draw_player(game);
}
