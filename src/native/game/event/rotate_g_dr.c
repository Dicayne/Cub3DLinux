/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_g_dr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:11:29 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/25 18:24:10 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	rotate_g(t_cub3d *cub)
{
	double old_dirx;
	double old_planex;
	double ang;

	ang = -RS - cub->spe.rot_spe;
	old_dirx = cub->cast.dir.x_f;
	old_planex = cub->cast.plane.x_f;
	cub->cast.dir.x_f =
			cub->cast.dir.x_f * cos(ang) - cub->cast.dir.y_f * sin(ang);
	cub->cast.dir.y_f =
			old_dirx * sin(ang) + cub->cast.dir.y_f * cos(ang);
	cub->cast.plane.x_f =
			cub->cast.plane.x_f * cos(ang) - cub->cast.plane.y_f * sin(ang);
	cub->cast.plane.y_f =
			old_planex * sin(ang) + cub->cast.plane.y_f * cos(ang);
}

static void	rotate_dr(t_cub3d *cub)
{
	double old_dirx;
	double old_planex;
	double ang;

	ang = RS + cub->spe.rot_spe;
	old_dirx = cub->cast.dir.x_f;
	old_planex = cub->cast.plane.x_f;
	cub->cast.dir.x_f =
			cub->cast.dir.x_f * cos(ang) - cub->cast.dir.y_f * sin(ang);
	cub->cast.dir.y_f =
			old_dirx * sin(ang) + cub->cast.dir.y_f * cos(ang);
	cub->cast.plane.x_f =
			cub->cast.plane.x_f * cos(ang) - cub->cast.plane.y_f * sin(ang);
	cub->cast.plane.y_f =
			old_planex * sin(ang) + cub->cast.plane.y_f * cos(ang);
}

void		rotate_g_dr(t_cub3d *cub, int keycode)
{
	if (keycode == G)
		rotate_g(cub);
	if (keycode == DR)
		rotate_dr(cub);
}
