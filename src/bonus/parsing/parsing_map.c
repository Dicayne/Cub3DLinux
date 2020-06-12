/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 15:26:34 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 18:16:24 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

static int	pars_map3(char **split, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	map->map = (int**)malloc(sizeof(int*) * map->y);
	if (map->map == NULL)
		return (-1);
	while (y < map->y)
	{
		x = 0;
		map->map[y] = (int*)malloc(sizeof(int) * map->x);
		while (split[y][x] != '\0')
		{
			if (split[y][x] == ' ')
				map->map[y][x] = 11;
			else
				map->map[y][x] = split[y][x] - 48;
			x++;
		}
		if (x < map->x)
			fill_8(map->map, x, y, map->x);
		y++;
	}
	return (0);
}

static int	pars_map2(char **split, t_map *map)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	x = 0;
	y = 0;
	while (split[i] != NULL)
	{
		if (x < (int)ft_strlen(split[i]))
			x = ft_strlen(split[i]);
		if (split[i][0] == '\0')
			y--;
		i++;
	}
	y += i;
	map->x = x;
	map->y = y;
	pars_map3(split, map);
	return (0);
}

static int	check_line(char **str, int bool, char **join, t_path *pars)
{
	int i;
	int empty;

	i = 0;
	empty = 1;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] != ' ' && (*str)[i] != 9)
			empty = 0;
		i++;
	}
	if (empty == 1 && bool == 0)
		return (1);
	else if (empty == 0 && bool == 1)
	{
		free(*join);
		free(*str);
		pars->error = ft_strdup("File ERROR\n");
		return (-1);
	}
	else if (empty == 1 && bool == 1)
		return (1);
	else
		return (0);
}

static void	pars_map1bis(char **split, char *join, t_map *map)
{
	split = ft_split(join, '@');
	pars_map2(split, map);
	free(join);
	free_split(split);
}

int			pars_map(t_map *map, int fd, char *str2, t_path *pars)
{
	char	*str;
	int		ret;
	char	*join;
	char	**split;
	int		bool;

	str = NULL;
	split = NULL;
	join = ft_strdup(str2);
	free(str2);
	ret = 1;
	bool = 0;
	while (ret > 0)
	{
		join = ft_strjoingnl(join, "@");
		ret = get_next_line(fd, &str);
		bool = check_line(&str, bool, &join, pars);
		if (ret == -1 || bool == -1)
			return (-1);
		join = ft_strjoingnl(join, str);
		free(str);
	}
	pars_map1bis(split, join, map);
	return (check_map(map, pars));
}
