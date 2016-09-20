/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:52:34 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 11:42:17 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int re;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	re = 1;
	while (nb > 1)
	{
		re *= nb;
		if (re > 2147483647)
			return (0);
		nb--;
	}
	return (re);
}
