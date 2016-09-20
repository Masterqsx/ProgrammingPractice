/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 15:21:10 by sqian             #+#    #+#             */
/*   Updated: 2016/08/03 20:32:15 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_fill(void)
{
	int i;
	int j;
	int si;
	int sj;

	si = g_i - g_max + 1;
	sj = g_j - g_max + 1;
	i = 0;
	while (i < g_len)
	{
		j = 0;
		while (j < g_wid)
		{
			if (!is_em(i, j))
				write(1, &g_ob, 1);
			else if (i >= si && i <= g_i && j >= sj && j <= g_j)
				write(1, &g_fu, 1);
			else
				write(1, &g_em, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	ft_destroy(void)
{
	int i;

	i = 0;
	while (i < g_bcur)
	{
		free(g_board[i]);
		g_board[i] = NULL;
		i++;
	}
	free(g_board);
	g_board = NULL;
}

void	ft_strerr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
		write(1, str++, 1);
	g_errno = -1;
}

int		ft_min(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
		write(1, str++, 1);
}
