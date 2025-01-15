/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:52:26 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/15 20:04:32 by jurodrig         ###   ########.fr       */
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
	if (game->map->matrix[y][x] == ENEMY)
		end_game(game, "You lose!");
	else if (game->map->matrix[y][x] == EXIT)
	{
		if (game->player->collected == game->map->num_collectibles)
			end_game(game, "You win!");
		else
			mlx_image_to_window(game->window->mlx,
				game->textures->background_img, x * TILE_SIZE, y * TILE_SIZE);
	}
	return ;
}

void	render_player_path(t_game *game)
{
	int	prev_x;
	int	prev_y;
	int	new_x;
	int	new_y;

	prev_x = game->player->prev_position_x;
	prev_y = game->player->prev_position_y;
	new_x = game->player->position_x;
	new_y = game->player->position_y;
	if (game->map->matrix[prev_y][prev_x] == EXIT)
	{
		mlx_image_to_window(game->window->mlx, game->textures->exit_img, prev_x
			* TILE_SIZE, prev_y * TILE_SIZE);
	}
	else
	{
		mlx_image_to_window(game->window->mlx, game->textures->background_img,
			prev_x * TILE_SIZE, prev_y * TILE_SIZE);
	}
	mlx_image_to_window(game->window->mlx, game->player->current_texture, new_x
		* TILE_SIZE, new_y * TILE_SIZE);
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
		game->player->prev_position_x = game->player->position_x;
		game->player->prev_position_y = game->player->position_y;
		game->player->position_x = new_x;
		game->player->position_y = new_y;
		if (dx == -1)
			update_sprite_left(game);
		else if (dx == 1)
			update_sprite_right(game);
		else if (dy == -1 || dy == 1)
			update_sprite_vertical(game, dy);
		game->player->moves++;
		ft_printf("Moves: %d\n", game->player->moves);
		detect_position(game, new_x, new_y);
		render_player_path(game);
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
