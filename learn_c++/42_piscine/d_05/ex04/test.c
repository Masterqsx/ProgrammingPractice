/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:51:49 by sqian             #+#    #+#             */
/*   Updated: 2016/07/19 11:38:52 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* ft_strncpy(char* dest,char* src,unsigned int n);

int main(int argc,char ** argv){
	char* s0=argv[1];
	char s1[3];
	char s2[3];
	ft_strncpy(s1,s0,atoi(argv[2]));
	strncpy(s2,s0,atoi(argv[2]));
	printf("%s\n",s1);
	printf("%s\n",s2);
	return 0;
}
