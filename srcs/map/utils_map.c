/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:14:02 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/31 11:44:56 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game_map *cleanup(t_game_map *map, char **lines)
{
	ft_free_strs(lines);
	free_map(map);
	return (NULL);
}

void    free_matrix(char **matrix, int rows)
{
    while (--rows >= 0)
        free(matrix[rows]);
    free(matrix);
}

int	allocate_matrix(char ***matrix, int new_rows)
{
	*matrix = ft_calloc(new_rows + 1, sizeof(char *));
    return (*matrix != NULL);
}

int count_lines(char **lines)
{
    int count;

    count = 0;
    while (lines[count])
        count++;
    return (count);
}