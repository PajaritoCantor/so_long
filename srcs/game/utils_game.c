/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:20:27 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/10 15:38:41 by jurodrig         ###   ########.fr       */
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
	free_images(game);
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

void	close_handler(void *param)
{
	t_game *game;

	game = (t_game *)param;
	end_game(game, "Game closed!");
}
