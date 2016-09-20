/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:36:02 by sqian             #+#    #+#             */
/*   Updated: 2016/07/27 18:12:19 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *cur;

	if (begin_list == NULL)
		return (NULL);
	cur = begin_list;
	while (cur->next != NULL)
		cur = cur->next;
	return (cur);
}
