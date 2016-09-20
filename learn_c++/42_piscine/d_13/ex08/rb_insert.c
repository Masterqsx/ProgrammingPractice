/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 14:31:56 by sqian             #+#    #+#             */
/*   Updated: 2016/07/29 17:02:24 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"

t_rb_node	*ft_rb_create(void *data)
{
	t_rb_node *re;

	if ((re = (t_rb_node *)malloc(sizeof(*re))) == NULL)
		return (NULL);
	re->parent = NULL;
	re->left = NULL;
	re->right = NULL;
	re->data = data;
	re->color = RB_RED;
	return (re);
}

void		Rotate(t_rb_node *pivot, t_rb_node *cur, t_rb_node **root, int flag)
{
	cur->parent = pivot->parent;
	pivot->parent = cur;
	if (*root == pivot)
		*root = cur;
	if (!flag)
	{
		pivot->left = cur->left;
		cur->left->parent = pivot;
		cur->left = pivot;
		if (*root != cur)
			cur->parent->left = cur;
	}

void		rb_insert(t_rb_node **root, void *data,
		int (*cmpf)(void *, void *))
{
	if (!root || !cmpf)
		return ;
	if (!*root)
	{
		*root = ft_rb_create(data);
		return ;
	}
	if (cmpf(data, (*root)->data) >= 0)
	{
		if ((*root)->right == NULL)
		{
			(*root)->right = ft_rb_create(data);
			(*root)->right->parent = *root;
		}
		else
			rb_insert(&(*root)->right, data, cmpf);
	}
	else
	{
		if ((*root)->left == NULL)
		{
			(*root)->left = ft_rb_create(data);
			(*root)->left->parent = *root;
		}
		else
			rb_insert(&(*root)->left, data, cmpf);
	}
}
