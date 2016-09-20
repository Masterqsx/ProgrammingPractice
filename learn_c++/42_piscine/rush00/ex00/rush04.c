/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 10:20:07 by sqian             #+#    #+#             */
/*   Updated: 2016/07/17 12:33:21 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	check(int x, int y, int i, int j)
{
	if (j == 0 && i == 0)
		ft_putchar('A');
	else if (j == 0 && i == x - 1)
		ft_putchar('C');
	else if (j == y - 1 && i == 0)
		ft_putchar('C');
	else if (j == y - 1 && i == x - 1)
		ft_putchar('A');
	else if (j == 0 || j == y - 1 || i == 0 || i == x - 1)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			check(x, y, i, j);
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
