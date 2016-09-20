/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 12:36:02 by sqian             #+#    #+#             */
/*   Updated: 2016/07/25 12:39:42 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f) (char *))
{
	int i;
	int n;

	if (!tab || !f)
		return (0);
	i = 0;
	n = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			n++;
		i++;
	}
	return (n);
}
