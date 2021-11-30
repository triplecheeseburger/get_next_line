/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:46 by hakim             #+#    #+#             */
/*   Updated: 2021/11/30 15:26:31 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*nl_strjoin(char *line, char *buffer, int nl)
{
	int		len;
	int		index;
	int		bufdex;
	char	*result;

	if (line == 0 && buffer == 0)
		return (0);
	len = nl_loc(line, LEN) + nl + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (line && line[index] != '\0')
	{
		result[index] = line[index];
		++index;
	}
	bufdex = 0;
	while (bufdex <= nl)
		result[index++] = buffer[bufdex++];
	result[index] = '\0';
	free(line);
	line = 0;
	return (result);
}

int	nl_loc(char *s, int	mode)
{
	int	index;

	if (s == 0)
		return (0);
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '\n')
			return (index);
		++index;
	}
	if (mode == NL)
		return (-1);
	else
		return (index);
}

void	gnl_memmove(char *dst, char *src, size_t n)
{
	size_t	index;

	index = -1;
	while (src[++index] != '\0')
		dst[index] = src[index];
	while (index < n)
		dst[index++] = '\0';
}
