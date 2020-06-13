/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 13:34:12 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/13 02:36:30 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			darkness_mode(int color, double wall_dist)
{
	int		r;
	int		g;
	int		b;
	double	per;

	r = 0xff0000 & color;
	g = 0xff00 & color;
	b = 0xff & color;
	per = 1.0f - wall_dist / 12;
	if (per < 0.0f)
		per = 0.0f;
	else if (per > 1.0f)
		per = 1.0f;
	r = ((int)((double)0x0 + (r - 0x0) * per) & 0xFF0000);
	g = ((int)((double)0x0 + (g - 0x0) * per) & 0xFF00);
	b = ((int)((double)0x0 + (b - 0x0) * per) & 0xFF);
	return (r + g + b);
}

static void	check_endgame(t_cub3d *cub)
{
	if (cub->tex.g_o.g_o == 0)
		game_over(cub);
	if (cub->tex.y_w.g_o == 0)
		you_win(cub);
}

static void	print_hud(t_cub3d *cub)
{
	print_weap(cub);
	print_lifebarre(cub);
	if (cub->pars.scrheight > 300 && cub->pars.scrwidth > 300)
		put_mini_map(cub);
	if (cub->tex.lifbar.hp == 0)
		print_over_win(cub, 0);
	if (cub->map.nb_goal_start == 1 && cub->map.nb_goal == 0)
		print_over_win(cub, 1);
}

static void	display_2(t_cub3d *cub)
{
	check_endgame(cub);
	print_hud(cub);
	mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win,
				cub->img2.img, 0, 0);
	mlx_string_put(cub->map.mlx_ptr, cub->map.mlx_win,
					cub->pars.scrwidth / 2, cub->pars.scrheight / 1.7,
					0xffff, "X");
	if (cub->bool == 1)
		ft_printf("%sGOOD GAME %s:D\n", CYAN, YELLOW);
	cub->bool = 0;
}

void		display(t_cub3d *cub)
{
	if (cub->pars.save == 0 && cub->boolimg == 1)
	{
		check_endgame(cub);
		print_hud(cub);
		mlx_put_image_to_window(cub->map.mlx_ptr, cub->map.mlx_win,
					cub->img.img, 0, 0);
		mlx_string_put(cub->map.mlx_ptr, cub->map.mlx_win,
						cub->pars.scrwidth / 2, cub->pars.scrheight / 1.7,
						0xffff, "X");
		if (cub->bool == 1)
			ft_printf("%sGOOD GAME %s:D\n", CYAN, YELLOW);
		cub->bool = 0;
	}
	else if (cub->pars.save == 0 && cub->boolimg == 2)
		display_2(cub);
	else
		save(cub);
}
