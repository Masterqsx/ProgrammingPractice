/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 20:37:56 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 20:40:04 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int ft_strncmp(char*,char*,unsigned int);

int main(int argc,char **argv){
	printf("%d\n",ft_strncmp(argv[1],argv[2],atoi(argv[3])));
	printf("%d\n",strncmp(argv[1],argv[2],atoi(argv[3])));
	return 0;
}
