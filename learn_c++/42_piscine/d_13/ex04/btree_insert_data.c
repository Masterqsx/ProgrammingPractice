/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 20:59:10 by sqian             #+#    #+#             */
/*   Updated: 2016/07/28 21:11:29 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root,
		void *item, int (*cmpf)(void *, void *))
{
	if (!root || !cmpf)
		return ;
	if (*root == NULL)
		*root = btree_create_node(item);
	else
	{
		if (cmpf(item, (*root)->item) >= 0)
		{
			if ((*root)->right)
				btree_insert_data(&(*root)->right, item, cmpf);
			else
				(*root)->right = btree_create_node(item);
		}
		else
		{
			if ((*root)->left)
				btree_insert_data(&(*root)->left, item, cmpf);
			else
				(*root)->left = btree_create_node(item);
		}
	}
}
