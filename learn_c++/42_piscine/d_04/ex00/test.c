/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 09:57:43 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 09:58:55 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_iterative_factorial(int);

int main(){
  int nb=0;
  scanf("%d",&nb);
  printf("%d\n",ft_iterative_factorial(nb));
  return 0;
}
