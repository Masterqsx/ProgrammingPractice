/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 15:00:38 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 19:07:43 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_putchar(char);
int flag=1;
void ft_putnchar(char* str,int n){
  int i=0;
  while(i<n){
    ft_putchar(str[i]);
    i++;  
  }
}

void ft_print_combn(int);
void find_comn(int,char*,int,int);

void ft_print_combn(int n){
  char re[n];
  int i=0;
  while(i<n){
    re[i] = '0';
    i++;
  }
  find_comn(0,re,n,0);
}

void find_comn(int start,char* re,int n,int level){
  if(level==n){
    if(flag!=0) flag=0; 
    else ft_putnchar(", ",2);
    ft_putnchar(re,n);
    return;
  }
  while(start<10){
    re[level]=start+'0';
    find_comn(start+1,re,n,level+1);
    re[level]='0';
    start++;
  }
}

