/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:12:00 by hakim             #+#    #+#             */
/*   Updated: 2021/12/26 03:08:14 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	backup[fd] = gnl_read(backup[fd], fd);
	if (!backup[fd])
		return (NULL);
	line = pick_line(backup[fd]);
	backup[fd] = back_up(backup[fd]);
	return (line);
}

char	*gnl_read(char *backup, int fd)
{
	char	*buffer;
	int		rlen;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == 0)
		return (0);
	rlen = 1;
	while (rlen > 0 && nl_loc(backup) == -1)
	{
		rlen = read(fd, buffer, BUFFER_SIZE);
		if (rlen == 0)
			break ;
		if (rlen == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[rlen] = '\0';
		backup = ft_strjoin(backup, buffer);
	}
	free(buffer);
	return (backup);
}

char	*pick_line(char *backup)
{
	char	*line;
	int		len;
	int		ldex;

	len = 0;
	if (backup[0] == '\0')
		return (0);
	while (backup[len] != '\0' && backup[len] != '\n')
		++len;
	if (backup[len] == '\n')
		++len;
	line = malloc(sizeof(char) * (len + 1));
	if (line == 0)
		return (0);
	ldex = -1;
	while (++ldex < len)
		line[ldex] = backup[ldex];
	line[ldex] = '\0';
	return (line);
}

char	*back_up(char *backup)
{
	char	*new;
	int		index;
	int		deldex;

	deldex = 0;
	while (backup[deldex] != '\0' && backup[deldex] != '\n')
		++deldex;
	if (backup[deldex] == '\n')
		++deldex;
	if (backup[deldex] == '\0')
	{
		free(backup);
		return (0);
	}
	new = malloc(sizeof(char) * (ft_strlen(backup) - deldex + 1));
	if (new == 0)
		return (0);
	index = 0;
	while (backup[deldex] != '\0')
		new[index++] = backup[deldex++];
	new[index] = '\0';
	free(backup);
	return (new);
}
