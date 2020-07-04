/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 18:12:15 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 19:16:53 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

int				strlen_c(char *str, char c, char d)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (str[i] != '\0')
	{
		str[i] != c && str[i] != d ? ret++ : ret;
		i++;
	}
	return (ret);
}

void			fill_8(int **map, int x, int y, int max)
{
	while (x < max)
	{
		map[y][x] = 0;
		x++;
	}
}

void			from_0_to_8(t_map *map, int y, int x)
{
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] == 0 || map->map[y][x] == 2)
			{
				if (y == 0 || y == map->y - 1 || x == map->x - 1 || x == 0)
					map->map[y][x] = 8;
			}
			if (map->map[y][x] == 11)
				map->map[y][x] = 8;
			x++;
		}
		y++;
	}
}

int				strisnum(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1)
			i++;
		else
			return (-1);
	}
	return (1);
}

void			set_ret_error(int *ret, t_path *pars)
{
	*ret == 0 ? *ret = -1 : *ret;
	*ret == -2 ? pars->error = ft_strdup("Elements ERROR\n") : pars->error;
	*ret == -1 ? pars->error = ft_strdup("Arguments ERROR\n") : pars->error;
	*ret == -2 ? *ret = -1 : *ret;
}
