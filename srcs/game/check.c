/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:25:19 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 19:43:00 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool   check_ber(char *argv)
{
    char    *save;

    save = ft_strrchr(argv, '.');
    if (save)
        return (ft_strncmp(save + 1, "ber", 3) == 0);
    return (0);
}

void	check_valid_map(t_game_map *game)
{
    validate_map(game);
    is_map_surrounded_by_walls(game);
    is_rectangular(game);
    is_map_surrounded_by_walls(game);
}