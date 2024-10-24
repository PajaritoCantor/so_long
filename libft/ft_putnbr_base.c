/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 23:27:30 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 18:31:27 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(int fd, unsigned long nbr, char *b)
{
	long int	number;
	static int	i;

	number = (unsigned int)nbr;
	i = 0;
	if (number >= ft_strlen_printf(b))
	{
		ft_putnbr_base(fd, number / ft_strlen_printf(b), b);
		number = number % ft_strlen_printf(b);
	}
	i++;
	ft_putchar_printf(fd, b[number]);
	return (i);
}

int	ft_put_ex(int fd, size_t nbr)
{
	char		*base;
	static int	i;

	i = 0;
	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_put_ex(fd, nbr / 16);
		nbr = nbr % 16;
	}
	i++;
	ft_putchar_printf(fd, base[nbr]);
	return (i);
}

int	ft_putnbr(int fd, int nbr)
{
	long int	number;
	static int	i;

	number = (long long)nbr;
	i = 0;
	if (number < 0)
	{
		write(fd, "-", 1);
		number = number * -1;
	}
	if (number > 9)
	{
		ft_putnbr(fd, number / 10);
		number = number % 10;
	}
	i++;
	ft_putchar_printf(fd, number + '0');
	if (nbr < 0)
		i++;
	return (i);
}

int	ft_pointer(int fd, void *p)
{
	size_t	num;
	int		len;

	len = 0;
	num = (size_t)p;
	len = write(fd, "0x", 2);
	len += ft_put_ex(fd, num);
	return (len);
}
