/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:11:46 by sqian             #+#    #+#             */
/*   Updated: 2016/07/25 16:32:06 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2 || *s1 == '\0' || *s2 == '\0')
		return (*s1 - *s2);
	else
		return (ft_strcmp(s1 + 1, s2 + 1));
}

void	ft_swap(char **s1, char **s2)
{
	char *t;

	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

void	ft_sort_wordtab(char **tab)
{
	int i;
	int end;

	if (!tab)
		return ;
	end = 0;
	while (tab[end])
		end++;
	while (end > 1)
	{
		i = 0;
		while (i + 1 < end)
		{
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		end--;
	}
}
