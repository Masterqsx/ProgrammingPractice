/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 12:45:38 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 18:49:02 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		skip_star(char *s, int *i)
{
	if (s[*i] != '*' && s[*i] != '\0')
		return (-1);
	if (s[*i] == '\0')
		return (-2);
	while (s[*i] == '*' && s[*i] != '\0')
		(*i)++;
	return (s[*i] == '\0');
}

int		comp(char *s1, char *s2, int *i1, int *i2)
{
	while (s2[*i2] != '*' && s2[*i2] != '\0' && s1[*i1] != '\0')
	{
		if (s1[*i1] != s2[*i2])
			return (0);
		(*i1)++;
		(*i2)++;
	}
	return (s2[*i2] == '*' || s2[*i2] == '\0');
}

int		find_match(char *s1, char *s2, int i1, int i2)
{
	int temp2;
	int temp1;
	int flag;
	int flag2;

	flag = skip_star(s2, &i2);
	if (flag == 1)
		return (1);
	if (flag == -2 && s1[i1] != '\0')
		return (-1);
	else if (flag == -2)
		return (1);
	while (s1[i1] != '\0')
	{
		temp2 = i2;
		temp1 = i1;
		if (comp(s1, s2, &i1, &i2))
		{
			flag2 = find_match(s1, s2, i1, i2);
			if (flag2 != -1)
				return (flag2);
		}
		if (flag == -1)
			return (0);
		i2 = temp2;
		i1 = temp1 + 1;
	}
	return (0);
}

int		match(char *s1, char *s2)
{
	if (!s2 || !s1)
		return (0);
	return (find_match(s1, s2, 0, 0));
}
