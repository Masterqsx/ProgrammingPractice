/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 13:50:50 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 14:03:21 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		if (i < size - 1 && size > 0)
			dest[i] = src[i];
		else if (i == size - 1 || size == 0)
			dest[i] = '\0';
		i++;
	}
	if (i < size)
		dest[i] = '\0';
	return (i);
}
