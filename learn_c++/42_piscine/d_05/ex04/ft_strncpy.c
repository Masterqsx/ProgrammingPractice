/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:45:26 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 20:24:39 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;
	int flag;

	if (!dest || !src || n <= 0)
		return (dest);
	i = 0;
	flag = 0;
	while (i < n)
	{
		if (flag == 0 && src[i] == '\0')
			flag = 1;
		if (flag)
			dest[i] = '\0';
		else
			dest[i] = src[i];
		i++;
	}
	if (dest[i - 1] != '\0')
		dest[i] = '\0';
	return (dest);
}
