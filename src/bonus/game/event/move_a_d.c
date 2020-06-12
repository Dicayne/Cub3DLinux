/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 12:04:21 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/13 00:39:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	check_colision_d(t_cub3d *cub, int *time, double spd)
{
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 0)
		*time = 1;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
				[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 2)
		if (*time == 1)
		{
			if (cub->map.map
					[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
				[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 2 &&
					cub->tex.lifbar.hp > 0)
				cub->tex.lifbar.hp--;
			*time = 0;
		}
}

static void	check_colision_a(t_cub3d *cub, int *time, double spd)
{
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 0)
		*time = 1;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
				[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 2)
		if (*time == 1)
		{
			if (cub->map.map
					[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
				[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 2 &&
					cub->tex.lifbar.hp > 0)
				cub->tex.lifbar.hp--;
			*time = 0;
		}
}

static void	move_d(t_cub3d *cub)
{
	double		spd;
	static int	time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.plane.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y += cub->cast.plane.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x + (cub->cast.plane.x_f * spd))] == 0)
		cub->map.pos_x += cub->cast.plane.x_f * spd;
	check_colision_d(cub, &time, spd);
}

static void	move_a(t_cub3d *cub)
{
	double		spd;
	static int	time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.plane.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y -= cub->cast.plane.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x - (cub->cast.plane.x_f * spd))] == 0)
		cub->map.pos_x -= cub->cast.plane.x_f * spd;
	check_colision_a(cub, &time, spd);
}

void		move_a_d(t_cub3d *cub, int keycode)
{
	if (keycode == A)
		move_a(cub);
	if (keycode == D)
		move_d(cub);
}
