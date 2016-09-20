/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:00:12 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 19:21:20 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_pswap(void **data1, void **data2)
{
	void *temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list *end;
	t_list *cur;

	if (!begin_list || !cmp || !(*begin_list) || !((*begin_list)->next))
		return ;
	end = NULL;
	while (end != (*begin_list)->next && end != (*begin_list))
	{
		cur = *begin_list;
		while (cur->next != end)
		{
			if (cmp(cur->data, cur->next->data) > 0)
				ft_pswap(&(cur->data), &(cur->next->data));
			cur = cur->next;
		}
		end = cur;
	}
}
