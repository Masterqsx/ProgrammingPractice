/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/15 11:20:54 by sqian             #+#    #+#             */
/*   Updated: 2016/07/15 11:21:51 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int ft_is_prime(int);

int main(){
  int nb=0;
  scanf("%d",&nb);
  printf("%d\n",ft_is_prime(nb));
  return 0;
}
