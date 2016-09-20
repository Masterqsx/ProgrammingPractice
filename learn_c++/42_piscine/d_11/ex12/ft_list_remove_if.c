/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:16:05 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 18:51:33 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	stupid_norm(t_list *pre, t_list *cur, t_list **begin_list)
{
	if (pre == NULL)
	{
		pre = cur->next;
		free(cur);
		cur = pre;
		pre = NULL;
		*begin_list = cur;
	}
	else
	{
		pre->next = cur->next;
		free(cur);
		cur = pre->next;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *cur;
	t_list *pre;

	if (!begin_list || !cmp || !(*begin_list))
		return ;
	cur = *begin_list;
	pre = NULL;
	while (cur != NULL)
	{
		if (cmp(cur->data, data_ref) == 0)
		{
			stupid_norm(pre, cur, begin_list);
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
	}
}
