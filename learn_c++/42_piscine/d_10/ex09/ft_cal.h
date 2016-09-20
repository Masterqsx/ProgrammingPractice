/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:16:13 by sqian             #+#    #+#             */
/*   Updated: 2016/07/25 19:50:24 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CAL_H
# define FT_CAL_H
# include <unistd.h>
# include <stdlib.h>

int				ft_atoi(char *str);
int				is_op(char *str);
int				is_valid(int opera, int j);
int				ft_add(int i, int j);
int				ft_sub(int i, int j);
int				ft_div(int i, int j);
int				ft_mul(int i, int j);
int				ft_mod(int i, int j);
int				ft_usage(int i, int j);
void			ft_putstr(char *s);
int				ft_strcmp(char *s1, char *s2);
typedef	struct	s_opp
{
	char		*op;
	int			(*f) (int, int);
}				t_opp;
t_opp			g_opptab[6];

#endif
