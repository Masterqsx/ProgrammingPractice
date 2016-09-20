/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:13:52 by sqian             #+#    #+#             */
/*   Updated: 2016/07/30 21:30:45 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ISSPACE0 (*str)[i]=='\n'||(*str)[i]==' '||(*str)[i]=='\t'
#define ISSPACE1 (*str)[i]=='\r'||(*str)[i]=='\v'||(*str)[i]=='\f'

int g_flag;

int		ft_atoi(char **str)
{
	int i;
	int re;

	i = 0;
	while (ISSPACE0 || ISSPACE1)
		i++;
	g_flag = 1;
	if ((*str)[i] == '-')
	{
		g_flag = -1;
		i++;
	}
	else if ((*str)[i] == '+')
		i++;
	re = 0;
	while ((*str)[i] != '\0' && (*str)[i] >= '0' && (*str)[i] <= '9')
	{
		re = re * 10 + (*str)[i] - '0';
		i++;
	}
	*str += i;
	return (g_flag * re);
}
