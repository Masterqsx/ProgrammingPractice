/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 11:38:58 by sqian             #+#    #+#             */
/*   Updated: 2016/07/20 14:37:28 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SPACE (str[i]==' '||str[i]=='\t'||str[i]=='\n')
#define END (str[i] == '\0')

int			c_size(char *str, int n)
{
	int		i;

	i = n;
	while (!END && !SPACE)
		i++;
	return (i == n ? 0 : (i - n + 1));
}

char		*string_allocator(char *str, int *n)
{
	int		i;
	char	*re;

	re = (char *)malloc(c_size(str, *n) * sizeof(*re));
	i = *n;
	while (!END && !SPACE)
	{
		re[i - *n] = str[i];
		i++;
	}
	re[i - *n] = '\0';
	*n = i;
	return (re);
}

int			s_size(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (!END)
	{
		if (SPACE)
			i++;
		else
		{
			j++;
			while (!SPACE && !END)
				i++;
		}
	}
	return (j + 1);
}

char		**ft_split_whitespaces(char *str)
{
	char	**re;
	int		i;
	int		j;

	if (!str)
		return (0);
	re = (char **)malloc(s_size(str) * sizeof(*re));
	i = 0;
	j = 0;
	while (!END)
	{
		if (SPACE)
			i++;
		else
			re[j++] = string_allocator(str, &i);
	}
	re[j] = 0;
	return (re);
}
