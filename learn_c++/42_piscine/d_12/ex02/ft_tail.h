/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/27 14:38:16 by sqian             #+#    #+#             */
/*   Updated: 2016/07/28 23:31:44 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <errno.h>

int		ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_isoption(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(char *str);
int		ft_atoi(char *str);
#endif
