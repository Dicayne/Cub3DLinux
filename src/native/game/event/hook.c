/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:27:12 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/12 18:02:25 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			key_release(int keycode, t_move *move)
{
	if (keycode == W)
		move->w_on = 0;
	if (keycode == S)
		move->s_on = 0;
	if (keycode == A)
		move->a_on = 0;
	if (keycode == D)
		move->d_on = 0;
	if (keycode == G)
		move->g_on = 0;
	if (keycode == DR)
		move->dr_on = 0;
	return (0);
}

int			key_push(int keycode, t_move *move)
{
	if (keycode == W)
		move->w_on = 1;
	if (keycode == S)
		move->s_on = 1;
	if (keycode == A)
		move->a_on = 1;
	if (keycode == D)
		move->d_on = 1;
	if (keycode == G)
		move->g_on = 1;
	if (keycode == DR)
		move->dr_on = 1;
	if (keycode == 116 && move->dm == 0)
		move->dm = 1;
	else if (keycode == 116 && move->dm == 1)
		move->dm = 0;
	return (0);
}

int			key_hook(int keycode, t_cub3d *cub)
{
	key_push(keycode, &cub->move);
	if (keycode == ESC)
		close_prog(cub);
	if (keycode == 78 && cub->spe.rot_spe + RS > 0.0051)
		cub->spe.rot_spe -= 0.005;
	if (keycode == 69 && cub->spe.rot_spe + RS < 0.25)
		cub->spe.rot_spe += 0.005;
	if (keycode == 65364 && cub->spe.mov_spe + MS > 0.02)
		cub->spe.mov_spe -= 0.01;
	if (keycode == 65362 && cub->spe.mov_spe + MS < 0.2)
		cub->spe.mov_spe += 0.01;
	if (keycode == F)
		save(cub);
	return (0);
}
