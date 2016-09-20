/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 09:54:12 by sqian             #+#    #+#             */
/*   Updated: 2016/07/27 15:07:08 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

int		stupid_norm(int argc)
{
	if (argc == 1)
	{
		ft_putstr("File name missing.\n");
		return (0);
	}
	if (argc > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int		input;
	int		nbyte;
	char	buf[11];

	if (stupid_norm(argc) == 0)
		return (0);
	if ((input = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("File open failure\n");
		return (0);
	}
	while ((nbyte = read(input, buf, 10)) != 0)
	{
		if (nbyte == -1)
		{
			ft_putstr("File read failure\n");
			return (0);
		}
		buf[nbyte] = '\0';
		ft_putstr(buf);
	}
	close(input);
	return (0);
}
