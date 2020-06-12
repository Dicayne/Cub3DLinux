/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 16:21:48 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 18:51:57 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void		find_goal(t_cub3d *cub, double spd, char id)
{
	cub->map.nb_sprit--;
	cub->map.nb_goal--;
	if (id == 'w')
		cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] = 0;
	else if (id == 's')
		cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] = 0;
	free(cub->map.sprit);
	cub->map.sprit = fill_sprit(&cub->map, cub->map.nb_sprit);
}

static int	check_pos(int x, int y, t_cub3d *cub)
{
	int w;
	int h;

	h = (int)(cub->pars.scrheight / 4.5);
	w = (int)(cub->pars.scrwidth / 4.5);
	if ((y * cub->map.y / h) == (int)cub->map.pos_y &&
		(x * cub->map.x / w) == (int)cub->map.pos_x)
		return (-1);
	else
		return (1);
}

int			check_wall(int x, int y, t_cub3d *cub)
{
	int w;
	int h;

	h = (int)(cub->pars.scrheight / 4.5);
	w = (int)(cub->pars.scrwidth / 4.5);
	if ((y * cub->map.y / h) > 0 && (y * cub->map.y / h) < cub->map.y - 1 &&
		(x * cub->map.x / w) > 0 && (x * cub->map.x / w) < cub->map.x - 1 &&
		check_pos(x, y, cub) == 1)
		return (1);
	else
	{
		ft_printf("%sYOU CAN'T TOUCH HERE DEAR !%s ;D%s\n", RED, YELLOW, NC);
		return (-1);
	}
}
