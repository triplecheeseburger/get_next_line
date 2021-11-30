/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:18:46 by hakim             #+#    #+#             */
/*   Updated: 2021/12/01 01:39:46 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	nl_loc(char *s)
{
	int	index;

	if (s == 0)
		return (-1);
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	size_t	index;
	char	*result;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0)
		return (ft_strdup(s2));
	else if (s2 == 0)
		return (ft_strdup(s1));
	len = ft_strlen((char *)s1);
	len += ft_strlen((char *)s2);
	result = malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	index = -1;
	while (s1[++index] != '\0')
		result[index] = s1[index];
	while (*s2 != '\0')
		result[index++] = *s2++;
	result[index] = '\0';
	free(s1);
	return (result);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	index;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	index = 0;
	while (index <= len)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
