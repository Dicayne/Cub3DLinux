/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:01:58 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 16:11:58 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			find_pos_y(t_print *print, t_cub3d *cub, t_image *tex)
{
	int		y;
	double	step;
	double	tex_pos;

	y = 0;
	step = 1.0 * tex->img_h / print->line_height;
	tex_pos = (print->draw_start - cub->pars.scrheight / 2
										+ print->line_height / 2) * step;
	if (print->line_height < cub->pars.scrheight)
		return (print->y * tex->img_h / print->line_height);
	else
		return (((int)tex_pos & tex->img_h - 1) + step);
}

static void	print_img2(int side, t_cub3d *cub, int x, double dst)
{
	t_print print;

	print.wall_dist = dst;
	print.start = 0;
	print.line_height = cub->pars.scrheight / print.wall_dist;
	print.draw_start = -print.line_height / 2 + cub->pars.scrheight / 2;
	if (print.draw_start < 0)
		print.draw_start = 0;
	print.draw_end = print.line_height / 2 + cub->pars.scrheight / 2;
	if (print.draw_end >= cub->pars.scrheight)
		print.draw_end = cub->pars.scrheight - 1;
	print.y = 0;
	init_world_color(cub, &print.color_sky, &print.color_floor);
	if (cub->boolimg == 1)
		print_img3_1(&print, cub, side, x);
	else if (cub->boolimg == 2)
		print_img3_2(&print, cub, side, x);
}

void		print_img(int side, t_cub3d *cub, int x, double dst)
{
	cub->cast.pos_tex.x_f = cub->map.pos_y + dst * cub->cast.ray_dir.y_f;
	cub->cast.pos_tex.y_f = cub->map.pos_x + dst * cub->cast.ray_dir.x_f;
	cub->cast.pos_tex.x_i = (cub->cast.pos_tex.x_f -
								(int)cub->cast.pos_tex.x_f) * 1000;
	cub->cast.pos_tex.y_i = (cub->cast.pos_tex.y_f -
								(int)cub->cast.pos_tex.y_f) * 1000;
	print_img2(side, cub, x, dst);
}
