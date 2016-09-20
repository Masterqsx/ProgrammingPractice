/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:57:24 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 20:19:49 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	hex_print(unsigned long long nb, char *base)
{
	if (nb >= 16)
		hex_print(nb / 16, base);
	ft_putchar(base[nb % 16]);
}

void	c_print(char c, char *base)
{
	ft_putchar(base[(int)c / 16]);
	ft_putchar(base[(int)c % 16]);
}

void	content_print(char *addr, unsigned int i, int flag, int size)
{
	unsigned int j;

	j = i;
	while (j < size + i)
	{
		if (!flag)
			c_print(*(addr + j), "0123456789abcdef");
		else if (*(addr + j) >= 0 && *(addr + j) <= 31)
			ft_putchar('.');
		else
			ft_putchar(*(addr + j));
		if ((j - i) % 2 == 1 && !flag)
			ft_putchar(' ');
		j++;
	}
	while (j < 16 + i && !flag)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if ((j - i) % 2 == 1)
			ft_putchar(' ');
		j++;
	}
}

void	display(void *addr, unsigned int i, int size)
{
	hex_print((unsigned long long)(addr + i), "0123456789abcdef");
	ft_putchar(':');
	ft_putchar(' ');
	content_print((char *)addr, i, 0, size);
	content_print((char *)addr, i, 1, size);
	ft_putchar('\n');
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i + 16 < size)
	{
		display(addr, i, 16);
		i += 16;
	}
	display(addr, i, size - i);
	return (addr);
}
