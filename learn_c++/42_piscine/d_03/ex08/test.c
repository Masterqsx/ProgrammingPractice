/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 14:28:06 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 20:12:57 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int ft_atoi(char*);

int main(){
  char str[12]={'-','2','1','4','7','4','8','3','6','0','e','\0'};
  printf("%d\n",ft_atoi(str));
  printf("%d\n",-1*(214748364*10+8));
  return 0;
}
