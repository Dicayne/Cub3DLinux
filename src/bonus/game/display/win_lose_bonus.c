/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:03:06 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/25 18:24:35 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

void		game_over(t_cub3d *cub)
{
	system("aplay -q ./sound/g-o-music.wav");
	system("aplay -q ./sound/g-o-voice.wav");
	close_prog(cub);
}

void		you_win(t_cub3d *cub)
{
	system("aplay -q ./sound/y_w_music.wav");
	system("aplay -q ./sound/y_w_voice.wav");
	close_prog(cub);
}
