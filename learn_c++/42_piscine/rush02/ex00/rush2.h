/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/31 12:43:38 by sqian             #+#    #+#             */
/*   Updated: 2016/07/31 21:35:26 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH2_H
# define RUSH2_H
# include <stdlib.h>
# include <unistd.h>

int		g_option;
int		g_wid;
int		g_len;
int		g_sta;
char	*g_str;
char	*g_check;
int		g_end;
int		g_cur;
int		g_check_cur;
int		ft_getc(int fd, char *c);
void	filter(int i, char c);
void	ft_print(int g_option);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_printf(int i, int j, int k, int flag);
void	norm(int i, char c);
char	*ft_strcpy(char *dest, char *src);
char	*ft_realloc(char *str, int size);
void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y);
int		ft_putchar(char c);
int		checkrush(int option);
int		ft_strcmp(char *s1, char *s2);
#endif
