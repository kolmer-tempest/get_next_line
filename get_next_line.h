/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpires-k <bpires-k@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/09 21:43:08 by bpires-k          #+#    #+#             */
/*   Updated: 2026/06/21 17:23:35 by bpires-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*buf_str;
	struct s_list	*next;
}			t_list;

char	*get_next_line(int fd);
int		save_line(int fd, char *str);
char	*ft_strchr(const char *s, int c);

#endif
