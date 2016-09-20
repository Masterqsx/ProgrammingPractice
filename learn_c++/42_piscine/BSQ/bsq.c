/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 13:54:44 by sqian             #+#    #+#             */
/*   Updated: 2016/08/03 20:32:00 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	bsq(int fd)
{
	g_errno = 0;
	board_input(fd);
	if (g_errno == 0)
	{
		square_catch();
		ft_fill();
	}
	ft_destroy();
}

int		main(int argc, char **argv)
{
	int i;
	int fd;

	if (argc < 2)
	{
		bsq(0);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i++], O_RDONLY)) == -1)
			ft_perror("can not open file\n");
		bsq(fd);
		close(fd);
	}
	return (0);
}
