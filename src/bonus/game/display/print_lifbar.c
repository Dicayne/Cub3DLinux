/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lifbar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 11:45:48 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 17:15:35 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void		init_lb(t_cub3d *cub)
{
	free(cub->tex.lifbar.path);
	free_tab_int(&cub->tex.lifbar);
	if (cub->tex.lifbar.hp == 6)
		cub->tex.lifbar.path = ft_strdup("./texture/lb/LBFull.xpm");
	else if (cub->tex.lifbar.hp == 5)
		cub->tex.lifbar.path = ft_strdup("./texture/lb/LB-1.xpm");
	else if (cub->tex.lifbar.hp == 4)
		cub->tex.lifbar.path = ft_strdup("./texture/lb/LB-2.xpm");
	else if (cub->tex.lifbar.hp == 3)
		cub->tex.lifbar.path = ft_strdup("./texture/lb/LB-3.xpm");
	else if (cub->tex.lifbar.hp == 2)
		cub->tex.lifbar.path = ft_strdup("./texture/lb/LB-4.xpm");
	else if (cub->tex.lifbar.hp == 1 || cub->tex.lifbar.hp == 0)
		cub->tex.lifbar.path = ft_strdup("./texture/lb/LB-critical.xpm");
	if (get_img_info(
			&cub->tex.lifbar, cub->map.mlx_ptr, cub->tex.lifbar.path) == -1)
		close_prog(cub);
}

static void		init_img_lb(t_cub3d *cub, t_image *lb)
{
	lb->img_h = cub->pars.scrheight / 10;
	lb->img_w = cub->pars.scrwidth / 4;
	lb->img = mlx_new_image(cub->map.mlx_ptr, lb->img_w, lb->img_h);
	lb->adr = mlx_get_data_addr(lb->img, &lb->bits_per_pixel,
					&lb->line_length, &lb->endian);
}

static void		print(t_image *lb, t_cub3d *cub)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < lb->img_h)
	{
		x = 0;
		while (x < lb->img_w)
		{
			color = mlx_get_color_value(cub->map.mlx_ptr,
				cub->tex.lifbar.tiadr[(cub->tex.lifbar.img_h * y) / lb->img_h]
									[(cub->tex.lifbar.img_w * x) / lb->img_w]);
			if ((unsigned int)color != 0xFF3F48CC && cub->boolimg == 1)
				my_mlx_pixel_put(&cub->img, x, cub->pars.scrheight - (lb->img_h + 2) + y, color);
			if ((unsigned int)color != 0xFF3F48CC && cub->boolimg == 2)
				my_mlx_pixel_put(&cub->img2, x, cub->pars.scrheight - (lb->img_h + 2) + y, color);
			x++;
		}
		y++;
	}
}

void			print_lifebarre(t_cub3d *cub)
{
	t_image		lb;
	static int	hp_b;

	if (cub->bool == 1)
		hp_b = cub->tex.lifbar.hp;
	init_lb(cub);
	init_img_lb(cub, &lb);
	print(&lb, cub);
}
