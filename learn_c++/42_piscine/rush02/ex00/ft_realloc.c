/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 19:22:32 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 19:26:24 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush2.h"

char	*ft_realloc(char *str, int size)
{
	char *re;

	re = (char *)malloc(size * sizeof(*re));
	if (str == NULL)
		return (re);
	ft_strcpy(re, str);
	free(str);
	return (re);
}
