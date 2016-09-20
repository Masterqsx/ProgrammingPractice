/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 22:02:55 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 22:14:18 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_dis(void)
{
	int i;

	i = 1;
	ft_putchar('T');
	while (i < 11)
	{
		if (i % 3 == 0)
			ft_putchar('t');
		else if (i % 3 == 1)
			ft_putchar('u');
		else if (i % 3 == 2)
			ft_putchar(' ');
		i++;
	}
}

void	ft_generic(void)
{
	ft_dis();
	ft_putchar(' ');
	ft_putchar(';');
	ft_putchar(' ');
	ft_dis();
	ft_putchar('\n');
}
