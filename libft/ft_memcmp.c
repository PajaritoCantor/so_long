/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:00:03 by jurodrig          #+#    #+#             */
/*   Updated: 2024/07/09 13:25:48 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	return (0);
}
/*
int	main(void)
{
	const unsigned char	data1[] = {'H', 'o', 'l', 'o'};
	const unsigned char	dat2[] = {'H', 'o', 'l', 'a'};
	size_t				n1;

	n1 = 4;
	int result = ft_memcmp(data1, dat2, n1);
	printf("%d\n", result);


    // Ejemplo deos literales
    const unsigned char dat1[] = {0x01, 0xFF, 0xA3, 0x5C};
    const unsigned char data2[] = {0x01, 0xFF, 0xA3, 0x5D};
    size_t n2 = 4; // Número de bytes a comparar

    int result1 = ft_memcmp(dat1, data2, n2);
    printf("Resultado de ft_memcmp: %d\n", result1); 
	// Imprimir el resultado correctamente
    return 0;
}
*/
