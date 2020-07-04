/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:29:09 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 17:36:41 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	prep_ray_cast2(t_cast *cast, t_map map)
{
	if (cast->ray_dir.x_f < 0)
	{
		cast->step.x_i = -1;
		cast->side_dist.x_f = (map.pos_x - cast->map.x_i) *
								cast->delta_dist.x_f;
	}
	else
	{
		cast->step.x_i = 1;
		cast->side_dist.x_f = (cast->map.x_i + 1.0 - map.pos_x) *
								cast->delta_dist.x_f;
	}
	if (cast->ray_dir.y_f < 0)
	{
		cast->step.y_i = -1;
		cast->side_dist.y_f = (map.pos_y - cast->map.y_i) *
								cast->delta_dist.y_f;
	}
	else
	{
		cast->step.y_i = 1;
		cast->side_dist.y_f = (cast->map.y_i + 1.0 - map.pos_y) *
								cast->delta_dist.y_f;
	}
}

static void	prep_ray_cast(t_cast *cast, t_path pars, int x, t_map map)
{
	init_camera(cast, pars, x);
	cast->sprit_dst = 0;
	cast->wall_dist = 0;
	cast->map.x_i = map.pos_x;
	cast->map.y_i = map.pos_y;
	cast->delta_dist.y_f = sqrt(1 + (cast->ray_dir.x_f * cast->ray_dir.x_f) /
									(cast->ray_dir.y_f * cast->ray_dir.y_f));
	cast->delta_dist.x_f = sqrt(1 + (cast->ray_dir.y_f * cast->ray_dir.y_f) /
									(cast->ray_dir.x_f * cast->ray_dir.x_f));
	prep_ray_cast2(cast, map);
}

static void	check_side(int *side, t_cast *cast)
{
	if (*side == 1)
	{
		if (cast->ray_dir.y_f < 0)
			*side += 2;
	}
	else
	{
		if (cast->ray_dir.x_f < 0)
			*side += 2;
	}
}

static void	ray_throw(t_cast *cast, int *side, t_cub3d *cub)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cast->side_dist.x_f < cast->side_dist.y_f)
		{
			cast->side_dist.x_f += cast->delta_dist.x_f;
			cast->map.x_i += cast->step.x_i;
			*side = 0;
		}
		else
		{
			cast->side_dist.y_f += cast->delta_dist.y_f;
			cast->map.y_i += cast->step.y_i;
			*side = 1;
		}
		if (cub->map.map[cast->map.y_i][cast->map.x_i] == 1)
			hit = 1;
	}
	check_side(side, cast);
}

void		ray_cast(t_cub3d *cub)
{
	int			x;
	int			side;
	double		tab_wdst[cub->pars.scrwidth];

	check_dir_plane(cub);
	x = 0;
	while (x < cub->pars.scrwidth)
	{
		prep_ray_cast(&cub->cast, cub->pars, x, cub->map);
		ray_throw(&cub->cast, &side, cub);
		if (side == 0 || side == 2)
			tab_wdst[x] = (cub->cast.map.x_i - cub->map.pos_x +
						(1 - cub->cast.step.x_i) / 2) / cub->cast.ray_dir.x_f;
		else
			tab_wdst[x] = (cub->cast.map.y_i - cub->map.pos_y +
						(1 - cub->cast.step.y_i) / 2) / cub->cast.ray_dir.y_f;
		print_img(side, cub, x, tab_wdst[x]);
		x++;
	}
	print_sprit(cub, tab_wdst, cub->map.nb_sprit);
	display(cub);
}
