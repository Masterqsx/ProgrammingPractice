/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:18:09 by sqian             #+#    #+#             */
/*   Updated: 2016/07/30 23:52:52 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		p_cal(char c)
{
	if (c == '(')
		return (0);
	else if (c == '+' || c == '-')
		return (1);
	else
		return (2);
}

int		cal(int n1, int n2, char c)
{
	if (c == '+')
		return (n1 + n2);
	else if (c == '-')
		return (n1 - n2);
	else if (c == '*')
		return (n1 * n2);
	else if (c == '/')
		return (n1 / n2);
	else
		return (n1 % n2);
}

void	push_op(char c)
{
	int re;

	while (g_op_end != 0 && p_cal(c) <= p_cal(g_op[g_op_end - 1]))
	{
		re = cal(g_num[g_num_end - 2], g_num[g_num_end - 1],
				g_op[g_op_end - 1]);
		g_op_end--;
		g_num_end -= 2;
		g_num[g_num_end++] = re;
	}
	g_op[g_op_end++] = c;
}
