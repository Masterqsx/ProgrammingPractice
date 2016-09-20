/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:19:31 by sqian             #+#    #+#             */
/*   Updated: 2016/07/25 15:57:35 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cal.h"

int		is_op(char *str)
{
	if (NOP)
		return (0);
	if (str[1] != '\0')
		return (0);
	return (1);
}

int		is_valid(char op, int j)
{
	if ((op == '/' || op == '%') && j == 0)
		return (0);
	return (1);
}

int		trans(char op)
{
	if (op == '+')
		return (0);
	if (op == '-')
		return (1);
	if (op == '*')
		return (2);
	if (op == '/')
		return (3);
	else
		return (4);
}
