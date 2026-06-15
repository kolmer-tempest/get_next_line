/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-k <bpires-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:42:46 by bpires-k          #+#    #+#             */
/*   Updated: 2026/06/14 12:06:45 by bpires-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_line(int fd, char *str)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *) malloc(BUFFER_SIZE);
	bytes_read = 1;
	while (bytes_read != 0 || ft_strchr(buffer, '\n') != NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		str = buffer;
		free(buffer);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	int chars_read;

	chars_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = save_line(fd, line);
	if (!line)
		return (NULL);
	return (line);
}
