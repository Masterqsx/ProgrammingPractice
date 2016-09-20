/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:00:50 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 11:50:25 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	long long re;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	re = (long long)nb * (long long)ft_recursive_factorial(nb - 1);
	if (re > 2147483647)
		return (0);
	else
		return (re);
}
