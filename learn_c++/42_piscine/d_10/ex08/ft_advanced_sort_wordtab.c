/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_wordtab.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:48:12 by sqian             #+#    #+#             */
/*   Updated: 2016/07/25 16:50:23 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char *t;

	t = *s1;
	*s1 = *s2;
	*s2 = t;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp) (char *, char *))
{
	int i;
	int end;

	if (!tab || !cmp)
		return ;
	end = 0;
	while (tab[end])
		end++;
	while (end > 1)
	{
		i = 0;
		while (i + 1 < end)
		{
			if (cmp(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		end--;
	}
}
