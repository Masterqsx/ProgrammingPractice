/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:54:53 by sqian             #+#    #+#             */
/*   Updated: 2016/07/28 23:30:36 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"

void	ft_error(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

void	ft_strerr(char *path)
{
	ft_error("cat: ");
	ft_error(path);
	if (errno == EACCES)
		ft_error(": Permission denied\n");
	else if (errno == ENOENT)
		ft_error(": No such file or directory\n");
	else if (errno == EISDIR)
		ft_error(": Is a directory\n");
}

void	ft_dis(int fd, char *path)
{
	int		nbyte;
	char	buf[11];

	while ((nbyte = read(fd, buf, 10)) != 0)
	{
		if (nbyte == -1)
		{
			ft_strerr(path);
			return ;
		}
		buf[nbyte] = '\0';
		ft_putstr(buf);
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		input;

	if (argc == 1)
	{
		while (1)
			ft_dis(0, "Stdin");
	}
	i = 1;
	while (i < argc)
	{
		if ((input = open(argv[i], O_RDONLY)) == -1)
			ft_strerr(argv[i++]);
		else
		{
			ft_dis(input, argv[i++]);
			close(input);
		}
	}
	return (0);
}
