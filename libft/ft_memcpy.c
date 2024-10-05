/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:29:13 by jurodrig          #+#    #+#             */
/*   Updated: 2024/07/14 00:33:26 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
/*
#include <stdio.h>
int main()
{
	int data [] = {1, 2, 3, 4, 5};
	size_t n;
	size_t i;
	size_t len;

	n = 3 * sizeof(int);

	ft_memcpy(data + 1, data, n);

	i = 0;
	len = sizeof(data)/sizeof(data[0]);
	while (i < len)
	{
		printf("%d ", data[i]);
		i++;
	}
	printf ("\n");
	
	return (0);
}
*/
