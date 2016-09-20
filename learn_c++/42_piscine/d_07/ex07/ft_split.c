/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 16:04:56 by sqian             #+#    #+#             */
/*   Updated: 2016/07/20 17:05:55 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define SPACE (isdelim(str[i]))
#define END (str[i] == '\0')

char *g_delim;

int			isdelim(char c)
{
	int		i;

	i = 0;
	while (g_delim[i] != '\0')
	{
		if (g_delim[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*string_allocator(char *str, int *n)
{
	int		i;
	char	*re;

	i = *n;
	while (!END && !SPACE)
		i++;
	i = (i == *n ? 0 : (i - *n + 1));
	re = (char *)malloc(i * sizeof(*re));
	if (!re)
		return (0);
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

char		**ft_split(char *str, char *charset)
{
	char	**re;
	int		i;
	int		j;

	if (!str || !charset)
		return (0);
	g_delim = charset;
	re = (char **)malloc(s_size(str) * sizeof(*re));
	i = 0;
	j = 0;
	while (!END)
	{
		if (SPACE)
			i++;
		else
		{
			re[j++] = string_allocator(str, &i);
			if (!re[j - 1])
				return (re);
		}
	}
	re[j] = 0;
	return (re);
}
