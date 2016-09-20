/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 10:51:10 by sqian             #+#    #+#             */
/*   Updated: 2016/07/20 11:03:04 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = (int *)malloc((max - min) * sizeof(int));
	if (!(*range))
		return (0);
	i = 0;
	while (i < max - min)
	{
		range[0][i] = i + min;
		i++;
	}
	return (max - min);
}
