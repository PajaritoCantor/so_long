/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:25:19 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/30 20:59:20 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool   check_ber(char *argv)
{
    char    *save;

    save = ft_strrchr(argv, '.');
    if (save)
        return (ft_strncmp(save, "ber", 4) == 0);
    return (0);
}

void	check_valid_map(t_game_map *game)
{
    validate_map(game);
    is_map_surrounded_by_walls(game);
    is_rectangular(game);
    is_map_surrounded_by_walls(game);
}

int verificity_ber(char *file_name)
{
    size_t  len;

    len = ft_strlen(file_name);
    if (len < 4)
        return (0);
    if (ft_strncmp(file_name + len - 4, ".ber", 4) == 0)
        return (1);
    return (0);
}