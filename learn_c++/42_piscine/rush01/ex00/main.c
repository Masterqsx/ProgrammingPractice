/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 14:18:59 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 17:35:05 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include <stdio.h>
void	initial0(void)
{
	int i;

	g_check = (int **)malloc(3 * sizeof(int *));
	g_check[0] = (int *)malloc(9 * sizeof(int));
	g_check[1] = (int *)malloc(9 * sizeof(int));
	g_check[2] = (int *)malloc(9 * sizeof(int));
	g_res = (char **)malloc(9 * sizeof(char *));
	i = 0;
	while (i < 9)
	{
		g_check[0][i] = 0;
		g_check[1][i] = 0;
		g_check[2][i] = 0;
		i++;
	}	
}

void	initial1(char **argv)
{
	int i;
	int j;

	i = 0;
	g_map = argv + 1;
	while (i < 9)
	{
		g_res[i] = (char *)malloc(9 * sizeof(char ));
		j = 0;
		while (j < 9)
		{
			if (g_map[i][j] != '.')
				setcheck(i * 9 + j, g_map[i][j] - '1', 1);
			j++;
		}
		i++;
	}
	g_n = 0;
}

void	putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		islegal(char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!VCHAR)
				return (0);
			j++;
		}
		if (j != 9)
			return (0);
		i++;
	}
	return (1);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc != 10)
		putstr("Error\n");
	else if (!islegal(argv))
		putstr("Error\n");
	else
	{
		initial0();
		initial1(argv);
		backtracking(0);
		if (g_n != 1)
			putstr("Error\n");
		else
			copy(0);
	}
	return (0);
}
