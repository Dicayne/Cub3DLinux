/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_ev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:21:39 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:45:57 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void	init_move_ev(t_move *move)
{
	move->w_on = 0;
	move->s_on = 0;
	move->a_on = 0;
	move->d_on = 0;
	move->g_on = 0;
	move->dr_on = 0;
	move->dm = 0;
}

void	init_speed(t_speed *spe)
{
	spe->mov_spe = 0;
	spe->rot_spe = 0;
}
