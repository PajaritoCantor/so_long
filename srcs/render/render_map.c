/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:19:09 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 09:02:06 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_map(t_vars *vars, t_game_map *game)
{
    int x;
    int y;

    y = 0;
    while (y < game->rows)
    {
        x = 0;
        while (x < game->cols)
        {
            render_tile(vars, game->matrix[y][x], x, y);
            x++;
        }
        y++;
    }
}