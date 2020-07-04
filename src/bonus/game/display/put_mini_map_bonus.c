/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_mini_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:30:22 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/30 16:52:13 by vmoreau          ###   ########.fr       */
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

static int		set_color_m_map(int x, int y, t_cub3d *cub, t_image *m_map)
{
	if (cub->map.map[(y * cub->map.y) / m_map->img_h]
					[(x * cub->map.x) / m_map->img_w] == 1)
		return (0xff0000);
	else if (cub->map.map[(y * cub->map.y) / m_map->img_h]
							[(x * cub->map.x) / m_map->img_w] == 2)
		return (0xff);
	else
		return (0x000000);
}

static void		base_m_map(t_cub3d *cub, t_image *m_map)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < m_map->img_h)
	{
		x = 0;
		while (x < m_map->img_w)
		{
			color = set_color_m_map(x, y, cub, m_map);
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
