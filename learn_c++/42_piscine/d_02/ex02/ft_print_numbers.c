/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 12:59:47 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 21:42:35 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_putchar(char c);

void ft_print_numbers(){
  int cur; 
  cur = 0;
  while(cur < 10){
    ft_putchar(cur + '0');
    cur++;
  }
}
