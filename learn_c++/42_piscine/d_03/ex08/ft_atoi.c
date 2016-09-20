/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:23:32 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 20:58:40 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_atoi(char *str)
{  
    int i,re;
    
    if(!str) return 0;
    if(str[0] != '-') i = 0;
    else i = 1;
    re = 0;
    while(str[i] - '0' < 10 && str[i] - '0' >= 0)
    {
        re = re * 10 + str[i] - '0';
        i++;
    }
    if(str[0] != '-') return re;
    else return re * -1;
}
