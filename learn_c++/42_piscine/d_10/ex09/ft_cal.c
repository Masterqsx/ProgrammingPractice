/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:36:05 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 21:16:12 by sqian            ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int i;
	int j;
	int opera;

	if (argc != 4)
		return (0);
	if ((opera = is_op(argv[2])) == 5)
	{
		g_opptab[5].f(0, 0);
		return (0);
	}
	i = ft_atoi(argv[1]);
	j = ft_atoi(argv[3]);
	if (!is_valid(opera, j))
		return (0);
	ft_putnbr(g_opptab[opera].f(i, j));
	write(1, "\n", 1);
	return (0);
}
