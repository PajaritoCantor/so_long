/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:42:59 by jurodrig          #+#    #+#             */
/*   Updated: 2024/06/15 18:54:09 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	return (('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z'));
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
