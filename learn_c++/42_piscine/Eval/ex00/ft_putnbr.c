/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:19:53 by sqian             #+#    #+#             */
/*   Updated: 2016/07/30 22:43:19 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	recursive(long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
		recursive(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	ft_putnbr(int nb)
{
	recursive(nb);
}
