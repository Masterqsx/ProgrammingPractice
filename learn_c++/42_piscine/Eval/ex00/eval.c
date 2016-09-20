/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:06:26 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 00:35:45 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval.h"
#define ISSPACE0 (**str)=='\n'||(**str)==' '||(**str)=='\t'
#define ISSPACE1 (**str)=='\r'||(**str)=='\v'||(**str)=='\f'

int		initial(char *str)
{
	g_size = 0;
	while (str[g_size] != '\0')
		g_size++;
	if ((g_num = (int *)malloc(sizeof(int) * g_size)) == 0)
		return (0);
	if ((g_op = (char *)malloc(sizeof(char) * g_size)) == 0)
		return (0);
	g_num_end = 0;
	g_op_end = 0;
	return (1);
}

void	skip_space(char **str)
{
	while ((ISSPACE0 || ISSPACE1) && *str != '\0')
		(*str)++;
}

void	paran_pop(void)
{
	int re;

	while (g_op[g_op_end - 1] != '(')
	{
		re = cal(g_num[g_num_end - 2], g_num[g_num_end - 1],
				g_op[g_op_end - 1]);
		g_op_end--;
		g_num_end -= 2;
		g_num[g_num_end++] = re;
	}
	g_op_end--;
}

void	finish_cal(void)
{
	int re;

	while (g_op_end > 0)
	{
		re = cal(g_num[g_num_end - 2], g_num[g_num_end - 1],
				g_op[g_op_end - 1]);
		g_op_end--;
		g_num_end -= 2;
		g_num[g_num_end++] = re;
	}
}

int		eval_expr(char *str)
{
	initial(str);
	while (*str != '\0')
	{
		skip_space(&str);
		if (*(str) == '(')
			g_op[g_op_end++] = '(';
		else if (*(str) == ')')
			paran_pop();
		else if (is_num(*str))
		{
			g_num[g_num_end++] = ft_atoi(&str);
			str--;
		}
		else if ((*str == '+' || *str == '-') && is_num(*(str + 1)))
		{
			g_num[g_num_end++] = ft_atoi(&str);
			str--;
		}
		else
			push_op(*(str));
		str++;
	}
	return (norm());
}
