/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 10:42:43 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 10:44:59 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdlib.h>
int ft_putchar(char c){
	write(1,&c,1);
	return 0;
}
void ft_putnbr(int);
int main(int argc,char ** argv){
	ft_putnbr(atoi(argv[1]));
	return 0;
}
