/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:05:34 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 10:06:47 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int ft_putchar(char c){
	write(1,&c,1);
	return 0;
}
void ft_putstr(char*);
int main(){
	char str[4]="abc";
	ft_putstr(str);
	return 0;
}
