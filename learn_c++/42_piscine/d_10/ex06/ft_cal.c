/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:36:05 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 21:03:13 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cal.h"

void	ft_putnbr(long nb)
{
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	c = nb % 10 + '0';
	write(1, &c, 1);
}

void	stupid_norm(void)
{
	g_a[0] = &ad;
	g_a[1] = &mi;
	g_a[2] = &mu;
	g_a[3] = &di;
	g_a[4] = &mo;
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	if (argc != 4)
		return (0);
	stupid_norm();
	if (!is_op(argv[2]))
	{
		write(1, "0\n", 2);
		return (0);
	}
	i = ft_atoi(argv[1]);
	j = ft_atoi(argv[3]);
	if (!is_valid(argv[2][0], j))
	{
		if (argv[2][0] == '/')
			write(1, "Stop : division by zero\n", 24);
		else
			write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(g_a[trans(argv[2][0])](i, j));
	write(1, "\n", 1);
	return (0);
}
