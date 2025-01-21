/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:17:20 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/21 19:50:56 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_game *game)
{
	mlx_delete_texture(game->textures->wall_img);
	mlx_delete_texture(game->textures->background_img);
	mlx_delete_texture(game->textures->caracter_img);
	mlx_delete_texture(game->textures->player_img);
	mlx_delete_texture(game->textures->exit_img);
	free(game->textures);
}

void	load_textures(t_game *game)
{
	game->textures->wall_img = mlx_load_xpm42(WALL_TEXTURE);
	game->textures->background_img = mlx_load_xpm42(FLOOR_TEXTURE);
	game->textures->player_img = mlx_load_xpm42(PLAYER_TEXTURE);
	game->textures->caracter_img = mlx_load_xpm42(COLLECTIBLE_TEXTURE);
	game->textures->exit_img = mlx_load_xpm42(EXIT_TEXTURE);
	if (!game->textures->wall_img || !game->textures->background_img
		|| !game->textures->player_img || !game->textures->exit_img
		|| !game->textures->caracter_img)
		ft_printfd(1, ERROR_LOAD_TEXTURES);
}

void	check_textures_error(t_game *game)
{
	if (!game->textures->wall_img || !game->textures->background_img
		|| !game->textures->caracter_img || !game->textures->exit_img
		|| !game->textures->player_img)
		(free_textures(game), ft_printfd(1, ERROR_CONVERT_TEXTURES));
}

void	convert_textures(t_game *game)
{
	void	*temp;

	temp = game->textures->wall_img;
	game->textures->wall_img = mlx_texture_to_image(game->window->mlx,
			game->textures->wall_img);
	mlx_delete_xpm42(temp);
	temp = game->textures->background_img;
	game->textures->background_img = mlx_texture_to_image(game->window->mlx,
			game->textures->background_img);
	mlx_delete_xpm42(temp);
	temp = game->textures->exit_img;
	game->textures->exit_img = mlx_texture_to_image(game->window->mlx,
			game->textures->exit_img);
	mlx_delete_xpm42(temp);
	temp = game->textures->caracter_img;
	game->textures->caracter_img = mlx_texture_to_image(game->window->mlx,
			game->textures->caracter_img);
	mlx_delete_xpm42(temp);
	temp = game->textures->player_img;
	game->textures->player_img = mlx_texture_to_image(game->window->mlx,
			game->textures->player_img);
	mlx_delete_xpm42(temp);
	check_textures_error(game);
}
