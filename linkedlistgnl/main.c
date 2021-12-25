/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:19:40 by hakim             #+#    #+#             */
/*   Updated: 2021/12/17 23:30:09 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd[5];
	int		a = 300;
	int		i;

	fd[0] = open("1", O_RDONLY);
	fd[1] = open("2", O_RDONLY);
	fd[2] = open("3", O_RDONLY);
	fd[3] = open("4", O_RDONLY);
	fd[4] = open("5", O_RDONLY);

	line = get_next_line(fd[0]);
	i = 1;
	while (a--)
	{
		if (i == 5)
			i = 0;
		if (line)
			printf("%s", line);
		free(line);
		line = get_next_line(fd[i]);
		i++;
	}
	free(line);
	for (i = 0; i < 5; i++)
		close(fd[i]);
	return (0);
}
