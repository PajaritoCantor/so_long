/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:02:32 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/18 15:05:46 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (!game || !game->textures)
		return ;
	if (game->textures->wall_img)
		mlx_delete_image(game->window->mlx, game->textures->wall_img);
	if (game->textures->background_img)
		mlx_delete_image(game->window->mlx, game->textures->background_img);
	if (game->textures->player_img)
		mlx_delete_image(game->window->mlx, game->textures->player_img);
	if (game->textures->enemy_img)
		mlx_delete_image(game->window->mlx, game->textures->enemy_img);
	if (game->textures->caracter_img)
		mlx_delete_image(game->window->mlx, game->textures->caracter_img);
	if (game->textures->exit_img)
		mlx_delete_image(game->window->mlx, game->textures->exit_img);
}
