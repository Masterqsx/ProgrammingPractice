/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compact.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 14:13:29 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 14:39:17 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_compact(char **tab, int length)
{
	char	*temp[length];
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (i < length)
	{
		if (tab[i] != 0)
			temp[size++] = tab[i++];
		else
			i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = temp[i];
		i++;
	}
	return (size);
}
