/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:25 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 10:59:29 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_game(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->mlx_win);
    ft_printfd(1, "Game closed successfully\n");
    exit(0);
    return (0);
}

int key_press(int keycode, t_vars *vars)
{
    if (keycode == 53)
        close_game(vars);
    else if (keycode == 13)
        move_player(vars, 0, -1);
    else if (keycode == 0)
        move_player(vars, -1, 0);
    else if (keycode == 1)
        move_player(vars, 0, 1);
    else if (keycode == 2)
        move_player(vars, 1, 0);
    return (0);
}

