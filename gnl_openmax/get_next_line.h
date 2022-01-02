/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:34:47 by hakim             #+#    #+#             */
/*   Updated: 2021/11/30 16:33:45 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define NL -1
# define LEN 1

char	*get_next_line(int fd);
char	*put_or_cut(char *buffer, char *line);
char	*nl_strjoin(char *line, char *buffer, int nl);
void	gnl_memmove(char *dst, char *src, size_t n);
int		nl_loc(char *s, int mode);

#endif
