/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:12:00 by hakim             #+#    #+#             */
/*   Updated: 2021/11/24 17:38:19 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	temp[BUFFER_SIZE];
	char		readed[BUFFER_SIZE + 1];
	char		*line;
	int			len;
	int			rlen;

	line = 0;
	len = 1;
	readed[BUFFER_SIZE] = '\0';
	if (temp[0] == '\0')
		rlen = read(fd, readed, BUFFER_SIZE);
	else
		rlen = gnl_memmove(readed, temp, BUFFER_SIZE);
	while (rlen > 0)
	{
		if (put_or_cut(readed, &len, temp, line))
			rlen = read(fd, readed, BUFFER_SIZE);
		else
			break ;
	}
	if (rlen == -1)
		return (0);
	return (line);
}

int	put_or_cut(char *readed, int *len, char *temp, char *line)
{
	if (nl_loc(readed) == -1)
	{
		putline(readed, len, line);
		return (1);
	}
	else if (nl_loc(readed) >= 0)
		putncut(readed, len, temp, line);
	return (0);
}

void	putline(char *readed, int *len, char *line)
{
	*len += ft_strlen(readed);
	line = gnl_realloc(line, *len);
	ft_strlcat(line, readed, *len);
}

void	putncut(char *readed, int *len, char *temp, char *line)
{
	*len += nl_loc(readed);
	line = gnl_realloc(line, *len);
	ft_strlcat(line, readed, *len);
	ft_strlcat(temp, readed + nl_loc(readed), BUFFER_SIZE - nl_loc(readed));
}

int	gnl_memmove(char *readed, char *temp, size_t n)
{
	void	*origin;

	if (readed == 0 && temp == 0)
		return (0);
	origin = readed;
	while (n--)
	{
		*readed = *temp;
		readed++;
		temp++;
	}
	flush_temp(temp);
	return (ft_strlen(readed));
}
