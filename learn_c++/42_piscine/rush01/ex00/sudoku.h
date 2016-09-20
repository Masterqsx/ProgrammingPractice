/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 14:58:53 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 17:36:04 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H
# include <stdlib.h>
# include <unistd.h>
# define VCHAR ((argv[i][j]>='0'&&argv[i][j]<='9')||argv[i][j]=='.')

void	backtracking(int level);
char	**g_map;
char	**g_res;
int		g_n;
int		**g_check;
void	initial(char **argv);
void	setcheck(int level, int num, int i);
void	copy(int flag);
#endif
