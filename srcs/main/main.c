/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:33:15 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 20:03:10 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_print_game(t_game_map  *map)
{
    int i;

    i = 0;
    while (i < map->rows)
    {
        ft_printf("%s\n", map->matrix[i]);
        i++;
    }
}
//ft_error in each error, AND SUCCESS to exit with success; CHECK if init_game fails;
int main(int argc, char **argv)
{
    t_vars vars;
    t_game_map *game;

    if (argc != 2)
        ft_error(USAGE, 1);
    if (!argv[1])
        ft_error(ERROR_MAP, 1);
    if (!check_ber(argv[1]))
        ft_error(ERROR_MAP, 1);
    game = NULL;
    game = read_map(argv[1]);
    if (!game)
        ft_error(ERROR_MAP_READ, 1);
    ft_print_game(game);
    if (!validate_map(game))
        free_map(game);
    if (!init_game(&vars, game))
    {
        free_map(game);
        ft_error(ERROR, 1);
    }
    mlx_loop(vars.mlx);
    free_map(game);
    ft_success(SUCCESS, 1);
}