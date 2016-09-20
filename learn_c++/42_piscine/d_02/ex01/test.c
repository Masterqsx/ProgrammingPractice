/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 18:28:00 by sqian             #+#    #+#             */
/*   Updated: 2016/07/13 18:28:02 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_putchar(char c){
  write(1,&c,1);
  return 0;
}

void ft_print_reverse_alphabet(void);

int main(){
  ft_print_reverse_alphabet();
  return 0;
}

  
