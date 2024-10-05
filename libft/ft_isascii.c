/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 17:54:28 by jurodrig          #+#    #+#             */
/*   Updated: 2024/06/15 18:52:26 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int i)
{
	return (i >= 0 && i <= 127);
}
/*
#include <stdio.h>

int main (void)
{
	int c = 125;

	printf("%d\n", ft_isascii(c));
	
	if (c >=32 && c <= 126)
	{
		printf("%c\n", c);
	}
	else
	{
		printf("No es imprimible visible en ASCII\n");
	}
}
*/
