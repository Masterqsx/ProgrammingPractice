/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:19:53 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 20:39:11 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int		ft_putcha(char c)
{
	write(1, &c, 1);
	return (0);
}

void	recursive(long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putcha('-');
	}
	if (nb >= 10)
		recursive(nb / 10);
	ft_putcha(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	recursive(nb);
}
