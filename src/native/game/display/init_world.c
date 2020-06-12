/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:14:25 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:44:55 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static int	get_color2(int r, int g, int b)
{
	int	color;

	color = 0;
	color += r << 16;
	color += g << 8;
	color += b;
	return (color);
}

static int	get_color(char *str_color)
{
	int		r;
	int		g;
	int		b;
	char	**split;
	int		bool;

	bool = 1;
	split = ft_split(str_color, ',');
	if (split[0] != NULL && split[1] != NULL && split[2] != NULL &&
		split[3] == NULL)
	{
		r = ft_atoi(split[0]);
		g = ft_atoi(split[1]);
		b = ft_atoi(split[2]);
		if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) &&
			(b >= 0 && b <= 255))
			bool = 0;
	}
	free_split(split);
	if (bool == 1)
	{
		ft_printf("%sError\n%sRGB ERROR\n", RED, YELLOW);
		exit(EXIT_FAILURE);
	}
	return (get_color2(r, g, b));
}

void		init_world_color(t_cub3d *cub, int *sky, int *floor)
{
	*sky = get_color(cub->pars.pars_c);
	*floor = get_color(cub->pars.pars_f);
}
