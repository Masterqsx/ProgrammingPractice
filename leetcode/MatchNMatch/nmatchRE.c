/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/23 23:41:00 by sqian             #+#    #+#             */
/*   Updated: 2016/07/24 23:13:20 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nmatch(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (!(*s1) && !(*s2))
		return (1);
	else if (*s2 == '*' && !(*s1))
		return (nmatch(s1, s2 + 1));
	else if (!(*s1))
		return (0);
	else if (!(*s2))
		return (0);
	else if (*s2 == '*')
		return (nmatch(s1, s2 + 1) + nmatch(s1 + 1, s2));
	else if (*s2 == *s1)
		return (nmatch(s1 + 1, s2 + 1));
	else
		return (0);
}
