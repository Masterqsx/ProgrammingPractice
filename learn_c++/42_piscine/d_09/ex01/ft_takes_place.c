/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_takes_place.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 22:15:56 by sqian             #+#    #+#             */
/*   Updated: 2016/07/21 22:44:22 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	trans(int hour, int *t, char *c)
{
	if (hour >= 12)
		*c = 'P';
	else
		*c = 'A';
	if (hour == 0 || hour == 12)
		*t = 12;
	else
		*t = hour % 12;
}

void	ft_takes_place(int hour)
{
	int		t;
	char	c;

	trans(hour % 24, &t, &c);
	printf("THE FOLLOWING TAKES PLACE BETWEEN ");
	printf("%d.00 %c.M. AND ", t, c);
	trans((hour + 1) % 24, &t, &c);
	printf("%d.00 %c.M.\n", t, c);
}
