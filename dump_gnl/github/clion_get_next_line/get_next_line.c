/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:12:00 by hakim             #+#    #+#             */
/*   Updated: 2021/11/30 15:28:42 by hakim            ###   ########.fr       */
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
	rlen = nl_loc(buffer, LEN);
	if (buffer[0] == '\0')
		rlen = read(fd, buffer, BUFFER_SIZE); 
	while (rlen > 0)
	{
		line = put_or_cut(buffer, line);
		if (buffer[0] == '\0')
			rlen = read(fd, buffer, BUFFER_SIZE);
		else if (buffer[0] == -1)
		{
			gnl_memmove(buffer, buffer + BUFFER_SIZE, BUFFER_SIZE);
			break;
		}
		else
			break ;
	}
	return (line);
}

char	*put_or_cut(char *buffer, char *line)
{
	int	nl;

	nl = nl_loc(buffer, NL);
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
		line = nl_strjoin(line, buffer, BUFFER_SIZE - 1);
	gnl_memmove(buffer, buffer + BUFFER_SIZE, BUFFER_SIZE);
	return (line);
}
