/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:55:04 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 20:13:09 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	stupid_norm(t_list *pre, t_list *cur, t_list **begin_list, void *data)
{
	if (pre == NULL)
	{
		pre = ft_create_elem(data);
		pre->next = cur;
		*begin_list = pre;
	}
	else
	{
		pre->next = ft_create_elem(data);
		pre->next->next = cur;
	}
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list *cur;
	t_list *pre;

	if (!begin_list || !cmp)
		return ;
	if (!(*begin_list))
		*begin_list = ft_create_elem(data);
	cur = *begin_list;
	pre = NULL;
	while (cur != NULL)
	{
		if (cmp(cur->data, data) >= 0)
		{
			stupid_norm(pre, cur, begin_list, data);
			return ;
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
	pre->next = ft_create_elem(data);
}
