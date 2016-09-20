/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 20:42:29 by sqian             #+#    #+#             */
/*   Updated: 2016/07/28 20:47:26 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree *re;

	if ((re = (t_btree *)malloc(sizeof(*re))) == 0)
		return (0);
	re->item = item;
	re->left = 0;
	re->right = 0;
	return (re);
}
