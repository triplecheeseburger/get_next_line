/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:12:00 by hakim             #+#    #+#             */
/*   Updated: 2021/12/01 01:42:17 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	head;
	t_list			*node;
	char			*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	line = 0;
	node = find_fd(&head, fd);
	line = gnl(fd, node, line);
	return (line);
}

t_list	*find_fd(t_list *head, int fd)
{
	t_list	*temp;

	temp = head;
	while (temp->next != 0)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp->next = malloc(sizeof(t_list));
	temp->next->fd = fd;
	temp->next->prev = temp;
	return (temp->next);
}

char	*gnl(int fd, t_list *node, char *line)
{
	int	rlen;

	rlen = nl_loc(node->buffer, LEN);
	if (node->buffer[0] == '\0')
		rlen = read(fd, node->buffer, BUFFER_SIZE);
	while (rlen > 0)
	{
		line = put_or_cut(node->buffer, line);
		if (node->buffer[0] == '\0')
			rlen = read(fd, node->buffer, BUFFER_SIZE);
		else if (node->buffer[0] == -1)
		{
			gnl_memmove(node->buffer, node->buffer + BUFFER_SIZE, BUFFER_SIZE);
			break ;
		}
		else
			break ;
	}
	if (rlen <= 0)
		free_node(node);
	return (line);
}

void	free_node(t_list *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
	free(node);
	node = 0;
}

char	*put_or_cut(char *buffer, char *line)
{
	int	nl;

	nl = nl_loc(buffer, NL);
	if (buffer[0] == -1)
		buffer[0] = '\0';
	if (nl != -1)
	{
		line = nl_strjoin(line, buffer, nl);
		gnl_memmove(buffer, buffer + nl + 1, BUFFER_SIZE);
		if (nl == BUFFER_SIZE - 1)
			buffer[0] = -1;
		return (line);
	}
	else
		line = nl_strjoin(line, buffer, BUFFER_SIZE - 1);
	gnl_memmove(buffer, buffer + BUFFER_SIZE, BUFFER_SIZE);
	return (line);
}
