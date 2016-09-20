/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 14:38:59 by sqian             #+#    #+#             */
/*   Updated: 2016/07/20 14:52:57 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar(str[i++]);
}

void	ft_print_words_tables(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i] != 0)
	{
		ft_putstr(tab[i++]);
		ft_putchar('\n');
	}
}
