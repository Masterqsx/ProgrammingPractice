/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:35:28 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 11:59:00 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long lo;
	long long hi;
	long long mid;

	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	lo = 2;
	hi = nb;
	while (lo <= hi)
	{
		mid = lo + (hi - lo) / 2;
		if (mid * mid == nb)
			return ((int)mid);
		else if (mid * mid > nb)
			hi = mid - 1;
		else
			lo = mid + 1;
	}
	return (0);
}
