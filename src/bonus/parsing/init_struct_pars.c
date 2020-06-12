/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_pars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 18:13:20 by vmoreau           #+#    #+#             */
/*   Updated: 2020/04/08 16:47:44 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

void		init_struct_pars(t_path *pars, t_map *map)
{
	pars->scrheight = 0;
	pars->scrwidth = 0;
	pars->pars_no = NULL;
	pars->pars_so = NULL;
	pars->pars_ea = NULL;
	pars->pars_we = NULL;
	pars->pars_s = NULL;
	pars->pars_f = NULL;
	pars->pars_c = NULL;
	pars->error = NULL;
	map->x = 0;
	map->y = 0;
	map->pos_x = -1;
	map->pos_y = -1;
	map->dir = '\0';
	map->nb_sprit = 0;
}

static void	free_map(t_map *map)
{
	int y;

	y = 0;
	while (y < map->y)
	{
		free(map->map[y]);
		y++;
	}
	free(map->map);
}

void		free_tab_int(t_image *img)
{
	int y;

	y = 0;
	while (y < img->img_h)
	{
		free(img->tiadr[y]);
		y++;
	}
	free(img->tiadr);
}

void		free_img(t_image *img)
{
	img->img != NULL ? free(img->img) : img->img;
	img->path != NULL ? free(img->path) : img->path;
	free_tab_int(img);
}

void		free_struct(t_path *pars, t_map *map)
{
	pars->pars_no != NULL ? free(pars->pars_no) : pars->pars_no;
	pars->pars_so != NULL ? free(pars->pars_so) : pars->pars_so;
	pars->pars_we != NULL ? free(pars->pars_we) : pars->pars_we;
	pars->pars_ea != NULL ? free(pars->pars_ea) : pars->pars_ea;
	pars->pars_s != NULL ? free(pars->pars_s) : pars->pars_s;
	pars->pars_f != NULL ? free(pars->pars_f) : pars->pars_f;
	pars->pars_c != NULL ? free(pars->pars_c) : pars->pars_c;
	pars->error != NULL ? free(pars->error) : pars->error;
	if (map->x != 0)
		free_map(map);
	free(map->sprit);
}
