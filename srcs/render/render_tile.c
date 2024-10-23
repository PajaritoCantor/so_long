/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:43:43 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 10:28:36 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    render_tile(t_vars *vars, int x, int y, char tile)
{
    if (tile == '1')
        mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wall_img, x, y);
    else if (tile == '0')
}