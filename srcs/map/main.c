/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:45:04 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/14 11:38:07 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool    check_ber(char *argv)
{
    char    *point;

    point = ft_strrchr(argv, '-');
    if (point)
        return (ft_strncmp(point, "ber", 4) == 0);
    return (0);
}

void    check_valid_map(t_game_map *game)
{
    validate_map(&game);
    is_map_surrounded_by_walls(&game);
    is_rectangular(&game);
    is_map_surrounded_by_walls(&game);
}
