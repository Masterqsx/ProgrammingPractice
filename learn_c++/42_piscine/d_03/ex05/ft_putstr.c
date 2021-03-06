/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:11:22 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 20:56:48 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_putchar(char);

void ft_putstr(char* str)
{
    int i;

    if(!str) return;
    i = 0;
    while(str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}
