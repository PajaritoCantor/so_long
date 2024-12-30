/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 15:52:26 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/30 12:31:27 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x_offset, int y_offset)
{
	static int	move_count;
	int			new_x;
	int			new_y;

	new_x = game->player_pos.player_x + x_offset;
	new_y = game->player_pos.player_y + y_offset;
	if (game->map.matrix[new_y][new_x] == '1')
		return ;
	if (game->map.matrix[new_y][new_x] == 'C')
	{
		game->map.num_collectibles--;
		game->map.matrix[new_y][new_x] = '0';
	}
	if (game->map.matrix[new_y][new_x] == 'E'
		&& game->map.num_collectibles == 0)
	{
		ft_printf("You win\n");
		exit_game(game);
	}
	game->player_pos.player_x = new_x;
	game->player_pos.player_y = new_y;
	render_map(game);
	move_count = 0;
	move_count++;
	ft_printf("movimientos: %d\n", move_count);
}
void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
		move_player(game, 0, -1);
	else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
		move_player(game, 0, 1);
	else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
		move_player(game, -1, 0);
	else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
		move_player(game, 1, 0);
	else if (keydata.key == MLX_KEY_ESCAPE)
		exit_game(game);
}
void	close_handler(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	exit_game(game);
	return ;
}
void	init_hook(t_game *game)
{
	mlx_key_hook(game->window.mlx_win, key_handler, game);
	mlx_loop_hook(game->window.mlx_win, close_handler, game);
}
void	exit_game(t_game *game)
{
	if (game == NULL)
		return ;
	if (game->textures)
		free(game);
	if (game->map.matrix)
		free(game);
	if (game->window.mlx)
		mlx_terminate(game->window.mlx);
	ft_printf("Well done!\n");
	exit(0);
}