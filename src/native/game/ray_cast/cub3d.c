/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 11:18:11 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/30 13:34:37 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void	init_img_struct(t_cub3d *cub)
{
	cub->img.img = mlx_new_image(cub->map.mlx_ptr, cub->pars.scrwidth,
					cub->pars.scrheight);
	cub->img.adr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
					&cub->img.line_length, &cub->img.endian);
	cub->img.img_h = cub->pars.scrheight;
	cub->img.img_w = cub->pars.scrwidth;
	cub->img.iadr = (int*)cub->img.adr;
	tab_text(&cub->img);
	cub->img.free = 1;
	cub->img2.img = mlx_new_image(cub->map.mlx_ptr, cub->pars.scrwidth,
					cub->pars.scrheight);
	cub->img2.adr = mlx_get_data_addr(cub->img2.img, &cub->img2.bits_per_pixel,
					&cub->img2.line_length, &cub->img2.endian);
	cub->img2.img_h = cub->pars.scrheight;
	cub->img2.img_w = cub->pars.scrwidth;
	cub->img2.iadr = (int*)cub->img2.adr;
	tab_text(&cub->img2);
	cub->img2.free = 1;
}

void	corec_reso(t_cub3d *cub)
{
	int sx;
	int sy;

	mlx_get_screen_size(cub->map.mlx_ptr, &sx, &sy);
	if (cub->pars.scrwidth > sx)
		cub->pars.scrwidth = sx;
	if (cub->pars.scrheight > sy)
		cub->pars.scrheight = sy;
}

void	start(t_cub3d *cub)
{
	if ((cub->map.mlx_ptr = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	corec_reso(cub);
	set_images(cub);
	check_color(cub);
	cub->bool = 1;
	cub->boolimg = 1;
	if (cub->pars.save == 0)
	{
		if ((cub->map.mlx_win = mlx_new_window(cub->map.mlx_ptr,
					cub->pars.scrwidth, cub->pars.scrheight, "Cub3D")) == NULL)
			exit(EXIT_FAILURE);
		init_img_struct(cub);
		event(cub);
		mlx_loop(cub->map.mlx_ptr);
	}
	else
	{
		cub->map.mlx_win = NULL;
		init_img_struct(cub);
		ray_cast(cub);
	}
}
