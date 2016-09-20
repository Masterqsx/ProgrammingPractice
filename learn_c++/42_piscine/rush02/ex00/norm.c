/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 16:39:48 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 21:04:05 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

void	norm(int i, char c)
{
	if (i == 1 && g_option > 10)
	{
		if (c == 'A')
			g_option = 3;
		else
			g_option = 54;
	}
	else if (i == 2 && g_option > 10)
	{
		if (c == 'C' && g_option == 543)
			g_option = 53;
		else if (c == 'C' && g_option == 54)
			g_option = 4;
		else if (c == 'A' && g_option == 543)
			g_option = 4;
		else if (c == 'A' && g_option == 54)
			g_option = 5;
	}
}

int		ft_putchar(char c)
{
	if (g_check_cur < g_end - 1)
		g_check[g_check_cur++] = c;
	else
		g_check[g_check_cur] = c;
	return (0);
}

int		checkrush(int option)
{
	int n;

	g_check = (char *)malloc(g_end * sizeof(char));
	g_check_cur = 0;
	n = option % 10 - 1;
	if (n == 0)
		rush00(g_wid, g_len);
	else if (n == 1)
		rush01(g_wid, g_len);
	else if (n == 2)
		rush02(g_wid, g_len);
	else if (n == 3)
		rush03(g_wid, g_len);
	else
		rush04(g_wid, g_len);
	g_check[g_check_cur] = '\0';
	g_str[g_cur] = '\0';
	return (ft_strcmp(g_str, g_check));
}
