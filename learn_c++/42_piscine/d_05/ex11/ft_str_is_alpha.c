/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:30:39 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 21:39:07 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWCASE (str[i]>='a'&&str[i]<='z')
#define UPCASE (str[i]>='A'&&str[i]<='Z')

int		ft_str_is_alpha(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (!(LOWCASE || UPCASE))
			return (0);
		i++;
	}
	return (1);
}
