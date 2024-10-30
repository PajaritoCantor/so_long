/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:33:15 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/30 21:07:15 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_map(t_game_map *map)
{
    int row;

    row = 0;
    while (row < map->rows)
    {
        ft_putstr(map->matrix[row]);
        ft_putchar('\n');
        row++;
    }
}

int main(int argc, char *argv[])
{
    t_game_map  *map;

    if (argc != 2)
    {
        ft_printfd(2, "Error\n Not valid arguments\n", 29);
        return (1);
    }
    if (!verificity_ber(argv[1]))
    {
        ft_printfd(2, "Error\n Not valid extension\n", 28);
        return (1);
    }
    map = init_map();  // Llamada a la función init_map y asignación del valor retornado
    if (!map)
    {
       ft_printfd(2, "Error\n Failed to initialize map\n", 34);
        return (1);
    }
    if (!read_map(argv[1]))
    {
        ft_printfd(2, "Error\n Reading map failed\n", 28);
        free_map(map);  // Asegúrate de liberar la memoria asignada
        return (1);
    }
    print_map(map);
    free_map(map);
    return (0);
}
