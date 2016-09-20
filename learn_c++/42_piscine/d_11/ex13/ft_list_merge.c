/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:52:22 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 18:59:14 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *cur;

	if (!begin_list1)
		return ;
	if (!(*begin_list1))
		*begin_list1 = begin_list2;
	else
	{
		cur = *begin_list1;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = begin_list2;
	}
}
