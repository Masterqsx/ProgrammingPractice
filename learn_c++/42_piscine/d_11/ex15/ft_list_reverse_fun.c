/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 19:22:36 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 19:53:55 by sqian            ###   ########.fr       */
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

void	reverse(t_list *begin_list, int size)
{
	t_list	*array[size];
	t_list	*cur;
	int		i;

	cur = begin_list;
	i = 0;
	while (cur != NULL)
	{
		array[i++] = cur;
		cur = cur->next;
	}
	size--;
	while (i < size)
		ft_pswap(array[i++]->data, array[size--]->data);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	t_list	*cur;

	if (!begin_list || !(begin_list->next))
		return ;
	i = 0;
	cur = begin_list;
	while (cur != NULL)
	{
		i++;
		cur = cur->next;
	}
	reverse(begin_list, i);
}
