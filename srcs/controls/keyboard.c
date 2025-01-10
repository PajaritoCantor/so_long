/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:52:26 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/09 23:18:04 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	detect_position(t_game *game, int x, int y)
{
	if (game->map->matrix[y][x] == COLLECTIBLE)
	{
		game->map->matrix[y][x] = EMPTY;
		game->player->collected++;
	}
	else if (game->map->matrix[y][x] == EXIT)
	{
		if (game->player->collected == game->map->num_collectibles)
			end_game(game, "You win!");
	}
	return ;
}

void	move_player(t_game *game, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = game->player->position_x + dx;
	new_y = game->player->position_y + dy;
	if (new_y >= 0 && new_y < game->map->rows && new_x >= 0
		&& new_x < game->map->cols && game->map->matrix[new_y][new_x] != WALL)
	{
		game->player->position_x = new_x;
		game->player->position_y = new_y;
		if (dy == -1)
			game->player->facing = UP;
		else if (dy == 1)
			game->player->facing = DOWN;
		else if (dx == -1)
			game->player->facing = LEFT;
		else if (dx == 1)
			game->player->facing = RIGHT;
		detect_position(game, new_x, new_y);
		render_map(game);
		printf("Player moved! New Position: (%d, %d)\n", new_x, new_y);
	}
	else
		printf("Invalid move: Wall or boundary!\n");
}

void	handle_keypress(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_handler(game);
	if (keydata.action == MLX_PRESS )
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
