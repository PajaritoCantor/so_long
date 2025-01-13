/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:07 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/13 18:17:09 by jurodrig         ###   ########.fr       */
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
		ft_error(ERROR_WINDOW, 1);
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
	//search_player_and_collectibles(game);
	render_map(game);
	if (!game->player)
		ft_error("Error al asignar memoria para el jugador", 1);
}
