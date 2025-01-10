/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:17:20 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/10 02:54:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->textures->wall_img)
		mlx_delete_image(game->window->mlx, game->textures->wall_img);
	if (game->textures->background_img)
		mlx_delete_image(game->window->mlx, game->textures->background_img);
	if (game->textures->player_img)
		mlx_delete_image(game->window->mlx, game->textures->player_img);
	if (game->textures->caracter_img)
		mlx_delete_image(game->window->mlx, game->textures->caracter_img);
	if (game->textures->exit_img)
		mlx_delete_image(game->window->mlx, game->textures->exit_img);
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
		ft_error("Error: Una o más texturas no se pudieron cargar.", 1);
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
	temp = game->textures->player_img;
	game->textures->player_img = mlx_texture_to_image(game->window->mlx,
			game->textures->player_img);
	mlx_delete_xpm42(temp);
	temp = game->textures->caracter_img;
	game->textures->caracter_img = mlx_texture_to_image(game->window->mlx,
			game->textures->caracter_img);
	mlx_delete_xpm42(temp);
	temp = game->textures->exit_img;
	game->textures->exit_img = mlx_texture_to_image(game->window->mlx,
			game->textures->exit_img);
	mlx_delete_xpm42(temp);
	if (!game->textures->wall_img || !game->textures->background_img
		|| !game->textures->player_img || !game->textures->caracter_img
		|| !game->textures->exit_img)
		(free_textures(game), ft_error("Error: Missing texture.", 1));
}
