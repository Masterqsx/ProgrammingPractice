/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sastantua.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 15:12:43 by sqian             #+#    #+#             */
/*   Updated: 2016/07/17 14:38:31 by sqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define DOOR_LEFT  (g_door[0] - x - 2 + y)
#define DOOR_RIGHT (g_door[1] - x - 2 + y)
#define DOOR_BOTTOM (x + 2 - g_door[2])
#define DOOR_HORI i >= DOOR_LEFT && i <= DOOR_RIGHT
#define DOOR_VER y >= DOOR_BOTTOM && y <= x + 2 && x == g_height - 1
#define DOOR_HANDLE g_height>4&&y==x-(g_height-5)/2&&i==g_door[1]-x-3+y

int		ft_putchar(char c);

int g_size;
int g_whitespace;
int g_height;
int g_door[3];

void	c_white(int x, int y)
{
	if (x == g_height)
		return ;
	if (y == x + 2)
		c_white(x + 1, 0);
	else
		c_white(x, y + 1);
	if (y == 0 && x != 0)
		g_whitespace += (x - 1) / 2 + 3;
	else
		g_whitespace += 1;
}

void	print_to_screen(int x, int y)
{
	int i;

	i = 1;
	while (i < g_size)
	{
		if (i == g_size - 1)
			ft_putchar('\\');
		else if (DOOR_HORI && DOOR_VER)
		{
			if (DOOR_HANDLE)
				ft_putchar('$');
			else
				ft_putchar('|');
		}
		else
			ft_putchar('*');
		i++;
	}
	ft_putchar('\n');
}

void	print_pyramid(int x, int y)
{
	int i;

	if (x == g_height)
		return ;
	i = 0;
	while (i < g_whitespace - 1)
	{
		ft_putchar(' ');
		i++;
	}
	ft_putchar('/');
	print_to_screen(x, y);
	if (y == x + 2)
	{
		g_size += (x / 2 + 3) * 2;
		g_whitespace -= x / 2 + 3;
		print_pyramid(x + 1, 0);
	}
	else
	{
		g_size += 2;
		g_whitespace -= 1;
		print_pyramid(x, y + 1);
	}
}

void	sastantua(int size)
{
	if (size <= 0)
		return ;
	g_height = size;
	g_size = 3;
	g_whitespace = 0;
	c_white(0, 0);
	g_door[0] = g_whitespace - (size - 1) / 2;
	g_door[1] = g_whitespace + (size - 1) / 2;
	g_door[2] = (size - 1) / 2 * 2;
	print_pyramid(0, 0);
}
