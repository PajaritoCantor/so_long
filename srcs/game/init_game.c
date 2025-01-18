/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:07 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/18 14:45:49 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_player_and_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->map->num_collectibles = 0;
	while (y < game->map->rows)
	{
		x = 0;
		while (x < game->map->cols)
		{
			if (game->map->matrix[y][x] == PLAYER)
			{
				game->player->position_x = x;
				game->player->position_y = y;
			}
			else if (game->map->matrix[y][x] == COLLECTIBLE)
				game->map->num_collectibles++;
			x++;
		}
		y++;
	}
	game->player->moves = 0;
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	width = game->map->cols * TILE_SIZE;
	height = game->map->rows * TILE_SIZE;
	game->window = ft_calloc(1, sizeof(t_window));
	if (!game->window)
		end_game(game, ERROR_WINDOW);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	game->window->mlx = mlx_init(width, height, "SO_LONG", true);
	if (!game->window->mlx)
		end_game(game, ERROR_MLX);
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		end_game(game, ERROR_MEMORY_ALLOCATION);
	load_textures(game);
	convert_textures(game);
	game->player = ft_calloc(1, sizeof(t_position));
	if (!game->player)
		end_game(game, ERROR_MEMORY_ALLOCATION);
	game->player->current_texture = game->textures->player_img;
	if (!game->player->current_texture)
		end_game(game, ERROR_ASSIGN_TEXTURES);
	search_player_and_collectibles(game);
	mlx_key_hook(game->window->mlx, handle_keypress, game);
}
