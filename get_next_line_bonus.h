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
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
typedef struct s_list
{
	char			*backup;
	int				fd;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
char	*gnl_read(char *backup, int fd);
char	*pick_line(char *backup);
char	*back_up(char *backup);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
int		nl_loc(char *s);
size_t	ft_strlen(const char *str);
void	free_node(t_list *node);
t_list	*find_fd(t_list *head, int fd);

#endif
