/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 21:07:40 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 00:34:31 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_H
# define EVAL_H
# include <unistd.h>
# include <stdlib.h>

int		*g_num;
char	*g_op;
int		g_size;
int		g_num_end;
int		g_op_end;
int		ft_atoi(char **str);
int		is_num(char c);
void	paran_pop(void);
void	push_op(char c);
void	finish_cal(void);
int		cal(int n1, int n2, char c);
void	ft_putnbr(int nb);
int		eval_expr(char *str);
int		ft_putchar(char c);
int		norm(void);
#endif
