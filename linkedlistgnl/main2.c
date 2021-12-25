/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:19:40 by hakim             #+#    #+#             */
/*   Updated: 2021/12/18 01:43:08 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*line;
	int		fd;
//	int		a = 2000;
//	int		i;

	fd = 0;//open("1", O_RDONLY);	
//	fd[1] = open("1", O_RDONLY);
//	fd[2] = open("1", O_RDONLY);
//	fd[3] = open("1", O_RDONLY);
//	fd[4] = open("1", O_RDONLY);

//	for (i = 0; i < 5; i++)
	line = get_next_line(fd);
	while (line)
	{
//		if (i == 5)
//			i = 0;
//		if (line)
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
//		i++;
	}
	free(line);
//	for (i = 0; i < 5; i++)
	close(fd);
	return (0);
}
