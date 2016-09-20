/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:19:49 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 15:24:40 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list *cur;

	if (!begin_list)
		return ;
	if (!(*begin_list))
	{
		*begin_list = ft_create_elem(data);
	}
	else
	{
		cur = *begin_list;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = ft_create_elem(data);
	}
}
