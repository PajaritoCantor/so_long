/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jurodrig <jurodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:29:14 by jurodrig          #+#    #+#             */
/*   Updated: 2024/10/14 09:39:22 by jurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return (-1);
	}
	return (fd);
}

char	*add_buffer(char *content, const char *buffer, ssize_t bytes_read)
{
	char	*new_content;
	size_t	current_length;

	current_length = ft_strlen(content);
	new_content = malloc(current_length + bytes_read + 1);
	if (!new_content)
		return (NULL);
	ft_memcpy(new_content, content, current_length);
	ft_memcpy(new_content + current_length, buffer, bytes_read);
	free(content);
	return (new_content);
}

char	*read_file(int fd)
{
	char	*content;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	content = ft_calloc(1, 1);
	if (!content)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		content = add_buffer(content, buffer, bytes_read);
		if (!content)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}
