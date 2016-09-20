/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 12:20:47 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 17:37:39 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

void	copy(int flag)
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			if (flag == 1)
				g_res[i][j] = g_map[i][j];
			else
			{
				write(1, &g_res[i][j], 1);
				if (j != 8)
					write(1, " ", 1);
			}
			j++;
		}
		if (flag == 1)
			g_res[i][j] = '\0';
		else
			write(1, "\n", 1);
		i++;
	}
}

int		isvalid(int level, int num)
{
	if (((g_check[0][level % 9]) & (1 << num)) > 0)
		return (0);
	if (((g_check[1][level / 9]) & (1 << num)) > 0)
		return (0);
	if (((g_check[2][(level % 9) / 3 + (level / 9 / 3) * 3]) & (1 << num)) > 0)
		return (0);
	return (1);
}

void	setcheck(int level, int num, int i)
{
	if (i == 1)
	{
		g_check[0][level % 9] |= (1 << num);
		g_check[1][level / 9] |= (1 << num);
		g_check[2][(level % 9) / 3 + (level / 9 / 3) * 3] |= (1 << num);
	}
	else
	{
		g_check[0][level % 9] = g_check[0][level % 9] &= ~(1 << num);
		g_check[1][level / 9] = g_check[1][level / 9] &= ~(1 << num);
		g_check[2][(level % 9) / 3 + (level / 9 / 3) * 3] &= ~(1 << num);
	}
}

void	backtracking_helper(int level, int i)
{
	if (isvalid(level, i))
	{
		setcheck(level, i, 1);
		g_map[level / 9][level % 9] = i + '1';
		backtracking(level + 1);
		g_map[level / 9][level % 9] = '.';
		setcheck(level, i, 0);
	}
}

void	backtracking(int level)
{
	int i;

	if (level >= 81)
	{
		g_n++;
		if (g_n == 1)
			copy(1);
		return ;
	}
	if (g_n < 2)
	{
		if (g_map[level / 9][level % 9] == '.')
		{
			i = 0;
			while (i < 9)
			{
				backtracking_helper(level, i);
				i++;
			}
		}
		else
			backtracking(level + 1);
	}
}
