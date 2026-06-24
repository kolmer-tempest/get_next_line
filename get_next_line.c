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

char	*save_line(int fd, char *full_line)
{
	int		chars_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	chars_read = 1;
	while (!ft_strchr(full_line, '\n') && chars_read != 0)
	{
		chars_read = read(fd, buffer, BUFFER_SIZE);
		if (chars_read == -1)
			return (free(buffer), NULL);
		buffer[chars_read] = '\0';
		full_line = ft_strjoin(full_line, buffer);
	}
	free(buffer);
	return (full_line);
}

char	*get_next_line(int fd)
{
	static char	*fline;
	char		*nline;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fline = save_line(fd, fline);
	if (!fline || *fline == '\0')
		return (free(fline), fline = NULL, NULL);
	if (ft_strchr(fline, '\n'))
		nline = ft_substr(fline, 0, ft_strchr(fline, '\n') - fline + 1);
	else
		nline = ft_substr(fline, 0, ft_strchr(fline, '\0') - fline);
	temp = fline;
	if (ft_strchr(fline, '\n') && *(ft_strchr(fline, '\n') + 1))
		fline = ft_substr(fline, ft_strchr(fline, '\n') - fline + 1,
				ft_strchr(fline, '\0') - ft_strchr(fline, '\n'));
	else
		fline = NULL;
	free(temp);
	return (nline);
}
