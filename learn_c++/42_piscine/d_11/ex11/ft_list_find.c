/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:12:26 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 18:15:16 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;

	if (!cmp)
		return (NULL);
	cur = begin_list;
	while (cur != NULL)
	{
		if (cmp(cur->data, data_ref) == 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
