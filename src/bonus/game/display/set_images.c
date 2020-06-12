/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:14:19 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 17:49:31 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			tab_text(t_image *img)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	img->tiadr = (int**)malloc(sizeof(int*) * img->img_h);
	if (img->tiadr == NULL)
		return (-1);
	while (i < img->img_h)
	{
		j = 0;
		img->tiadr[i] = (int*)malloc(sizeof(int) * img->img_w);
		if (img->tiadr[i] == NULL)
			return (-1);
		while (j < img->img_w)
		{
			img->tiadr[i][j] = img->iadr[k];
			j++;
			k++;
		}
		i++;
	}
	return (0);
}

int			get_img_info(t_image *img, void *mlx_ptr, char *path_tex)
{
	img->img = mlx_xpm_file_to_image(mlx_ptr, path_tex, &img->img_w,
									&img->img_h);
	if (img->img != NULL)
	{
		img->adr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
		img->iadr = (int*)img->adr;
		return (tab_text(img));
	}
	else
	{
		ft_printf("%sError\n", RED);
		ft_printf("%sTexture Error ==> %s%s%s\n", YELLOW, CYAN, path_tex, NC);
		return (-1);
	}
}

static void	set_images2(t_cub3d *cub)
{
	cub->tex.weap.path = ft_strdup("./texture/sprite/shotgun.xpm");
	cub->tex.lifbar.path = ft_strdup("./texture/lb/LBFull.xpm");
	cub->tex.lifbar.hp = 6;
	cub->tex.g_o.path = ft_strdup("./texture/lb/G-O.xpm");
	cub->tex.g_o.g_o = 1;
	cub->tex.goal.path = ft_strdup("./texture/sprite/goal.xpm");
	cub->tex.y_w.path = ft_strdup("./texture/sprite/you_win.xpm");
	cub->tex.y_w.g_o = 1;
	if (get_img_info(
				&cub->tex.weap, cub->map.mlx_ptr, cub->tex.weap.path) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.lifbar, cub->map.mlx_ptr, cub->tex.lifbar.path) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.g_o, cub->map.mlx_ptr, cub->tex.g_o.path) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.goal, cub->map.mlx_ptr, cub->tex.goal.path) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.y_w, cub->map.mlx_ptr, cub->tex.y_w.path) == -1)
		close_prog(cub);
}

void		set_images(t_cub3d *cub)
{
	cub->tex.weap.path = NULL;
	if (get_img_info(
				&cub->tex.tex_no, cub->map.mlx_ptr, cub->pars.pars_no) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.tex_so, cub->map.mlx_ptr, cub->pars.pars_so) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.tex_ea, cub->map.mlx_ptr, cub->pars.pars_ea) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.tex_we, cub->map.mlx_ptr, cub->pars.pars_we) == -1)
		close_prog(cub);
	if (get_img_info(
				&cub->tex.tex_s, cub->map.mlx_ptr, cub->pars.pars_s) == -1)
		close_prog(cub);
	set_images2(cub);
}
