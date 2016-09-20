/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_active_bits.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 15:05:34 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 15:22:03 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_active_bits(int value)
{
	unsigned int temp;
	unsigned int n;

	temp = (unsigned int)value;
	n = 0;
	while (temp != 0)
	{
		if (temp % 2 != 0)
			n++;
		temp /= 2;
	}
	return (n);
}
