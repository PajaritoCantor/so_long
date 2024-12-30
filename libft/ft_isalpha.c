/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:42:59 by jurodrig          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:46 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	return ((97 <= i && i <= 122) || (65 <= i && i <= 90));
}
/*
int main (void)
{
	char c = 'A';
	printf("El carácter '%c' es alfabético: %d, 
	valor ASCII: %d\n", c, ft_isalpha(c), c);
	return (0);
}
*/
