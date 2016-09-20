/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/29 10:18:52 by sqian             #+#    #+#             */
/*   Updated: 2016/07/29 15:25:03 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree_rb.h"
#include <stdio.h>

void	rb_insert(t_rb_node **, void *, int (*)(void *, void *));
void	btree_apply_by_level(t_rb_node *, void (*)(void *, int, int));
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
	t_rb_node *root = NULL;
	rb_insert(&root, i+4, cmp);	
	rb_insert(&root, i+2, cmp);
	rb_insert(&root, i+6, cmp);
	rb_insert(&root, i+5, cmp);
	rb_insert(&root, i+7, cmp);
	rb_insert(&root, i+1, cmp);
	int j = 5;
	rb_insert(&root, &j, cmp);
	int k = 2;
	rb_insert(&root, &k, cmp);
	btree_apply_by_level(root, &display);
	printf("\n");
	return 0;
}
