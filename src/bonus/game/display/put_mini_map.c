/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mini_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:30:22 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/13 02:38:59 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void		init_img_mmap(t_cub3d *cub, t_image *m_map)
{
	m_map->img_h = cub->pars.scrheight / 4.5;
	m_map->img_w = cub->pars.scrwidth / 4.5;
	m_map->img = mlx_new_image(cub->map.mlx_ptr, m_map->img_w, m_map->img_h);
	m_map->adr = mlx_get_data_addr(m_map->img, &m_map->bits_per_pixel,
					&m_map->line_length, &m_map->endian);
}

static void		print_pos(t_cub3d *cub, t_image *m_map)
{
	int x;
	int y;

	x = ((int)(cub->map.pos_x * 100) * m_map->img_w) / (cub->map.x * 100);
	y = ((int)(cub->map.pos_y * 100) * m_map->img_h) / (cub->map.y * 100);
	if (cub->boolimg == 1)
	{
		my_mlx_pixel_put(&cub->img, x, y, 0xffffff);
		my_mlx_pixel_put(&cub->img, x + 1, y, 0xffffff);
		my_mlx_pixel_put(&cub->img, x, y + 1, 0xffffff);
		my_mlx_pixel_put(&cub->img, x - 1, y, 0xffffff);
		my_mlx_pixel_put(&cub->img, x, y - 1, 0xffffff);
	}
	if (cub->boolimg == 2)
	{
		my_mlx_pixel_put(&cub->img2, x, y, 0xffffff);
		my_mlx_pixel_put(&cub->img2, x + 1, y, 0xffffff);
		my_mlx_pixel_put(&cub->img2, x, y + 1, 0xffffff);
		my_mlx_pixel_put(&cub->img2, x - 1, y, 0xffffff);
		my_mlx_pixel_put(&cub->img2, x, y - 1, 0xffffff);
	}
}

static void		back_map(t_image *m_map, t_cub3d *cub)
{
	int x;
	int y;
	int color;

	color = 0xa6000000;
	y = 0;
	while (y < m_map->img_h)
	{
		x = 0;
		while (x < m_map->img_w)
		{
			if (cub->boolimg == 1)
				my_mlx_pixel_put(&cub->img, x, y, color);
			if (cub->boolimg == 2)
				my_mlx_pixel_put(&cub->img2, x, y, color);
			x++;
		}
		y++;
	}
}

static void		base_m_map(t_cub3d *cub, t_image *m_map)
{
	int x;
	int y;
	int color;

	back_map(m_map, cub);
	y = 0;
	while (y < m_map->img_h)
	{
		x = 0;
		while (x < m_map->img_w)
		{
			if (cub->map.map[(y * cub->map.y) / m_map->img_h]
							[(x * cub->map.x) / m_map->img_w] == 1)
				color = 0xff0000;
			if (cub->map.map[(y * cub->map.y) / m_map->img_h]
							[(x * cub->map.x) / m_map->img_w] == 2)
				color = 0xff;
			if (cub->boolimg == 1)
				my_mlx_pixel_put(&cub->img, x, y, color);
			if (cub->boolimg == 2)
				my_mlx_pixel_put(&cub->img2, x, y, color);
			x++;
		}
		y++;
	}
	print_pos(cub, m_map);
}

void			put_mini_map(t_cub3d *cub)
{
	t_image m_map;

	init_img_mmap(cub, &m_map);
	base_m_map(cub, &m_map);
	mlx_destroy_image(cub->map.mlx_ptr, m_map.img);
}
