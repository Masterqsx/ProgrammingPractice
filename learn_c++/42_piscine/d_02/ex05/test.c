/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:17:35 by sqian             #+#    #+#             */
/*   Updated: 2016/07/13 20:34:15 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int ft_putchar(char c){
  write(1,&c,1);
  return 0;
}

void ft_print_comb2();

int main(){
  ft_print_comb2();
}

