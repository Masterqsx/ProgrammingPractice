/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 20:14:19 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 20:39:49 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	stupid_norm(t_list **cur, t_list **cur1, t_list **cur2, int (*cmp)())
{
	if (cmp((*cur1)->data, (*cur2)->data) > 0)
	{
		(*cur)->next = *cur2;
		*cur2 = (*cur2)->next;
	}
	else
	{
		(*cur)->next = *cur1;
		*cur1 = (*cur1)->next;
	}
	*cur = (*cur)->next;
	(*cur)->next = NULL;
}

void	ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	t_list fake;
	t_list *cur1;
	t_list *cur2;
	t_list *cur;

	if (!begin_list1 || !cmp || !begin_list2)
		return ;
	if (!(*begin_list1))
	{
		*begin_list1 = begin_list2;
		return ;
	}
	cur1 = *begin_list1;
	cur2 = begin_list2;
	cur = &fake;
	cur->next = NULL;
	while (cur1 != NULL && cur2 != NULL)
		stupid_norm(&cur, &cur1, &cur2, cmp);
	if (cur1 == NULL)
		cur->next = cur2;
	else
		cur->next = cur1;
	*begin_list1 = fake.next;
}
