/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:06:23 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/15 20:22:33 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_sprite_vertical(t_game *game, int dy)
{
	if (dy == -1)
		game->player->current_texture = game->textures->player_img;
	else if (dy == 1)
		game->player->current_texture = game->textures->player_img;
}

void	update_sprite_right(t_game *game)
{
	static int	right_frame = 0;

	right_frame++;
	if (right_frame == 1)
		game->player->current_texture = game->textures->player_img_right[0];
	else if (right_frame == 2)
	{
		game->player->current_texture = game->textures->player_img_right[1];
		right_frame = 0;
	}
	else
		game->player->current_texture = game->textures->player_img;
}

void	update_sprite_left(t_game *game)
{
	static int	left_frame = 0;

	left_frame++;
	if (left_frame == 1)
		game->player->current_texture = game->textures->player_img_left[0];
	else if (left_frame == 2)
	{
		game->player->current_texture = game->textures->player_img_left[1];
		left_frame = 0;
	}
	else
		game->player->current_texture = game->textures->player_img;
}
