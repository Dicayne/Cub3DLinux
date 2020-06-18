/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:43:08 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/18 14:47:51 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static int		check_value(t_map *map, int y, int x)
{
	map->nb_sprit = 0;
	map->nb_goal = 0;
	map->nb_goal_start = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (!((map->map[y][x] >= 0 && map->map[y][x] <= 2)
			|| map->map[y][x] == 30 || map->map[y][x] == 35
			|| map->map[y][x] == 39 || map->map[y][x] == 21
			|| map->map[y][x] == 11 || map->map[y][x] == 3))
				return (-1);
			if (map->map[y][x] == 2 || map->map[y][x] == 3)
				map->nb_sprit++;
			if (map->map[y][x] == 3)
				map->nb_goal++;
			x++;
		}
		y++;
	}
	if (map->nb_goal > 0)
		map->nb_goal_start = 1;
	return (0);
}

static int		check_pos(t_map *map, int y, int x)
{
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 30 || map->map[y][x] == 35
				|| map->map[y][x] == 39 || map->map[y][x] == 21)
			{
				if (map->pos_x == -1 && map->pos_y == -1)
				{
					map->pos_y = y + 0.5;
					map->pos_x = x + 0.5;
					map->dir = map->map[y][x] + 48;
					map->map[y][x] = 5;
				}
				else
					return (-1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void		from_8_to_1(t_map *map)
{
	int y;
	int x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 8)
				map->map[y][x] = 1;
			x++;
		}
		y++;
	}
}

int				check_map(t_map *map, t_path *pars)
{
	int x;
	int y;

	x = 0;
	y = 0;
	pars->error = ft_strdup("Map ERROR\n");
	if (check_value(map, y, x) == -1)
		return (-1);
	else if (check_pos(map, y, x) == -1)
		return (-1);
	else if (check_closed_map(map, y, x) == -1)
		return (-1);
	from_8_to_1(map);
	if (map->nb_sprit > 0)
	{
		map->bool_sprit = 0;
		map->sprit = fill_sprit(map, map->nb_sprit);
	}
	return (0);
}
