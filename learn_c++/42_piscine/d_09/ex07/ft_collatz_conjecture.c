/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_collatz_conjecture.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 09:59:52 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 10:23:13 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_collatz_conjecture(unsigned int base)
{
	if (base == 1)
		return (0);
	else if (base % 2 == 0)
		base /= 2;
	else
		base = 3 * base + 1;
	return (ft_collatz_conjecture(base) + 1);
}
