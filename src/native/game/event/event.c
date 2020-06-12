/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 14:45:57 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 18:32:25 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

int			close_prog(t_cub3d *cub)
{
	ft_printf("%sSee you soon %s:'( %s\n", CYAN, YELLOW, NC);
	mlx_clear_window(cub->map.mlx_ptr, cub->map.mlx_win);
	mlx_destroy_window(cub->map.mlx_ptr, cub->map.mlx_win);
	free_struct(&cub->pars, &cub->map);
	system("leaks Cub3D");
	exit(EXIT_SUCCESS);
	return (0);
}

void		event(t_cub3d *cub)
{
	init_move_ev(&cub->move);
	init_speed(&cub->spe);
	mlx_hook(cub->map.mlx_win, 3, 1L << 1, key_release, &cub->move);
	mlx_hook(cub->map.mlx_win, 2, 1L << 0, key_hook, cub);
	mlx_hook(cub->map.mlx_win, 17, 1L << 17, close_prog, cub);
	mlx_loop_hook(cub->map.mlx_ptr, refresh, cub);
}
