/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 12:43:28 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 21:32:35 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

int		find_first(int fd)
{
	char c;

	ft_getc(fd, &c);
	filter(0, c);
	if (g_sta != 1)
	{
		ft_print(g_option);
		return (0);
	}
	return (1);
}

int		find_width(int fd)
{
	char c;
	char re[2];

	while (g_wid > 0 && ft_getc(fd, &c) == 1 && c != '\n')
		re[((g_wid++) - 1) % 2] = c;
	g_len++;
	if (g_wid > 1)
		filter(1, re[(g_wid - 2) % 2]);
	return (1);
}

void	find_len(int fd)
{
	char	c;
	char	re[2];
	int		i;

	i = 0;
	while (ft_getc(fd, &c) == 1)
	{
		if (c == '\n')
			g_len++;
		re[(i++) % 2] = c;
	}
	if (i != 0)
		filter(2, re[i % 2]);
	ft_print(g_option);
}

void	detect(int fd)
{
	g_option = 0;
	g_sta = 0;
	g_wid = 0;
	g_len = 0;
	g_end = 64;
	g_cur = 0;
	g_str = (char *)malloc(g_end * sizeof(char));
	if (!find_first(fd) || !find_width(fd))
		return ;
	find_len(fd);
}

int		main(void)
{
	detect(0);
	free(g_check);
	free(g_str);
	return (0);
}
