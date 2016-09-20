/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 13:34:28 by sqian             #+#    #+#             */
/*   Updated: 2016/08/03 20:32:54 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_getc(int fd, char *c, int flag)
{
	int sta;

	if ((sta = (int)read(fd, c, 1)) == -1)
		ft_perror("getc read failure\n");
	if (flag == 1 && (*c) != g_em && (*c) != g_ob && (*c) != '\n')
	{
		sta = 0;
		g_errno = -1;
	}
	return (sta);
}

int		ft_getline(char **line, int *size, int fd, int flag)
{
	char c;

	*size = 0;
	if ((*line = malloc(g_chunk)) == NULL)
		ft_perror("getline malloc failure\n");
	while ((g_sta = ft_getc(fd, &c, flag)) && c != '\n')
		ft_store(line, size, c, flag);
	if (g_sta != 1)
	{
		free(*line);
		*line = NULL;
	}
	return (g_sta);
}

void	ft_perror(char *str)
{
	if (!str)
		return ;
	while (*str != '\0')
		write(2, str++, 1);
	exit(1);
}

char	*ft_realloc(char *str, int nl, int ol)
{
	char *re;

	if ((re = (char *)malloc(sizeof(*re) * nl)) == NULL)
		ft_perror("realloc malloc failure\n");
	if (str != NULL)
	{
		ft_strcpy(re, str, ol);
		free(str);
	}
	return (re);
}

char	*ft_strcpy(char *dest, char *src, int ol)
{
	int i;

	if (!dest || !src)
		return (0);
	i = 0;
	while (i < ol)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
