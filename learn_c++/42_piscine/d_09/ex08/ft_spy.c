/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 10:26:22 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 11:15:14 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define SCMP(X,Y) ft_strcmp(X,Y)
#define SCMPP SCMP(argv[i],"president")
#define SCMPA SCMP(argv[i],"attack")
#define SCMPO SCMP(argv[i],"powers")

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_strlowcase(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i++] != '\0')
	{
		if (str[i - 1] >= 'A' && str[i - 1] <= 'Z')
			str[i - 1] += 'a' - 'A';
	}
	return (str);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	s1 = ft_strlowcase(s1);
	while (s1[i] == ' ' && s1[i] != '\0')
		i++;
	while (s1[i] != '\0' && s2[j] != '\0')
	{
		if (s1[i] != s2[j])
			return (s1[i] - s2[j]);
		i++;
		j++;
	}
	if ((s1[i] == '\0' || s1[i] == ' ') && s2[j] == '\0')
		return (0);
	else
		return (s1[i] - s2[j]);
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!SCMPP || !SCMPA || !SCMPO)
			ft_putstr("Alert!!!\n");
		i++;
	}
	return (0);
}
