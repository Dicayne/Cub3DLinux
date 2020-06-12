/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_w_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 11:55:43 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/13 00:39:47 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	check_colision_s(t_cub3d *cub, int *time, double spd)
{
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 0)
		*time = 1;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 2 ||
		cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 3)
		if (*time == 1)
		{
			if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 2 &&
					cub->tex.lifbar.hp > 0)
				cub->tex.lifbar.hp--;
			if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 3)
				find_goal(cub, spd, 's');
			*time = 0;
		}
}

static void	check_colision_w(t_cub3d *cub, int *time, double spd)
{
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 0)
		*time = 1;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 1 ||
		cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 2 ||
		cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 3)
		if (*time == 1)
		{
			if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 2 &&
					cub->tex.lifbar.hp > 0)
				cub->tex.lifbar.hp--;
			if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
					[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 3)
				find_goal(cub, spd, 'w');
			*time = 0;
		}
}

static void	move_w(t_cub3d *cub)
{
	double		spd;
	static int	time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y + (cub->cast.dir.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y += cub->cast.dir.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x + (cub->cast.dir.x_f * spd))] == 0)
		cub->map.pos_x += cub->cast.dir.x_f * spd;
	check_colision_w(cub, &time, spd);
}

static void	move_s(t_cub3d *cub)
{
	double		spd;
	static int	time;

	spd = MS + cub->spe.mov_spe;
	if (cub->map.map[(int)(cub->map.pos_y - (cub->cast.dir.y_f * spd))]
				[(int)cub->map.pos_x] == 0)
		cub->map.pos_y -= cub->cast.dir.y_f * spd;
	if (cub->map.map[(int)cub->map.pos_y]
				[(int)(cub->map.pos_x - (cub->cast.dir.x_f * spd))] == 0)
		cub->map.pos_x -= cub->cast.dir.x_f * spd;
	check_colision_s(cub, &time, spd);
}

void		move_w_s(t_cub3d *cub, int keycode)
{
	if (keycode == W)
		move_w(cub);
	if (keycode == S)
		move_s(cub);
}
