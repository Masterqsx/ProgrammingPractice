/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 22:21:51 by sqian             #+#    #+#             */
/*   Updated: 2016/07/29 23:34:45 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	g_h;

void	level_count(t_btree *root, int level)
{
	if (root == NULL)
		return ;
	if (level > g_h)
		g_h = level;
	level_count(root->left, level + 1);
	level_count(root->right, level + 1);
}

int		btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	g_h = 0;
	level_count(root, 0);
	return (g_h + 1);
}
