/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 01:17:20 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/08 00:37:10 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_textures(t_game *game)
{
    if (game->textures->wall_img)
        mlx_delete_texture(game->textures->wall_img);
    if (game->textures->background_img)
        mlx_delete_texture(game->textures->background_img);
    if (game->textures->caracter_img)
        mlx_delete_texture(game->textures->caracter_img);
    if (game->textures->player_img)
        mlx_delete_texture(game->textures->player_img);
    if (game->textures->exit_img)
        mlx_delete_texture(game->textures->exit_img);
    free(game->textures);
    game->textures = NULL;
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
	t_textures *textures = game->textures;

	textures->wall_img = mlx_texture_to_image(game->window->mlx, textures->wall_img);
	textures->background_img = mlx_texture_to_image(game->window->mlx, textures->background_img);
	textures->player_img = mlx_texture_to_image(game->window->mlx, textures->player_img);
	textures->caracter_img = mlx_texture_to_image(game->window->mlx, textures->caracter_img);
	textures->exit_img = mlx_texture_to_image(game->window->mlx, textures->exit_img);

	// Asegúrate de que no se pierda memoria intermedia
	if (!textures->wall_img || !textures->background_img
		|| !textures->player_img || !textures->caracter_img
		|| !textures->exit_img)
		ft_error("Error: Missing texture.", 1);
}