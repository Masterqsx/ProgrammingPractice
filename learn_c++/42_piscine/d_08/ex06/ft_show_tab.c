/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 15:49:30 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 16:08:37 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

void		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		ft_putchar(s[i++]);
	ft_putchar('\n');
}

void		ft_putnbr(long nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void		ft_show_tab(struct s_stock_par *par)
{
	int i;
	int j;

	if (!par)
		return ;
	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size_param);
		ft_putchar('\n');
		j = 0;
		while (par[i].tab[j] != 0)
			ft_putstr(par[i].tab[j++]);
		i++;
	}
}
