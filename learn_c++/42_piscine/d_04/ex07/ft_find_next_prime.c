/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:57:34 by sqian             #+#    #+#             */
/*   Updated: 2016/07/16 12:12:52 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int end;

	if (nb % 2 == 0 || nb < 2)
		return (0);
	if ((nb / 2) % 2 == 0)
		end = nb / 2 + 1;
	else
		end = nb / 2;
	while (end > 1)
	{
		if (nb % end == 0)
			return (0);
		end -= 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb % 2 == 0)
		nb++;
	while (nb <= 2147483647)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb += 2;
	}
	return (0);
}
