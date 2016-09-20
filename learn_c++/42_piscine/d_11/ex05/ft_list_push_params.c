/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:40:28 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 15:58:08 by sqian            ###   ########.fr       */
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

t_list	*ft_list_push_params(int ac, char **av)
{
	int		i;
	t_list	*begin;

	begin = NULL;
	i = 1;
	while (i < ac)
		ft_list_push_back(&begin, av[i++]);
	ft_list_push_back(&begin, av[0]);
	return (begin);
}
