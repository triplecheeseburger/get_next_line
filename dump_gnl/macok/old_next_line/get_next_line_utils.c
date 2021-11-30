/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:46 by hakim             #+#    #+#             */
/*   Updated: 2021/11/24 17:38:50 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*gnl_realloc(char *str, int new_len)
{
	char	*result;
	int		index;

	if (new_len == 0)
	{
		free(str);
		return (0);
	}
	else if (str == 0)
		return (malloc(new_len));
	result = malloc(new_len);
	if (result == 0)
		return (0);
	index = -1;
	while (str[++index] != '\0')
		result[index] = str[index];
	result[index] = '\0';
	free(str);
	return (result);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	index;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	index = 0;
	if (size < dst_len)
		return (src_len + size);
	else
	{
		while (dst_len + index + 1 < size && src[index] != '\0')
		{
			dst[dst_len + index] = src[index];
			index++;
		}
	}
	dst[dst_len + index] = '\0';
	return (dst_len + src_len);
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

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

void	flush_temp(char *temp)
{
	size_t	index;

	index = 0;
	while (index < BUFFER_SIZE)
		temp[index] = '\0';
	return ;
}
