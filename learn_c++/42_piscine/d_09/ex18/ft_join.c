/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 15:54:17 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 16:50:53 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*space_create(int s, char **argv)
{
	int		i;
	int		j;
	int		size;
	char	*re;

	if (s == 0)
		return (0);
	i = 0;
	size = 0;
	while (argv[i] != 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
			j++;
		size += j + s;
		i++;
	}
	re = (char *)malloc(size * sizeof(*re));
	return (!re ? 0 : re);
}

char	*ft_concat_params(int size, char **argv, char *sep, int argc)
{
	int		i;
	int		j;
	int		k;
	char	*re;

	if (!(re = space_create(size, argv)))
		return (0);
	i = 0;
	k = 0;
	while (argv[i] != 0)
	{
		j = 0;
		while (argv[i][j] != '\0')
			re[k++] = argv[i][j++];
		j = 0;
		if (i != argc - 1)
		{
			while (j < size)
				re[k++] = sep[j++];
		}
		else
			re[k++] = '\0';
		i++;
	}
	return (re);
}

char	*ft_join(char **tab, char *sep)
{
	int i;
	int j;

	if (!sep || !tab)
		return (0);
	i = 0;
	while (sep[i])
		i++;
	if (i == 0)
		return (0);
	j = 0;
	while (tab[j])
		j++;
	if (j == 0)
		return (0);
	return (ft_concat_params(i, tab, sep, j));
}
