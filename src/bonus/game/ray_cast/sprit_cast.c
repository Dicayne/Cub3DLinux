/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprit_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:21:54 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 16:16:46 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void	print_color(t_cub3d *cub, t_sprit *sp, int y)
{
	if (cub->boolimg == 1)
		if ((sp->color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&cub->img, sp->draw_start.x_i, y, sp->color);
	if (cub->boolimg == 2)
		if ((sp->color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&cub->img2, sp->draw_start.x_i, y, sp->color);
}

static void	print_sprit3(t_cub3d *cub, t_sprit *sp)
{
	sp->scr_x = (int)(cub->pars.scrwidth / 2) *
											(1 + sp->trans.x_f / sp->trans.y_f);
	sp->sp_size.y_i = abs((int)(cub->pars.scrheight / (sp->trans.y_f)));
	sp->sp_size.x_i = abs((int)(cub->pars.scrheight / (sp->trans.y_f)));
	sp->draw_start.y_i = -sp->sp_size.y_i / 2 + cub->pars.scrheight / 2;
	if (sp->draw_start.y_i < 0)
		sp->draw_start.y_i = 0;
	sp->draw_end.y_i = sp->sp_size.y_i / 2 + cub->pars.scrheight / 2;
	if (sp->draw_end.y_i >= cub->pars.scrheight)
		sp->draw_end.y_i = cub->pars.scrheight - 1;
	sp->draw_start.x_i = -sp->sp_size.x_i / 2 + sp->scr_x;
	if (sp->draw_start.x_i < 0)
		sp->draw_start.x_i = 0;
	sp->draw_end.x_i = sp->sp_size.x_i / 2 + sp->scr_x;
	if (sp->draw_end.x_i >= cub->pars.scrwidth)
		sp->draw_end.x_i = cub->pars.scrwidth - 1;
}

static void	find_tex_x(t_cub3d *cub, t_sprit *sp, int bool)
{
	if (bool == 2)
		sp->tex.x_i = ((sp->draw_start.x_i - (-sp->sp_size.x_i / 2 + sp->scr_x))
						* cub->tex.tex_s.img_w / sp->sp_size.x_i);
	else
		sp->tex.x_i = ((sp->draw_start.x_i - (-sp->sp_size.x_i / 2 + sp->scr_x))
						* cub->tex.goal.img_w / sp->sp_size.x_i);
}

static void	print_sprit2(t_cub3d *cub, double *wdst, t_sprit *sp, int bool)
{
	int d;
	int y;

	print_sprit3(cub, sp);
	while (sp->draw_start.x_i < sp->draw_end.x_i)
	{
		find_tex_x(cub, sp, bool);
		y = sp->draw_start.y_i;
		if (sp->trans.y_f > 0 && sp->draw_start.x_i > 0 &&
			sp->draw_start.x_i < cub->pars.scrwidth &&
			sp->trans.y_f < wdst[sp->draw_start.x_i])
			while (y < sp->draw_end.y_i)
			{
				d = y * 256 - cub->pars.scrheight * 128 + sp->sp_size.y_i * 128;
				if (bool == 2)
					find_color_sp(cub, wdst, sp, d);
				else
					find_color_goal(cub, wdst, sp, d);
				print_color(cub, sp, y);
				y++;
			}
		sp->draw_start.x_i++;
	}
}

void		print_sprit(t_cub3d *cub, double *wdst, int nb_sprit)
{
	int		ord[nb_sprit];
	double	dst[nb_sprit];
	int		i;
	t_sprit	sp;
	double	mult;

	find_sp_dst(cub, ord, dst);
	i = 0;
	while (i < nb_sprit)
	{
		sp.sprite.x_f = cub->map.sprit[ord[i]].x - cub->map.pos_x;
		sp.sprite.y_f = cub->map.sprit[ord[i]].y - cub->map.pos_y;
		mult = 1.0 / (cub->cast.plane.x_f * cub->cast.dir.y_f -
						cub->cast.dir.x_f * cub->cast.plane.y_f);
		sp.trans.x_f = mult * (cub->cast.dir.y_f * sp.sprite.x_f -
						cub->cast.dir.x_f * sp.sprite.y_f);
		sp.trans.y_f = mult * (-cub->cast.plane.y_f * sp.sprite.x_f +
						cub->cast.plane.x_f * sp.sprite.y_f);
		print_sprit2(cub, wdst, &sp, cub->map.sprit[ord[i]].bool);
		i++;
	}
}
