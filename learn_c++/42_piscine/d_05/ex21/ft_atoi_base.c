/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 16:24:10 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 17:02:39 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BLANK0 (str[i]=='\t'||str[i]=='\n'||str[i]=='\v')
#define BLANK1 (str[i]=='\f'||str[i]=='\r'||str[i]==' ')

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
