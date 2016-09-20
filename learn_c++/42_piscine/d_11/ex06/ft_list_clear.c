/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:05:14 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 16:12:02 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list *cur;
	t_list *ne;

	if (!begin_list)
		return ;
	cur = *begin_list;
	while (cur != NULL)
	{
		ne = cur->next;
		free(cur);
		cur = NULL;
		cur = ne;
	}
}
