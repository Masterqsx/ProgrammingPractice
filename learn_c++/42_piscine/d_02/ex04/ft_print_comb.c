/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:14:55 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 21:45:23 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int ft_putchar(char);
int ft_putnchar(char* str,int n);
void find_comb(char*,int,int,int*);

void ft_print_comb(){
  char re[3] = {'0','0','0'};
  int flag; 
  flag = 1;
  find_comb(re,0,0,&flag);
}

int ft_putnchar(char* str,int n){
  int i; 
  i = 0;
  while(i < n){
    ft_putchar(str[i]);
    i++;
  }
  return 0;
}

void find_comb(char* re,int start,int level,int* flag){
  if(level == 3){
    if(*flag != 0) *flag = 0;
    else ft_putnchar(", ",2);
    ft_putnchar(re,3);
    return;
  }
  while(start < 10){
    re[level] = start + '0';
    find_comb(re,start + 1,level + 1,flag);
    re[level] = '0';
    start++;
  }
}
