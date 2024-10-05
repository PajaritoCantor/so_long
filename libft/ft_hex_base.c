/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 17:29:09 by jurodrig          #+#    #+#             */
/*   Updated: 2024/08/05 16:27:45 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_base(unsigned long p)
{
	int	result;
	int	hex;

	if (p == 0)
	{
		result = ft_putstr("(nil)");
		if (result == -1)
			return (-1);
		return (result);
	}
	result = ft_putstr("0x");
	if (result == -1)
		return (-1);
	hex = ft_putnbr_base(p, "0123456789abcdef", 0);
	if (hex == -1)
		return (-1);
	return (result + hex);
}
