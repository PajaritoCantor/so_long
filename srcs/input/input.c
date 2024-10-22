/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:50:25 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/21 14:13:28 by jurodrig         ###   ########.fr       */
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

void    move_player(t_vars *vars, int x_offset, int y_offset)
{
    int new_x;
    int new_y;

    new_x = vars->player_x + x_offset;
    new_y = vars->player_y + y_offset;
    if (vars->game->matrix[new_y][new_x] != '1')
    {
        vars->player_x = new_x;
        vars->player_y = new_y;
        render_game(vars, vars->game);
    }
    ft_printfd(2, "succesfull", 12);
    exit(1);
}