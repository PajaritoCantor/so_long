/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 21:41:31 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/23 13:31:31 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_error(char *error_msg, int y)
{
	ft_printfd(2, "Error: %s\n", error_msg);
	if (y)
		exit(EXIT_FAILURE);
	return (0);
}

int	ft_success(char *msg, int y)
{
	ft_printfd(1, "Success: %s\n", msg);
	if (y)
		exit(EXIT_SUCCESS);
	return (1);
}