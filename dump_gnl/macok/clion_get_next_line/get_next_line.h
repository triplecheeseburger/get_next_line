/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:34:47 by hakim             #+#    #+#             */
/*   Updated: 2021/11/29 19:37:10 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 42

char	*get_next_line(int fd);
char	*put_or_cut(char *buffer, char *line);
char	*ft_strjoin(char *line, char *buffer);
char	*nl_strjoin(char *line, char *buffer, int nl);
void	gnl_memmove(char *dst, char *src, size_t n);
void    flush_buffer(char *buffer);
int		nl_loc(char *s);
size_t	ft_strlen(const char *str);

#endif
