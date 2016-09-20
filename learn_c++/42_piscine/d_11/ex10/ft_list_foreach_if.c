/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach_if.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:04:36 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 18:11:39 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach_if(t_list *begin_list, void (*f) (void *),
		void *data_ref, int (*cmp) ())
{
	t_list *cur;

	if (!f || !cmp)
		return ;
	cur = begin_list;
	while (cur != NULL)
	{
		if (cmp(cur->data, data_ref) == 0)
			f(cur->data);
		cur = cur->next;
	}
}
