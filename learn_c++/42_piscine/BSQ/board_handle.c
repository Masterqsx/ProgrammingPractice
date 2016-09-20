/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_inial.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 19:39:36 by sqian             #+#    #+#             */
/*   Updated: 2016/08/03 15:00:45 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		initial(int fd)
{
	char	*line;
	char	*temp;
	int		size;

	g_chunk = 64;
	ft_getline(&line, &size, fd, 0);
	temp = line;
	if (temp != NULL)
	{
		g_len = ft_atoi(&temp);
		g_em = *(temp++);
		g_ob = *(temp++);
		g_fu = *(temp++);
	}
	free(line);
	g_bcur = 0;
	if (g_len <= 0)
		return (1);
	g_board = (char **)malloc((g_len + 1) * sizeof(char *));
	return (0);
}

void	board_input(int fd)
{
	int	size;

	if (initial(fd) == 1)
	{
		ft_strerr("map error\n");
		return ;
	}
	g_wid = 0;
	while (ft_getline(&(g_board[g_bcur]), &size, fd, 1) == 1)
	{
		g_bcur++;
		if (size == 0 || (g_wid != 0 && g_wid != size))
		{
			ft_strerr("map error\n");
			return ;
		}
		g_wid = size;
		g_chunk = (size + 2) / 7 + 1;
	}
	if (g_bcur != g_len || g_errno == -1)
		ft_strerr("map error\n");
}

void	square_catch_initial(int dp[2][g_wid], int *i)
{
	int		j;
	int		flag;

	g_i = 0;
	g_j = 0;
	g_max = 0;
	j = 0;
	flag = 0;
	*i = 1;
	while (j < g_wid)
	{
		if (is_em(0, j))
		{
			dp[0][j] = 1;
			update_max(0, j, 1);
		}
		else
			dp[0][j] = 0;
		j++;
	}
}

void	update_max(int i, int j, int size)
{
	if (size > g_max)
	{
		g_i = i;
		g_j = j;
		g_max = size;
	}
}

void	square_catch(void)
{
	int	dp[2][g_wid];
	int i;
	int j;
	int cur;
	int	pre;

	square_catch_initial(dp, &i);
	while (i < g_len)
	{
		norm(i, &cur, &pre, dp);
		j = 1;
		while (j < g_wid)
		{
			if (is_em(i, j))
			{
				dp[cur][j] = ft_min(ft_min(dp[pre][j],
							dp[pre][j - 1]), dp[cur][j - 1]) + 1;
				update_max(i, j, dp[cur][j]);
			}
			else
				dp[cur][j] = 0;
			j++;
		}
		i++;
	}
}
