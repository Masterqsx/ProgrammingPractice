/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 14:07:06 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 16:23:52 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

int		isvalid(char *base, unsigned int *size)
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

void	recursive(unsigned int nbr, unsigned int size, char *base)
{
	if (nbr >= size)
		recursive(nbr / size, size, base);
	ft_putchar(base[nbr % size]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int size;

	if (!isvalid(base, &size))
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		recursive(-1 * nbr, size, base);
	}
	else
		recursive(nbr, size, base);
}
