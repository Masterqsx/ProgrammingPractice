/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 21:41:29 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 21:45:41 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnchar(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		ft_putnchar(argv[i++]);
		ft_putchar('\n');
	}
	return (0);
}
