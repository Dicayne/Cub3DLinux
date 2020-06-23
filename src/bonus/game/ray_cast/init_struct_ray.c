/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_ray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:05:43 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/23 11:06:43 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void	check_dir_plane(t_cub3d *cub)
{
	if (cub->bool == 1)
	{
		init_dir(cub->map, &cub->cast);
		init_plane(&cub->cast);
	}
}

void	init_dir(t_map map, t_cast *cast)
{
	if (map.dir == 'N')
	{
		cast->dir.x_f = 0;
		cast->dir.y_f = -1;
	}
	else if (map.dir == 'S')
	{
		cast->dir.x_f = 0;
		cast->dir.y_f = 1;
	}
	else if (map.dir == 'W')
	{
		cast->dir.x_f = -1;
		cast->dir.y_f = 0;
	}
	else if (map.dir == 'E')
	{
		cast->dir.x_f = 1;
		cast->dir.y_f = 0;
	}
}

void	init_plane(t_cast *cast)
{
	cast->plane.x_f = -cast->dir.y_f * tan(FOV / 2);
	cast->plane.y_f = cast->dir.x_f * tan(FOV / 2);
}

void	init_camera(t_cast *cast, t_path pars, int x)
{
	double		camera_x;

	camera_x = 2 * x / (double)pars.scrwidth - 1;
	cast->ray_dir.x_f = cast->dir.x_f + cast->plane.x_f * camera_x;
	cast->ray_dir.y_f = cast->dir.y_f + cast->plane.y_f * camera_x;
}
