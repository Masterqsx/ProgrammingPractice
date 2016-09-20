/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:16:13 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 21:00:44 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAL_H
# define FT_CAL_H
# include <unistd.h>
# include <stdlib.h>
# define NOP (*str!='+'&&*str!='-'&&*str!='*'&&*str!='/'&&*str!='%')

int		ft_atoi(char *str);
int		is_op(char *str);
int		is_valid(char op, int j);
int		trans(char op);
int		ad(int i, int j);
int		mi(int i, int j);
int		mu(int i, int j);
int		di(int i, int j);
int		mo(int i, int j);
int		(*g_a[5]) (int, int);

#endif
