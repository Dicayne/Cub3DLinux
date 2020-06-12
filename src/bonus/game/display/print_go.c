/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_go.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 13:55:46 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 18:13:32 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void		init_img_g_o(t_cub3d *cub, t_image *g_o)
{
	g_o->img_h = cub->pars.scrheight / 1.5;
	g_o->img_w = cub->pars.scrwidth / 1.5;
	g_o->img = mlx_new_image(cub->map.mlx_ptr, g_o->img_w, g_o->img_h);
	g_o->adr = mlx_get_data_addr(g_o->img, &g_o->bits_per_pixel,
					&g_o->line_length, &g_o->endian);
}

static void		print_2(t_image *g_o, t_cub3d *cub, t_coor_vec l, int color)
{
	my_mlx_pixel_put(&cub->img,
			cub->pars.scrwidth / 2 - (g_o->img_w / 2) + l.x_i,
			cub->pars.scrheight / 4 + l.y_i, color);
	my_mlx_pixel_put(&cub->img2,
			cub->pars.scrwidth / 2 - (g_o->img_w / 2) + l.x_i,
			cub->pars.scrheight / 4 + l.y_i, color);
}

static void		print(t_image *g_o, t_cub3d *cub, int bool)
{
	t_coor_vec l;
	int color;

	l.y_i = 0;
	while (l.y_i < g_o->img_h)
	{
		l.x_i = 0;
		while (l.x_i < g_o->img_w)
		{
			if (bool == 0)
				color = mlx_get_color_value(cub->map.mlx_ptr,
					cub->tex.g_o.tiadr[(cub->tex.g_o.img_h * l.y_i) / g_o->img_h]
								[(cub->tex.g_o.img_w * l.x_i) / g_o->img_w]);
			else if (bool == 1)
				color = mlx_get_color_value(cub->map.mlx_ptr,
					cub->tex.y_w.tiadr[(cub->tex.y_w.img_h * l.y_i) / g_o->img_h]
								[(cub->tex.y_w.img_w * l.x_i) / g_o->img_w]);
			if ((unsigned int)color != 0xFF3F48CC)
				print_2(g_o, cub, l, color);
			l.x_i++;
		}
		l.y_i++;
	}
}

void			print_over_win(t_cub3d *cub, int bool)
{
	t_image		g_o;

	init_img_g_o(cub, &g_o);
	print(&g_o, cub, bool);
	if (bool == 0)
		cub->tex.g_o.g_o = 0;
	else if (bool == 1)
		cub->tex.y_w.g_o = 0;
}
