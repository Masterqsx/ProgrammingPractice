/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 12:48:01 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 13:45:03 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int j;
	unsigned int s_src;

	if (!dest || !src)
		return (0);
	j = 0;
	while (src[j] != '\0')
		j++;
	s_src = j;
	i = 0;
	while (dest[i] != '\0')
	{
		if (i == size)
			return (s_src + size);
		else
			i++;
	}
	s_src += i;
	j = 0;
	while (src[j] != '\0' && i < size - 1 && size > 0)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (s_src);
}
