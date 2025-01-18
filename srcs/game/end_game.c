/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:20:27 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/18 15:05:25 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	end_free_map(t_map *map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (y < map->rows)
	{
		free(map->matrix[y]);
		y++;
	}
	free(map->matrix);
	free(map);
}

static void	end_free_textures(t_game *game)
{
	if (!game->textures)
		return ;
	free_images(game);
	free(game->textures);
}

static void	end_free_window(t_window *window)
{
	if (!window)
		return ;
	if (window->mlx)
	{
		mlx_close_window(window->mlx);
		mlx_terminate(window->mlx);
	}
	free(window);
}

static void	end_free_player(t_position *player)
{
	if (!player)
		return ;
	free(player);
}

void	end_game(t_game *game, const char *message)
{
	if (message)
		ft_printf("%s\n", message);
	if (game)
	{
		end_free_map(game->map);
		end_free_textures(game);
		end_free_window(game->window);
		end_free_player(game->player);
		free(game);
	}
	exit(EXIT_SUCCESS);
}
