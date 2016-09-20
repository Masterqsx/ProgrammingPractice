/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 11:00:54 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 20:54:58 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_div_mod(int a,int b,int* div,int* mod)
{
    if(!div || !mod || b!=0) return;
    *div = a / b;
    *mod = a % b;
}
