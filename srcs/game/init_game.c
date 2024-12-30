/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:07 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/30 16:35:43 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	load_textures(t_game *game)
{
	game->textures->wall_img = mlx_load_xpm42(WALL_TEXTURE);
	game->textures->background_img = mlx_load_xpm42(FLOOR_TEXTURE);
	game->textures->player_img = mlx_load_xpm42(PLAYER_TEXTURE);
	game->textures->caracter_img = mlx_load_xpm42(COLLECTIBLE_TEXTURE);
	game->textures->exit_img = mlx_load_xpm42(EXIT_TEXTURE);
	if (!game->textures->wall_img || !game->textures->background_img
		|| !game->textures->player_img || !game->textures->exit_img
		|| !game->textures->caracter_img)
	{
		ft_error("Error al cargar una o más texturas", 1);
	}
}
*/
/*
void	init_game(t_game *game, char *file_path)
{
	t_map	*map;
	int		width_win;
	int		height_win;

	if (!map)
		ft_error("Invalid window or game pointer", 1);
	game->map.matrix = read_map(file_p);
	if (!game->map.matrix)
		ft_error("failed to init map matrix.", 1);
	game->map.rows = 
	width_win = game->map.cols * TILE_SIZE;
	height_win = game->map.rows * TILE_SIZE;
	game->window.mlx = mlx_init(width_win, height_win, "SO_LONG", true);
	if (!game->window.mlx)
		ft_error(ERROR_MLX, 1);
	load_textures(game);
	mlx_close_hook(game->window.mlx, (mlx_closefunc)close_window, game);
	mlx_key_hook(game->window.mlx, (mlx_keyfunc)key_handler, game);
	mlx_loop(game->window.mlx);
}
*/

static	void	create_window(t_game *game)
{
	game->window->mlx = mlx_
}
/*void	close_window(t_game *game)
{
	if (game->window.mlx) MLX_HEADLESS
	{
		if (game->window.mlx_win)
			mlx_terminate(game->window.mlx);
		free(game->window.mlx);
	}
	if (game->textures->wall_img)
		mlx_delete_image(game->window.mlx, game->textures->wall_img);
	if (game->textures->background_img)
		mlx_delete_image(game->window.mlx, game->textures->background_img);
	if (game->textures->player_img)
		mlx_delete_image(game->window.mlx, game->textures->player_img);
	if (game->textures->exit_img)
		mlx_delete_image(game->window.mlx, game->textures->exit_img);
	if (game->textures->caracter_img)
		mlx_delete_image(game->window.mlx, game->textures->caracter_img);
}
*/