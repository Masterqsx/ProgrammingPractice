/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 23:41:00 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 22:15:26 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int **g_chart;

int		ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		factorial(int s, int e)
{
	if (s == e)
		return (e);
	return (s * factorial(s - 1, e));
}

void	initial(char *s1, char *s2)
{
	int m = ft_strlen(s1) + 1;
	int n = ft_strlen(s2) + 1;
	g_chart = (int **)malloc(m * sizeof(*g_chart));
	for(int i=0; i < m;i++){
		g_chart[i] = (int *)malloc(n * sizeof(int));
		g_chart[i][0] = 0;
	}
	g_chart[0][0] = 1;
	for(int j=1; j < n;j++){
		if (s2[j - 1] == '*')
			g_chart[0][j] = g_chart[0][j - 1];
		else
			g_chart[0][j] = 0;
	}
}
	
int		dp(char *s1, char *s2, int m, int n)
{
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if (s2[j - 1] == '*')
				g_chart[i][j] = g_chart[i - 1][j] + g_chart[i][j - 1];//The key difference between simply return the nubmer of match
			else if (s2[j - 1] == s1[i - 1])
				g_chart[i][j] = g_chart[i - 1][j - 1];
			else
				g_chart[i][j] = 0;
		}
	}
	return (g_chart[m][n]);
}

int		nmatch(char *s1, char *s2)
{
	initial(s1, s2);
	return(dp(s1, s2, ft_strlen(s1), ft_strlen(s2)));

}
