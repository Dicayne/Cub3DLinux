/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:45:57 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/18 14:41:20 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static void		free_img_bis(t_image *img, t_cub3d *cub)
{
	if (img->free == 1 && img->img != NULL)
	{
		mlx_destroy_image(cub->map.mlx_ptr, img->img);
		free(img->path);
		free_tab_int(img);
	}
}

static void		free_mlx_ptr(void *mlx_ptr)
{
	struct s_xvar	*xvar;

	xvar = mlx_ptr;
	if (xvar->private_cmap)
		XFreeColormap(xvar->display, (Colormap)xvar->private_cmap);
	XCloseDisplay(xvar->display);
	free(xvar);
}

int				close_prog(t_cub3d *cub)
{
	if (cub->bool != 4)
	{
		ft_printf("%sSee you soon %s:'( %s\n", CYAN, YELLOW, NC);
		mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
		mlx_destroy_window(cub->map.mlx_ptr, cub->map.mlx_win);
	}
	free_img_bis(&cub->tex.tex_no, cub);
	free_img_bis(&cub->tex.tex_so, cub);
	free_img_bis(&cub->tex.tex_ea, cub);
	free_img_bis(&cub->tex.tex_we, cub);
	free_img_bis(&cub->tex.tex_s, cub);
	free_img_bis(&cub->img, cub);
	free_img_bis(&cub->img2, cub);
	free_struct(&cub->pars, &cub->map);
	free_mlx_ptr(cub->map.mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

int				close_prog_cross(t_cub3d *cub)
{
	if (cub->bool != 4)
	{
		ft_printf("%sSee you soon %s:'( %s\n", CYAN, YELLOW, NC);
		mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
		mlx_destroy_window(cub->map.mlx_ptr, cub->map.mlx_win);
	}
	free_img_bis(&cub->tex.tex_no, cub);
	free_img_bis(&cub->tex.tex_so, cub);
	free_img_bis(&cub->tex.tex_ea, cub);
	free_img_bis(&cub->tex.tex_we, cub);
	free_img_bis(&cub->tex.tex_s, cub);
	free_img_bis(&cub->img, cub);
	free_img_bis(&cub->img2, cub);
	free_struct(&cub->pars, &cub->map);
	free(cub->map.mlx_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}

void			event(t_cub3d *cub)
{
	init_move_ev(&cub->move);
	init_speed(&cub->spe);
	mlx_hook(cub->map.mlx_win, 3, 1L << 1, key_release, &cub->move);
	mlx_hook(cub->map.mlx_win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->map.mlx_win, 33, 1L << 17, close_prog_cross, cub);
	mlx_loop_hook(cub->map.mlx_ptr, refresh, cub);
}
