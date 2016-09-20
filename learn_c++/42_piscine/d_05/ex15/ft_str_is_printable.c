/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 22:52:38 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 23:03:28 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 0 && str[i] <= 31)
			return (0);
		i++;
	}
	return (1);
}
