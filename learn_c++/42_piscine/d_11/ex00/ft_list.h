/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:15:50 by sqian             #+#    #+#             */
/*   Updated: 2016/07/26 15:24:05 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stdlib.h>

typedef	struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;
t_list				*ft_create_elem(void *data);
#endif
