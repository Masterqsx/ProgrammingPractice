/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 18:32:18 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 18:34:17 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>

char *ft_strcpy(char *,char *);

int main(int argc,char **argv){
	char *s0="abcds";
	char s1[10];
	char s2[10];
	ft_strcpy(s1,s0);
	strcpy(s2,s0);
	printf("%s\n",s1);
	printf("%s\n",s2);
	return 0;
}
