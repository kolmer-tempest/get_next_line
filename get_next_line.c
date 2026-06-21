/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-k <bpires-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:42:46 by bpires-k          #+#    #+#             */
/*   Updated: 2026/06/21 17:22:42 by bpires-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	save_line(int fd, char *str)
{
	t_list	*buffer;
	int		chars_read;

	buffer = (t_list) malloc(sizeof(t_lis) * BUFFER_SIZE + 1);
	chars_read = 1;
	while (chars_read != 0 || ft_strchr(buffer, '\n') != NULL)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		buffer[chars_read] = '\0';
		str += buffer;
		free(buffer);
	}
	return (chars_read);
}

char	*get_next_line(int fd)
{
	static t_list	*line = NULL;
	int				chars_read;

	chars_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chars_read += save_line(fd, line);
	if (!line)
		return (NULL);
	return (line);
}
