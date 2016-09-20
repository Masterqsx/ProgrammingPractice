/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 21:07:08 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 21:29:17 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define LOWCASE (str[i]>='a'&&str[i]<='z')
#define UPCASE (str[i]>='A'&&str[i]<='Z')
#define NUM (str[i]>='0'&&str[i]<='9')

char	*ft_strcapitalize(char *str)
{
	int i;
	int flag;

	if (!str)
		return (0);
	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (LOWCASE || UPCASE || NUM)
		{
			if (flag == 0)
			{
				flag = 1;
				if (LOWCASE)
					str[i] += 'A' - 'a';
			}
		}
		else
			flag = 0;
		i++;
	}
	return (str);
}
