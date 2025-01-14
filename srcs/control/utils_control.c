/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:06:23 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/14 19:23:26 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*moves_text;

	moves_text = ft_itoa(game->player->moves);
	mlx_put_string(game->window->mlx, moves_text, 10, 10);
	free(moves_text);
}

void	update_sprite_vertical(t_game *game, int dy)
{
	if (dy == -1)
		game->player->current_texture = game->textures->player_img;
	else if (dy == 1)
		game->player->current_texture = game->textures->player_img;
}

void	update_sprite_right(t_game *game)
{
	static int	right_frame;

	right_frame++;
	if (right_frame == 1)
		game->player->current_texture = game->textures->player_img_right[0];
	else if (right_frame == 2)
		game->player->current_texture = game->textures->player_img_right[1];
	else
	{
		game->player->current_texture = game->textures->player_img;
		right_frame = 0;
	}
}

void	update_sprite_left(t_game *game)
{
	static int	left_frame;

	left_frame++;
	if (left_frame == 1)
		game->player->current_texture = game->textures->player_img_left[0];
	else if (left_frame == 2)
		game->player->current_texture = game->textures->player_img_left[1];
	else
	{
		game->player->current_texture = game->textures->player_img;
		left_frame = 0;
	}
}
