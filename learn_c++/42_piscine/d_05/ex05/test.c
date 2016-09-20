/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tset.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/18 19:28:20 by sqian             #+#    #+#             */
/*   Updated: 2016/07/18 19:34:08 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *ft_strstr(char *,char *);

int main(int argc,char **argv){
	printf("%s\n",ft_strstr(argv[1],argv[2]));
	printf("%s\n",strstr(argv[1],argv[2]));
	return 0;
}
