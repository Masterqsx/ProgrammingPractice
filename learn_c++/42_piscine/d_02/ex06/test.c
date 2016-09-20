/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 14:27:39 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 19:21:07 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int ft_putchar(char c){
  write(1,&c,1);
  return 0;
}

void ft_putnbr(int);

int main(){
  int i=0;
  scanf("%d",&i);
  ft_putnbr(i);
  return 0;
}

