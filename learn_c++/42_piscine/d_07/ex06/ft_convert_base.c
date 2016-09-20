/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:53:38 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 16:42:10 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define BLANK0 (str[i]=='\t'||str[i]=='\n'||str[i]=='\v')
#define BLANK1 (str[i]=='\f'||str[i]=='\r'||str[i]==' ')
#define ISBASE (isvalid(base_from,&len_from)&&isvalid(base_to,&len_to))

int		isvalid(char *base, int *size)
{
	int i;
	int cha[256];

	i = 0;
	while (i < 256)
		cha[i++] = 0;
	i = 0;
	while (base[i] != '\0')
		cha[(int)base[i++]]++;
	if (i < 2 || cha['+'] > 0 || cha['-'] > 0)
		return (0);
	*size = i;
	i = 0;
	while (i < 256)
	{
		if (cha[i++] > 1)
			return (0);
	}
	return (1);
}

int		isbase(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	int		size;
	int		i;
	int		re;
	char	c;

	if (!str || !isvalid(base, &size))
		return (0);
	i = 0;
	while (BLANK0 || BLANK1)
		i++;
	if ((c = str[i]) == '-' || c == '+')
		i++;
	re = 0;
	while (str[i] != '\0' && isbase(base, str[i]) != -1)
	{
		re = re * size + isbase(base, str[i]);
		i++;
	}
	return (c == '-' ? -1 * re : re);
}

char	*recursive(unsigned int nb, unsigned int size, char *base, char *re)
{
	if (nb >= size)
		re = recursive(nb / size, size, base, re);
	*re = base[nb % size];
	return (re + 1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	int		len_from;
	int		len_to;
	char	*re;

	if (!nbr || !base_from || !base_to || !ISBASE)
		return (0);
	re = (char *)malloc(34 * sizeof(*re));
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
	{
		re[0] = '-';
		*(recursive(-1 * nb, len_to, base_to, re + 1)) = '\0';
	}
	else
		*(recursive(nb, len_to, base_to, re)) = '\0';
	return (re);
}
