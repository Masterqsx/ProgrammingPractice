/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 09:14:23 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 09:18:55 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	rotate(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((c - 'a' + 42) % 26 + 'a');
	else if (c >= 'A' && c <= 'Z')
		return ((c - 'A' + 42) % 26 + 'A');
	else
		return (c);
}

char	*ft_rot42(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = rotate(str[i]);
		i++;
	}
	return (str);
}
