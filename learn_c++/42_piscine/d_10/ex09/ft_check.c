/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:19:31 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 21:15:54 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cal.h"
#include "ft_opp.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int		ft_usage(int i, int j)
{
	ft_putstr("error : only [");
	i = 0;
	j = 5;
	while (i < j)
	{
		ft_putstr(g_opptab[i++].op);
		ft_putstr(" ");
	}
	ft_putstr("] are accepted.\n");
	return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
		return (*s1 - *s2);
	return (ft_strcmp(s1 + 1, s2 + 1));
}

int		is_valid(int opera, int j)
{
	if (g_opptab[opera].f == &ft_div && j == 0)
	{
		write(1, "Stop : division by zero\n", 24);
		return (0);
	}
	if (g_opptab[opera].f == &ft_mod && j == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int		is_op(char *str)
{
	int i;

	i = 0;
	while (i < 5)
	{
		if (ft_strcmp(str, g_opptab[i].op) == 0)
			return (i);
		i++;
	}
	return (i);
}
