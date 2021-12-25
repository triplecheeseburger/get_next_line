/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:34:47 by hakim             #+#    #+#             */
/*   Updated: 2021/12/01 01:40:08 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define NL -1
# define LEN 1

typedef struct s_list
{
	char			buffer[BUFFER_SIZE + 1];
	int				fd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*gnl(int fd, t_list *buffer, char *line);
char	*put_or_cut(char *buffer, char *line);
char	*nl_strjoin(char *line, char *buffer, int nl);
int		nl_loc(char *s, int mode);
int		gnl_read(int fd, char *buffer);
void	gnl_memmove(char *dst, char *src, size_t n);
void	free_node(t_list *node);
t_list	*find_fd(t_list *head, int fd);

#endif
