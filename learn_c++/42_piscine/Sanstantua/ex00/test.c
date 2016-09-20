/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:58:37 by sqian             #+#    #+#             */
/*   Updated: 2016/07/17 13:19:52 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int ft_putchar(char c){
	write(1,&c,1);
	return 0;
}

void sastantua(int);

int main(int argc,char** argv){
	sastantua(atoi(argv[1]));
	return 0;
}
