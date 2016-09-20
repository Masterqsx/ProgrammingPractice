/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:27:13 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 11:55:46 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	unsigned int re;

	if (index < 0)
		return (-1);
	if (index < 2)
		return (index);
	re = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	if (re > 2147483647)
		return (0);
	else
		return (re);
}
