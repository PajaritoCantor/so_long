/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_limits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:03:06 by jurodrig          #+#    #+#             */
/*   Updated: 2024/08/25 21:09:43 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_error(const char *str)
{
	ft_printfd(2, "Error:\n\t%s\n", str);
	exit(EXIT_FAILURE);
}

int	ft_atoi_limits(const char *str)
{
	int		i;
	long	dest;
	int		sign;

	i = 0;
	dest = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		dest = (dest * 10) + (str[i++] - '0');
	if ((dest * sign) > INT_MAX || (dest * sign) < INT_MIN)
		print_error("Overflow detected");
	return ((int)(dest * sign));
}
