/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:11:33 by jurodrig          #+#    #+#             */
/*   Updated: 2024/08/25 22:35:28 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(int fd, va_list args, char format)
{
	int	dest;

	dest = 0;
	if (format == '%')
		dest += ft_putchar_printf(fd, '%');
	else if (format == 'c')
		dest += ft_putchar_printf(fd, va_arg(args, int));
	else if (format == 's')
		dest += ft_putstr_printf(fd, va_arg(args, char *));
	else if (format == 'p')
		dest += ft_pointer(fd, va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		dest += ft_putnbr(fd, va_arg(args, int));
	else if (format == 'u')
		dest += ft_putnbr_base(fd, va_arg(args, int), "0123456789");
	else if (format == 'x')
		dest += ft_putnbr_base(fd, va_arg(args, int), "0123456789abcdef");
	else if (format == 'X')
		dest += ft_putnbr_base(fd, va_arg(args, int), "0123456789ABCDEF");
	else
		dest += ft_putstr_printf(fd, va_arg(args, char *));
	return (dest);
}

static int	ft_xprintf(int fd, char const *string, va_list args)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			count = count + ft_format(fd, args, string[i + 1]);
			i++;
		}
		else
			count = count + write(fd, &string[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_xprintf(1, format, args);
	va_end(args);
	return (count);
}

int	ft_printfd(int fd, char const *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = ft_xprintf(fd, format, args);
	va_end(args);
	return (count);
}
