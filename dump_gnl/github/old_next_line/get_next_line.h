/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:34:47 by hakim             #+#    #+#             */
/*   Updated: 2021/11/24 17:37:26 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_realloc(char *str, int new_len);
int		put_or_cut(char *readed, int *len, char *temp, char *line);
int		gnl_memmove(char *readed, char *temp, size_t n);
int		nl_loc(char *s);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
void	flush_temp(char *temp);
void	putline(char *readed, int *len, char *line);
void	putncut(char *readed, int *len, char *temp, char *line);

#endif
