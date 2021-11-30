/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:12:00 by hakim             #+#    #+#             */
/*   Updated: 2021/11/29 20:06:23 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			rlen;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	rlen = ft_strlen(buffer);
	if (buffer[0] == '\0')
		rlen = read(fd, buffer, BUFFER_SIZE);
	while (rlen > 0)
	{
		line = put_or_cut(buffer, line);
		if (buffer[0] == '\0')
			rlen = read(fd, buffer, BUFFER_SIZE);
		else if (buffer[0] == -1)
		{
			flush_buffer(buffer);
			break ;
		}
		else
			break ;
	}
	return (line);
}

char	*put_or_cut(char *buffer, char *line)
{
	int	nl;

	nl = nl_loc(buffer);
	if (buffer[0] == -1)
		buffer[0] = '\0';
	if (nl != -1)
	{
		line = nl_strjoin(line, buffer, nl);
		gnl_memmove(buffer, buffer + nl + 1, BUFFER_SIZE);
		if (nl == BUFFER_SIZE - 1)
			buffer[0] = -1;
		return (line);
	}
	else
		line = ft_strjoin(line, buffer);
	flush_buffer(buffer);
	return (line);
}

void	gnl_memmove(char *dst, char *src, size_t n)
{
	size_t	index;

	index = -1;
	while (src[++index] != '\0')
		dst[index] = src[index];
	if (index < n)
		dst[index] = '\0';
}
