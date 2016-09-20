/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 10:42:06 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 16:20:48 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *re;
	int i;

	if (min >= max)
		return (0);
	re = (int *)malloc((max - min) * sizeof(*re));
	if (!re)
		return (0);
	i = min;
	while (i < max)
	{
		re[i - min] = i;
		i++;
	}
	return (re);
}
