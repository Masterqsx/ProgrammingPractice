/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:29:22 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 17:00:31 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list *fake;
	t_list *cur;
	t_list *temp;

	if (!begin_list || !(*begin_list) || !((*begin_list)->next))
		return ;
	fake = *begin_list;
	while (fake->next != NULL)
		fake = fake->next;
	cur = *begin_list;
	while (cur != fake)
	{
		temp = cur->next;
		cur->next = fake->next;
		fake->next = cur;
		cur = temp;
	}
	*begin_list = fake;
}
