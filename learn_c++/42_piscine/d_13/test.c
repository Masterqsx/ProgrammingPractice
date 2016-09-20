/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:18:52 by sqian             #+#    #+#             */
/*   Updated: 2016/07/29 23:35:23 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdio.h>

t_btree *btree_create_node(void *);
void	btree_insert_data(t_btree **, void *, int (*)(void *, void *));
void	btree_apply_by_level(t_btree *root, void (*)(void *, int, int));
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));
void	*btree_search_item(t_btree *, void *, int (*)(void *, void *));
int		btree_level_count(t_btree *root);

int cmp(void *i, void *j)
{
	if (*(int *)i > *(int *)j) return 1;
	else if (*(int *)i == *(int *)j) return 0;
	else return -1;
}

void display(void *item, int cl, int isf)
{
	if (isf){
		printf("\nlevel = %d: ", cl);
		printf("%d ", *(int *)item);
	}
	else
		printf("%d ", *(int *)item);
}

void dis(void *item)
{
	printf("%d ", *(int *)item);
}

int main(){
	int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	t_btree *root = NULL;
	btree_insert_data(&root, i+4, cmp);	
	btree_insert_data(&root, i+2, cmp);
	btree_insert_data(&root, i+6, cmp);
	btree_insert_data(&root, i+5, cmp);
	btree_insert_data(&root, i+7, cmp);
	btree_insert_data(&root, i+1, cmp);
	int j = 5;
	btree_insert_data(&root, &j, cmp);
	int k = 2;
	btree_insert_data(&root, &k, cmp);
	btree_apply_by_level(root, &display);
	printf("\n");
	btree_apply_prefix(root, &dis);
	printf("\n");
	btree_apply_infix(root, &dis);
	printf("\n");
	btree_apply_suffix(root, &dis);
	printf("\n");
	printf("%p\n", btree_search_item(root, &k, &cmp));
	printf("%p\n", root->left->left);
	printf("%d\n", btree_level_count(0));
	return 0;
}
