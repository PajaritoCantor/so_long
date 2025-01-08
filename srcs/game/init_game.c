/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:07 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/08 00:50:03 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game)
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
}
void	free_game(t_game *game)
{
	if (!game)
		return ;
	close_window(game);
	free_textures(game);
	if (game->player)
	{
		free(game->player);
		game->player = NULL;
	}
	if (game->map)
	{
		free_map(game->map);
		game->map = NULL;
	}
	free(game);
	game = NULL;
}
void	close_handler(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	free_game(game);
	exit(0);
}
void	close_window(t_game *game)
{
	if (game->window)
	{
		if (game->window->mlx)
		{
			mlx_terminate(game->window->mlx);
			game->window->mlx = NULL;
		}
		free(game->window);
		game->window = NULL;
	}
}

void	init_game(t_game *game)
{
	int	width;
	int	height;

	width = game->map->cols * TILE_SIZE;
	height = game->map->rows * TILE_SIZE;
	game->window = ft_calloc(1, sizeof(t_window));
	if (!game->window)
		ft_error(ERROR_WINDOW, 1);
	mlx_set_setting(MLX_SETTINGS_MAX, true);
	game->window->mlx = mlx_init(width, height, "SO_LONG", true);
	if (!game->window->mlx)
		ft_error("Error inicializando la ventana", 1);
	game->textures = ft_calloc(1, sizeof(t_textures));
	if (!game->textures)
		ft_error("Error al asignar memoria para las texturas", 1);
	load_textures(game);
	convert_textures(game);
	game->player = ft_calloc(1, sizeof(t_position));
	if (!game->player)
		ft_error("Error al asignar memoria para el jugador", 1);
	load_map(game);
	render_map(game);
	if (!game->player)
		ft_error("Error al asignar memoria para el jugador", 1);
	mlx_key_hook(game->window->mlx, handle_keypress, game);
	mlx_close_hook(game->window->mlx, close_handler, game);
	mlx_loop(game->window->mlx);
}
