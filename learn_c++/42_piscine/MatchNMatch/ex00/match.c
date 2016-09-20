/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/24 23:03:06 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 23:14:19 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		match(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (!(*s1) && !(*s2))
		return (1);
	else if (*s2 == '*' && !(*s1))
		return (match(s1, s2 + 1));
	else if (!(*s1))
		return (0);
	else if (!(*s2))
		return (0);
	else if (*s2 == '*')
		return (match(s1, s2 + 1) || match(s1 + 1, s2));
	else if (*s2 == *s1)
		return (match(s1 + 1, s2 + 1));
	else
		return (0);
}
