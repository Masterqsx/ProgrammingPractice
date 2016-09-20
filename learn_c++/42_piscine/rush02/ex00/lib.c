/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 12:47:03 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 21:00:44 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	filter(int i, char c)
{
	if (i == 0)
	{
		if (g_sta == 0 || c == '\n')
			g_sta = 0;
		else
		{
			g_wid++;
			if (c == '/')
				g_option = 2;
			else if (c == 'A')
				g_option = 543;
			else
				g_option = 1;
		}
	}
	else
		norm(i, c);
}

void	ft_print(int option)
{
	if (option == 0)
		option = 54321;
	if (checkrush(option) != 0)
	{
		ft_putstr("aucune\n");
		return ;
	}
	while (option != 0)
	{
		if (option > 10)
			ft_printf(option % 10 - 1, g_wid, g_len, 1);
		else
			ft_printf(option - 1, g_wid, g_len, 0);
		option /= 10;
	}
}

void	ft_printf(int i, int j, int k, int flag)
{
	ft_putstr("[rush-0");
	ft_putnbr(i);
	ft_putstr("] [");
	ft_putnbr(j);
	ft_putstr("] [");
	ft_putnbr(k);
	if (flag == 1)
		ft_putstr("] || ");
	else
		ft_putstr("]\n");
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int		ft_getc(int fd, char *c)
{
	if ((g_sta = read(fd, c, 1)) != 1)
		return (0);
	g_str[g_cur++] = *c;
	if (g_cur == g_end - 1)
	{
		g_end *= 2;
		g_str = ft_realloc(g_str, g_end);
	}
	return (g_sta);
}
