/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 19:54:50 by sqian             #+#    #+#             */
/*   Updated: 2016/07/17 14:08:39 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int g_board[8];

char	isvalid(int level, int i)
{
	int n;

	n = 0;
	while (n < level)
	{
		if (level - n == g_board[n] - g_board[i])
			return (0);
		if (level - n == g_board[i] - g_board[n])
			return (0);
		n++;
	}
	return (1);
}

void	print_narray(void)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ft_putchar(g_board[i] + '1');
		i++;
	}
	ft_putchar('\n');
}

void	backtracking(int level)
{
	int i;

	if (level >= 8)
		print_narray();
	else
	{
		i = level;
		while (i < 8)
		{
			if (isvalid(level, i))
			{
				g_board[level] ^= g_board[i] ^ (g_board[i] = g_board[level]);
				backtracking(level + 1);
				g_board[level] ^= g_board[i] ^ (g_board[i] = g_board[level]);
			}
			i++;
		}
	}
}

void	ft_eight_queens_puzzle_2(void)
{
	int i;

	i = 0;
	while (i < 8)
	{
		g_board[i] = i;
		i++;
	}
	backtracking(0);
	ft_putchar('\n');
}
