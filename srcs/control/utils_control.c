/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 17:06:23 by jurodrig          #+#    #+#             */
/*   Updated: 2025/01/10 17:23:27 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_moves(t_game *game)
{
	char	*moves_text;

	moves_text = ft_itoa(game->player->moves);
	mlx_put_string(game->window->mlx, moves_text, 10, 10);
	free(moves_text);
}