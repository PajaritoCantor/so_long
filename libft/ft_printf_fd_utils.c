/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:17:04 by jurodrig          #+#    #+#             */
/*   Updated: 2024/08/25 21:17:49 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_putchar_printf(int fd, int c)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_printf(int fd, char *str)
{
	if (!str)
		str = "(null)";
	return (write(fd, str, ft_strlen(str)));
}
