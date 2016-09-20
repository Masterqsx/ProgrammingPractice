/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 12:54:53 by sqian             #+#    #+#             */
/*   Updated: 2016/07/27 18:11:13 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_error(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

void	ft_strerr(char *path)
{
	ft_error("tail: ");
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

void	stupid_norm(char **argv, int i)
{
	ft_putstr("==> ");
	ft_putstr(argv[i]);
	ft_putstr(" <==\n");
}

int		main(int argc, char **argv)
{
	int		i;
	int		input;

	if (argc < 3)
		return (0);
	if (!ft_isoption(argv[1], argv[2]))
		return (0);
	i = 3;
	while (i < argc)
	{
		if ((input = open(argv[i], O_RDONLY)) == -1)
			ft_strerr(argv[i++]);
		else
		{
			if (argc > 4)
				stupid_norm(argv, i);
			lseek(input, -1 * ft_atoi(argv[2]), SEEK_END);
			ft_dis(input, argv[i++]);
			if (i < argc)
				ft_putstr("\n");
			close(input);
		}
	}
	return (0);
}
