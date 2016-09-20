/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 13:50:07 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 15:47:25 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"

char				*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	if (!src)
		return (0);
	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char *)malloc((i + 1) * sizeof(*dest));
	if (!dest)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void				assign(t_stock_par **re, char **av, int i, int j)
{
	if (av != 0)
	{
		(*re)[i].size_param = j;
		(*re)[i].str = av[i];
		(*re)[i].tab = ft_split_whitespaces(av[i]);
		(*re)[i].copy = ft_strdup(av[i]);
	}
	else
	{
		(*re)[i].str = 0;
		(*re)[i].tab = 0;
		(*re)[i].size_param = 0;
		(*re)[i].copy = 0;
	}
}

struct	s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	int			size;
	t_stock_par	*re;

	if (!av)
		return (0);
	i = 0;
	while (av[i] != 0 && i < ac)
		i++;
	re = (t_stock_par *)malloc((i + 1) * sizeof(t_stock_par));
	if (!re)
		return (0);
	size = i;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (av[i][j] != '\0')
			j++;
		assign(&re, av, i, j);
		i++;
	}
	assign(&re, 0, i, 0);
	return (re);
}
