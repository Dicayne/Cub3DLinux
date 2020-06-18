/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:42:46 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/18 14:33:42 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static void	fill_line_8xm0(t_map *map, int y, int x)
{
	y = map->y - 1;
	while (y > 0)
	{
		x = map->x - 1;
		if (map->map[y][x] == 8)
		{
			while (x > 0 && map->map[y][x] != 1)
			{
				if (map->map[y][x] == 5)
					map->dir = 0;
				map->map[y][x] = 8;
				x--;
			}
		}
		y--;
	}
}

static void	fill_line_8x0(t_map *map, int y, int x)
{
	while (y < map->y - 1)
	{
		x = 0;
		if (map->map[y][x] == 8)
		{
			while (x < map->x - 1 && map->map[y][x] != 1)
			{
				if (map->map[y][x] == 5)
					map->dir = 0;
				map->map[y][x] = 8;
				x++;
			}
		}
		y++;
	}
}

static int	check_around2(t_map *map, int y, int x)
{
	int check_v1;
	int check_v2;
	int check_v3;
	int check_v4;

	check_v1 = map->map[y][x - 1];
	check_v2 = map->map[y - 1][x];
	check_v3 = map->map[y][x + 1];
	check_v4 = map->map[y + 1][x];
	if (check_v1 == 8 || check_v2 == 8 || check_v3 == 8 || check_v4 == 8
		|| check_v1 == 11 || check_v2 == 11 || check_v3 == 11 || check_v4 == 11)
		return (-1);
	else
		return (0);
}

static int	check_around(t_map *map, int y, int x)
{
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 0 || map->map[y][x] == 2)
			{
				if (check_around2(map, y, x) == -1)
					return (-1);
			}
			if (map->map[y][x] == 5)
				map->map[y][x] = 0;
			x++;
		}
		y++;
	}
	if (map->dir == 0)
		return (-1);
	return (0);
}

void	print_int(t_map *coor)
{
	int y;
	int x;

	y = 0;
	while (y < coor->y)
	{
		x = 0;
		while (x < coor->x)
		{
			ft_putnbr(coor->map[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

int			check_closed_map(t_map *map, int y, int x)
{
	from_0_to_8(map, y, x);
	print_int(map);
	printf("\n\n");
	fill_line_8x0(map, y, x);
	print_int(map);
	printf("\n\n");
	fill_line_8xm0(map, y, x);
	print_int(map);
	printf("\n\n");
	return (check_around(map, y, x));
}
