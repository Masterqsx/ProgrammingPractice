/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 20:04:07 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 20:25:07 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>

int ft_strcmp(char *s1, char *s2);

int main(int argc,char **argv){
	printf("%d\n",ft_strcmp(argv[1],argv[2]));
	printf("%d\n",strcmp(argv[1],argv[2]));
	return 0;
}
