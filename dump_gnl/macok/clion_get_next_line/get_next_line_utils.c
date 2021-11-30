/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:46 by hakim             #+#    #+#             */
/*   Updated: 2021/11/29 17:44:53 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_strjoin(char *line, char *buffer)
{
	int		len;
	int		index;
	char	*result;

	if (line == 0 && buffer == 0)
		return (0);
	len = ft_strlen(line) + ft_strlen(buffer);
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (line && line[index] != '\0') {
        result[index] = line[index];
        ++index;
    }
	while (*buffer != '\0')
		result[index++] = *buffer++;
	result[index] = '\0';
	if (line)
		free(line);
	line = 0;
	return (result);
}

char	*nl_strjoin(char *line, char *buffer, int nl)
{
	int		len;
	int		index;
	int		bufdex;
	char	*result;

	if (line == 0 && buffer == 0)
		return (0);
	len = ft_strlen(line) + nl + 1;
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	index = 0;
    while (line && line[index] != '\0') {
        result[index++] = line[index];
    }
	bufdex = 0;
	while (bufdex <= nl)
		result[index++] = buffer[bufdex++];
	result[index] = '\0';
	if (line)
		free(line);
	line = 0;
	return (result);
}

int	nl_loc(char *s)
{
	int	index;

	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] == '\n')
			return (index);
		++index;
	}
	return (-1);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	if (str == 0)
		return (0);
	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void flush_buffer(char *buffer)
{
    size_t index;

    index = -1;
    while (++index < BUFFER_SIZE)
        buffer[index] = '\0';
}