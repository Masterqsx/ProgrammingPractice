/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:27:56 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 15:33:47 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new_b;

	if (!begin_list)
		return ;
	if (*begin_list == NULL)
	{
		if ((*begin_list = ft_create_elem(data)) == NULL)
			return ;
	}
	else
	{
		if ((new_b = ft_create_elem(data)) == NULL)
			return ;
		new_b->next = *begin_list;
		*begin_list = new_b;
	}
}
