/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:52:26 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/08 00:55:43 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game, const char *message)
{
	int	y;

	ft_printf("%s\n", message);
	if (game->map)
	{
		y = 0;
		while (y < game->map->rows)
		{
			free(game->map->matrix[y]);
			y++;
		}
		free(game->map->matrix);
		free(game->map);
	}
	free_textures(game);
	if (game->window)
	{
		if (game->window->mlx)
			mlx_close_window(game->window->mlx);
		free(game->window);
	}
	if (game->player)
		free(game->player);
	exit(EXIT_SUCCESS);
}

void	move_up(t_game *game)
{
	if (game->player->position_y > 0
		&& game->map->matrix[game->player->position_y
		- 1][game->player->position_x] != WALL)
	{
		game->player->position_y--;
		game->player->facing = UP;
		if (game->map->matrix[game->player->position_y][game->player->position_x] == COLLECTIBLE)
		{
			game->map->matrix[game->player->position_y][game->player->position_x] = EMPTY;
			game->player->collected++;
		}
		else if (game->map->matrix[game->player->position_y][game->player->position_x] == EMPTY
			&& game->player->collected == game->map->num_collectibles)
		{
			end_game(game);
			return ;
		}
		printf("Player moved up! New Position: (%d, %d)\n",
			game->player->position_x, game->player->position_y);
		render_map(game);
	}
}
void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_handler(game);
	// Si la tecla no está presionada, no hace nada
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		{
			printf("Moving up! (W or UP arrow)\n");
			move_up(game);
		}
		// else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		//	move_player(game, DOWN);
		// else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		//	move_player(game, LEFT);
		// else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		//	move_player(game, RIGHT);
	}
}
