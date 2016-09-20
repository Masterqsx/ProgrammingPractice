/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 13:34:38 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 13:44:02 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_board[8];

char	isvalid(int level, int i)
{
	int n;

	n = 0;
	while (n < level)
	{
		if (level - n == g_board[i] - g_board[n])
			return (0);
		if (n - level == g_board[i] - g_board[n])
			return (0);
		n++;
	}
	return (1);
}

void	backtracking(int level, int *re)
{
	int i;

	if (level >= 8)
		*re += 1;
	else
	{
		i = level;
		while (i < 8)
		{
			if (isvalid(level, i))
			{
				g_board[level] ^= g_board[i] ^ (g_board[i] = g_board[level]);
				backtracking(level + 1, re);
				g_board[level] ^= g_board[i] ^ (g_board[i] = g_board[level]);
			}
			i++;
		}
	}
}

int		ft_eight_queens_puzzle(void)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		g_board[i] = i;
		i++;
	}
	backtracking(0, &j);
	return (j);
}
