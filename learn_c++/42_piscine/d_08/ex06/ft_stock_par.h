/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_par.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 13:20:08 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 16:04:45 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STOCK_PAR_H
# define FT_STOCK_PAR_H
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_stock_par
{
	int				size_param;
	char			*str;
	char			*copy;
	char			**tab;
}					t_stock_par;
void				ft_show_tab(struct s_stock_par *par);
char				**ft_split_whitespaces(char *str);
struct s_stock_par	*ft_param_to_tab(int ac, char **av);
int					ft_putchar(char c);
#endif
