/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 21:13:28 by sqian             #+#    #+#             */
/*   Updated: 2016/07/28 21:37:12 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *))
{
	void *re;

	if (!root || !cmpf)
		return (NULL);
	else if ((re = btree_search_item(root->left, data_ref, cmpf)) != NULL)
		return (re);
	else if (cmpf(root->item, data_ref) == 0)
		return (root);
	else
		return (btree_search_item(root->right, data_ref, cmpf));
}
