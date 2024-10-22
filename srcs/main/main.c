/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 05:25:19 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/17 12:06:17 by jurodrig         ###   ########.fr       */
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


int main(int argc, char *argv[])
{
    t_vars vars;
    t_game_map  game;

    if (argc != 2 && check_ber(argv))
        ft_printfd(2, "Invalid numb of argcs");
    if (argc == 2 && !(check_ber(argv)))
        ft_printfd(2, "Invalide file");
    if (argc && check_ber(argv))
        {
            vars.game = &game;
            read_map(argv[1]);
            validate_map(&game);
            init_game(&vars, &game);
        }
}
