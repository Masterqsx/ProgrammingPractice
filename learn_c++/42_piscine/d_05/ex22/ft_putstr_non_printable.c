/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/19 18:09:42 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 18:25:19 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	non_printable_display(char *str, char *base)
{
	ft_putchar('\\');
	ft_putchar(base[(int)str[0] / 16]);
	ft_putchar(base[(int)str[0] % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (str[0] != '\0')
	{
		if (str[0] >= 0 && str[0] <= 31)
			non_printable_display(str, "0123456789abcdef");
		else
			ft_putchar(str[0]);
		str++;
	}
}
