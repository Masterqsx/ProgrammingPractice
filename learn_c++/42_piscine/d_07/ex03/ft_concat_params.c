/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 11:06:02 by sqian             #+#    #+#             */
/*   Updated: 2016/07/20 11:38:51 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*space_create(int argc, char **argv)
{
	int		i;
	int		j;
	int		size;
	char	*re;

	if (argc == 1)
		return (0);
	i = 1;
	size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			j++;
		size += j + 1;
		i++;
	}
	re = (char *)malloc(size * sizeof(*re));
	return (!re ? 0 : re);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	*re;

	if (!(re = space_create(argc, argv)))
		return (0);
	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
			re[k++] = argv[i][j++];
		if (i != argc - 1)
			re[k++] = '\n';
		else
			re[k++] = '\0';
		i++;
	}
	return (re);
}
