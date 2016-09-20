/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/28 22:56:42 by sqian             #+#    #+#             */
/*   Updated: 2016/07/29 11:04:45 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	g_flag;

int		level_at(t_btree *root, int curlevel, int level,
		void (*applyf)(void *item, int current_level, int is_first))
{
	int re1;
	int re2;

	if (!root || !applyf)
		return (0);
	if (curlevel == level)
	{
		applyf(root->item, curlevel, !g_flag);
		if (!g_flag)
			g_flag = 1;
		return (1);
	}
	re1 = level_at(root->left, curlevel + 1, level, applyf);
	re2 = level_at(root->right, curlevel + 1, level, applyf);
	return (re1 || re2);
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first))
{
	int i;

	if (!root || !applyf)
		return ;
	i = 0;
	while (1)
	{
		g_flag = 0;
		if (level_at(root, 0, i, applyf) == 0)
			return ;
		i++;
	}
}
