/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 20:38:08 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/04 23:18:20 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int open_file(char *file_path)
{
    int fd;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return -1;
    }
    return (fd);
}