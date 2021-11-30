/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakim <hakim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:33:12 by hakim             #+#    #+#             */
/*   Updated: 2021/11/25 22:12:56 by hakim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

void	ft_putchar_fd(int fd, char c);

int	main(void)
{
	int		rlen;
	int		fd;
	char	buffer[8];

//	fd = open("a.txt", O_WRONLY | O_CREAT, 00777);
//	ft_putchar_fd(fd, 'a');
//	close(fd);
//	printf("\n");
//
	fd = open("test.txt", O_RDONLY);
	rlen = read(fd, buffer, BUFFER_SIZE);
	printf("%s\n", buffer);
	printf("%d\n", rlen);
	printf("%lu\n", strlen(buffer));
	for (int i = 0; i < 8; i++)
		printf("%d ", buffer[i]);
}

void	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
}
