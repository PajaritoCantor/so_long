/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:13:36 by jurodrig          #+#    #+#             */
/*   Updated: 2024/07/14 21:46:08 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_stash_line(char *buffer_tmp, int *eol_loc)
{
	size_t	len;
	char	*line_text;

	len = 0;
	while (buffer_tmp[len] && buffer_tmp[len] != '\n')
		len++;
	len++;
	line_text = malloc(sizeof(char) * (len + 1));
	if (!line_text)
		return (NULL);
	ft_memcpy(line_text, buffer_tmp, len);
	line_text[len] = '\0';
	if (len > 0 && line_text[len - 1] == '\n')
		*eol_loc = len - 1;
	return (line_text);
}

size_t	find_eol_position(char *line_text)
{
	size_t	i;

	i = 0;
	if (!line_text)
		return (-1);
	while (i < BUFFER_SIZE || line_text[i] != '\0')
	{
		if (line_text[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*read_and_extr(char *line_text, char *buffer_tmp, int *eol_loc, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;
	size_t	line_length;

	while (*eol_loc == -1)
	{
		ft_bzero(buffer, (BUFFER_SIZE +1));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(line_text);
			ft_bzero(buffer_tmp, (BUFFER_SIZE + 1));
			return (NULL);
		}
		line_length = find_eol_position(buffer);
		ft_strlcpy_gnl(buffer_tmp, &buffer[line_length], (BUFFER_SIZE + 1));
		buffer[line_length] = '\0';
		line_text = ft_strjoin_gnl(line_text, buffer, eol_loc);
		if (bytes_read == 0)
		{
			ft_bzero(buffer_tmp, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line_text);
}

char	*get_next_line(int fd)
{
	static char	buffer_tmp[BUFFER_SIZE + 1];
	char		*line_text;
	int			eol_loc;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	eol_loc = -1;
	line_text = init_stash_line(buffer_tmp, &eol_loc);
	if (!line_text)
		return (NULL);
	ft_strlcpy_gnl(buffer_tmp, &buffer_tmp[eol_loc + 1], BUFFER_SIZE + 1);
	line_text = read_and_extr(line_text, buffer_tmp, &eol_loc, fd);
	if (!line_text || line_text[0] == '\0')
	{
		free(line_text);
		return (NULL);
	}
	return (line_text);
}
