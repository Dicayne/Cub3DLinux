/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:21 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 17:37:20 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	move_d(t_cub3d *cub)
{
	double spd;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y += cub->cast.plane.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 0)
		cub->map.pos_x += cub->cast.plane.x_f * spd;
}

static void	move_a(t_cub3d *cub)
{
	double spd;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y -= cub->cast.plane.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 0)
		cub->map.pos_x -= cub->cast.plane.x_f * spd;
}

void		move_a_d(t_cub3d *cub, int keycode)
{
	if (keycode == A)
		move_a(cub);
	if (keycode == D)
		move_d(cub);
}
