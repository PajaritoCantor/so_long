/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:43:43 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 11:01:51 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_vars *vars, int x, int y, char tile)
{
	if (tile == '1')
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->wall_img, x, y);
	else if (tile == '0')
		(void)0;
	else if (tile == 'P')
		(void)0;
	else if (tile == 'E')
		(void)0;
	else if (tile == 'C')
		(void)0;
}
