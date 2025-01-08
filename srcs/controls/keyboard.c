/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:52:26 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/08 02:15:22 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_handler(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	end_game(game, "Game closed!");
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
void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_handler(game);
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_player(game, 0, -1);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_player(game, 0, 1);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_player(game, -1, 0);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_player(game, 1, 0);
	}
}
