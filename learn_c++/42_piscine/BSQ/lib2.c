/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/02 13:26:39 by sqian             #+#    #+#             */
/*   Updated: 2016/08/03 14:09:35 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	norm(int i, int *cur, int *pre, int dp[2][g_wid])
{
	*cur = i % 2;
	*pre = 1 - *cur;
	if (is_em(i, 0))
	{
		update_max(i, 0, 1);
		dp[*cur][0] = 1;
	}
	else
		dp[*cur][0] = 0;
}

void	ft_store(char **line, int *size, char c, int flag)
{
	if (flag == 0)
	{
		(*line)[(*size)++] = c;
		if (*size == g_chunk - 2)
		{
			g_chunk *= 2;
			*line = ft_realloc(*line, g_chunk, g_chunk / 2);
		}
	}
	else
	{
		if ((*size) % 7 == 0)
			(*line)[(*size) / 7] = 0;
		if (c == g_ob)
			(*line)[(*size) / 7] |= 1 << ((*size) % 7);
		(*size)++;
		if ((*size) == g_chunk * 7)
		{
			g_chunk *= 2;
			*line = ft_realloc(*line, g_chunk, g_chunk / 2);
		}
	}
}

int		is_em(int i, int j)
{
	if ((g_board[i][j / 7] & (1 << (j % 7))) == 0)
		return (1);
	else
		return (0);
}
