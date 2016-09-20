/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 15:14:09 by sqian             #+#    #+#             */
/*   Updated: 2016/07/27 15:32:17 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int		ft_str_is_numeric(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int		ft_isoption(char *s1, char *s2)
{
	if (ft_strcmp(s1, "-c") != 0)
	{
		ft_error("tail: illegal option --");
		ft_error(s1);
		ft_error("\n");
		return (0);
	}
	else if (!ft_str_is_numeric(s2))
	{
		ft_error("tail: illegal offset --");
		ft_error(s2);
		ft_error("\n");
		return (0);
	}
	return (1);
}
