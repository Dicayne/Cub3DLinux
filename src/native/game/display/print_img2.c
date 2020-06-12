/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:01:58 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 18:45:23 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	find_color(int side, t_print *print, t_cub3d *cub)
{
	if (side == 3)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
			cub->tex.tex_no.tiadr[find_pos_y(print, cub, &cub->tex.tex_no)]
				[(cub->cast.pos_tex.y_i * cub->tex.tex_no.img_w) / 1000]);
	else if (side == 1)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_so.tiadr[find_pos_y(print, cub, &cub->tex.tex_so)]
					[(cub->cast.pos_tex.y_i * cub->tex.tex_so.img_w) / 1000]);
	else if (side == 0)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_ea.tiadr[find_pos_y(print, cub, &cub->tex.tex_ea)]
					[(cub->cast.pos_tex.x_i * cub->tex.tex_ea.img_w) / 1000]);
	else if (side == 2)
		print->color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.tex_we.tiadr[find_pos_y(print, cub, &cub->tex.tex_we)]
					[(cub->cast.pos_tex.x_i * cub->tex.tex_we.img_w) / 1000]);
	if (cub->move.dm == 1)
		print->color = darkness_mode(print->color, print->wall_dist);
}

void		print_img3_1(t_print *print, t_cub3d *cub, int side, int x)
{
	while (print->start < print->draw_start)
	{
		if (cub->move.dm == 1)
			my_mlx_pixel_put(&cub->img, x, print->start, 0);
		else
			my_mlx_pixel_put(&cub->img, x, print->start, print->color_sky);
		print->start++;
	}
	while (print->draw_start < print->draw_end)
	{
		find_color(side, print, cub);
		my_mlx_pixel_put(&cub->img, x, print->draw_start, print->color);
		print->draw_start++;
		print->y++;
	}
	while (print->draw_end < cub->pars.scrheight - 1)
	{
		if (cub->move.dm == 1)
			my_mlx_pixel_put(&cub->img, x, print->draw_end, 0);
		else
			my_mlx_pixel_put(&cub->img, x, print->draw_end, print->color_floor);
		print->draw_end++;
	}
}

void		print_img3_2(t_print *print, t_cub3d *cub, int side, int x)
{
	while (print->start < print->draw_start)
	{
		if (cub->move.dm == 1)
			my_mlx_pixel_put(&cub->img2, x, print->start, 0);
		else
			my_mlx_pixel_put(&cub->img2, x, print->start, print->color_sky);
		print->start++;
	}
	while (print->draw_start < print->draw_end)
	{
		find_color(side, print, cub);
		my_mlx_pixel_put(&cub->img2, x, print->draw_start, print->color);
		print->draw_start++;
		print->y++;
	}
	while (print->draw_end < cub->pars.scrheight - 1)
	{
		if (cub->move.dm == 1)
			my_mlx_pixel_put(&cub->img2, x, print->draw_end, 0);
		else
			my_mlx_pixel_put(&cub->img2, x, print->draw_end,
							print->color_floor);
		print->draw_end++;
	}
}
