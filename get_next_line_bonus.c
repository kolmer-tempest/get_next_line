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

#include "get_next_line_bonus.h"

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
	static char	*fline[1024];
	char		*nline;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fline[fd] = save_line(fd, fline[fd]);
	if (!fline[fd] || *fline[fd] == '\0')
		return (free(fline[fd]), fline[fd] = NULL, NULL);
	if (ft_strchr(fline[fd], '\n'))
		nline = ft_substr(fline[fd], 0, ft_strchr(fline[fd], '\n') - fline[fd] + 1);
	else
		nline = ft_substr(fline[fd], 0, ft_strchr(fline[fd], '\0') - fline[fd]);
	temp = fline[fd];
	if (ft_strchr(fline[fd], '\n') && *(ft_strchr(fline[fd], '\n') + 1))
		fline[fd] = ft_substr(fline[fd], ft_strchr(fline[fd], '\n') - fline[fd] + 1,
				ft_strchr(fline[fd], '\0') - ft_strchr(fline[fd], '\n'));
	else
		fline[fd] = NULL;
	free(temp);
	return (nline);
}
