/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:09:20 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/02 21:43:38 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stdio.h> // perror
#include <stdlib.h> // malloc, free
#include <string.h> // strlen
#include <unistd.h> // close
#include <fcntl.h> // open  

# define BUFFER_SIZE 4096
// Definición tamaño del Buffer para lectura de archivos

typedef struct s_map
{
    char    **matrix; 
    int     cols;
    int     rows;
    int     num_players;
    int     num_exits;
    int     num_collectibles;
} t_game_map;

#endif