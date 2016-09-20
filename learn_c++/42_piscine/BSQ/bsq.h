/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/30 19:22:29 by sqian             #+#    #+#             */
/*   Updated: 2016/08/03 14:01:32 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

char	**g_board;
int		g_bcur;
int		g_len;
int		g_wid;
int		g_max;
int		g_i;
int		g_j;
int		g_sta;
int		g_chunk;
int		g_errno;
char	g_em;
char	g_ob;
char	g_fu;
char	*ft_realloc(char *str, int nl, int ol);
char	*ft_strcpy(char *dest, char *src, int ol);
int		ft_getc(int fd, char *c, int flag);
int		ft_getline(char **line, int *size, int fd, int flag);
void	ft_perror(char *str);
void	ft_putstr(char *str);
int		ft_atoi(char **str);
void	board_input(int fd);
void	ft_destroy(void);
int		ft_min(int i, int j);
void	norm(int i, int *cur, int *pre, int dp[2][g_wid]);
void	update_max(int i, int j, int size);
void	square_catch(void);
void	ft_fill(void);
void	ft_strerr(char *str);
void	ft_store(char **line, int *size, char c, int flag);
int		is_em(int i, int j);
#endif
