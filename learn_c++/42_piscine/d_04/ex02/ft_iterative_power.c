/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:14:36 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 11:52:25 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	unsigned int re;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 0 || nb == 1)
		return (nb);
	re = 1;
	while (power > 0)
	{
		re *= nb;
		power--;
	}
	return (re);
}
