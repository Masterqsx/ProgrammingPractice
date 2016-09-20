/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:17:35 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 21:46:56 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_putchar(char);
int ft_putnchar(char* str,int n){
  int i;
  i = 0;
  while(i < n){
    ft_putchar(str[i]);
    i++;
  }
  return 0;
}

void print_n(int n){
  char re[2];
  re[0] = n / 10 + '0';
  re[1] = n % 10 + '0';
  ft_putnchar(re,2);
}

void ft_print_comb2(){
  int i,j; 
  i = 0;
  j = 1;
  while(i < 100){
    j = i + 1;
    while(j < 100){
      print_n(i);
      ft_putchar(' ');
      print_n(j);
      if(!(j == 99 && i == 98)) ft_putnchar(", ",2);
      j++;
    }
    i++;
  }
}
