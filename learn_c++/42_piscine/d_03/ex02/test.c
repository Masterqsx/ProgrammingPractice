/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 10:56:15 by sqian             #+#    #+#             */
/*   Updated: 2016/07/14 10:57:56 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

void ft_swap(int *,int *);

int main(){
  int i=2147483647,j=-2147483648;
  ft_swap(&i,&j);
  printf("%d %d\n",i,j);
  return 0;
}
