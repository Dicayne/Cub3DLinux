/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 13:57:41 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/18 14:18:38 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static int		check_split(char **split)
{
	int i;
	int j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (split[i][j] != '\0')
		{
			if (split[i][j] >= '0' && split[i][j] <= '9')
				j++;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

static int		check_color2(char *str_color)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	split = ft_split(str_color, ',');
	if (check_split(split) == 0)
	{
		if (split[0] != NULL && split[1] != NULL && split[2] != NULL &&
			split[3] == NULL)
		{
			r = ft_atoi(split[0]);
			g = ft_atoi(split[1]);
			b = ft_atoi(split[2]);
			if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) &&
				(b >= 0 && b <= 255))
			{
				free_split(split);
				return (0);
			}
		}
	}
	free_split(split);
	return (-1);
}

void			check_color(t_cub3d *cub)
{
	if (check_color2(cub->pars.pars_c) == -1)
	{
		ft_printf("%sError\n%sRGB ERROR%s\n", RED, YELLOW, NC);
		close_prog(cub);
	}
	if (check_color2(cub->pars.pars_f) == -1)
	{
		ft_printf("%sError\n%sRGB ERROR%s\n", RED, YELLOW, NC);
		close_prog(cub);
	}
}
