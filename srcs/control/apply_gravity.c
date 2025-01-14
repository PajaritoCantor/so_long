/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_gravity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 01:24:42 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/14 14:18:29 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	apply_gravity(t_game *game)
{
	t_position	*player;
	t_map		*map;
	int			new_y;

	player = game->player;
	map = game->map;
	if (!player->on_ground)
	// Actualizar posición vertical según velocidad
	{
		player->velocity_y += 1; // Aumentar velocidad por gravedad
		new_y = player->position_y + player->velocity_y;
		// Verificar colisión con el suelo
		if (new_y >= map->rows
			|| map->matrix[new_y][player->position_x] == WALL)
		{
			// Detener caída si colisiona con el suelo
			player->on_ground = 1;
			player->velocity_y = 0;
			player->position_y = new_y - 1;
		}
		else
		{
			player->position_y = new_y;
		}
	}
}
