/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 10:18:29 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 10:20:06 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_iterative_power(int,int);

int main(){
  int nb=0,power=0;
  scanf("%d %d",&nb,&power);
  printf("%d\n",ft_iterative_power(nb,power));
  return 0;
}
