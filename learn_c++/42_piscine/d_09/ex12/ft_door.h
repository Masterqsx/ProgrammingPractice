/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_door.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/22 13:37:01 by sqian             #+#    #+#             */
/*   Updated: 2016/07/22 14:04:06 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DOOR_H
# define FT_DOOR_H
# include <unistd.h>
# define OPEN 1
# define CLOSE 0
# define TRUE 1

typedef int		t_bool;
typedef struct	s_door
{
	int	state;
}				t_door;
void			ft_putstr(char *str);
t_bool			close_door(t_door *door);
t_bool			is_door_open(t_door *door);
t_bool			is_door_close(t_door *door);
t_bool			open_door(t_door *door);
#endif
