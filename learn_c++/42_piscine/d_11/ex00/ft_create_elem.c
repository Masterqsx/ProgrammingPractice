/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 13:19:11 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 14:20:36 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list *re;

	if ((re = (t_list *)malloc(sizeof(*re))) == 0)
		return (NULL);
	re->data = data;
	re->next = NULL;
	return (re);
}
