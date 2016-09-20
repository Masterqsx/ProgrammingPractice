/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:58:27 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 20:42:46 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	c_print(int i, int j, int x, int y)
{
	if (j == 0 && i == 0)
		ft_putchar('/');
	else if (j == 0 && i == x - 1)
		ft_putchar('\\');
	else if (j == y - 1 && i == 0)
		ft_putchar('\\');
	else if (j == y - 1 && i == x - 1)
		ft_putchar('/');
	else if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
		ft_putchar('*');
	else
		ft_putchar(' ');
}

void	rush01(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			c_print(i, j, x, y);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
