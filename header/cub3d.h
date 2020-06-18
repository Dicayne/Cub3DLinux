/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:13:04 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/18 14:24:47 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define FOV 1.25
# define ESC 65307
# define W 119
# define S 115
# define D 100
# define A 97
# define G 65361
# define F 102
# define DR 65363
# define MS 0.05
# define RS 0.040
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/header/libft.h"
# include "color.h"
# include "struct.h"

/*
** ---------------------PARSING---------------------
*/
int				parsing_fd(t_path *pars, t_map *map, char *fdm);
int				pars_map(t_map *map, int fd, char *str2, t_path *pars);
void			free_split(char **split);
int				strlen_c(char *str, char c, char d);
void			fill_8(int **map, int x, int y, int max);
void			from_0_to_8(t_map *map, int y, int x);
int				strisnum(char *str);
int				check_map(t_map *map, t_path *pars);
int				check_closed_map(t_map *map, int y, int x);
void			init_struct_pars(t_path *pars, t_map *map);
t_sp			*fill_sprit(t_map *map, int nb_sprit);
void			set_ret_error(int *ret, t_path *pars);
/*
** -----------------------GAME----------------------
** RAY_CAST
*/
void			start(t_cub3d *cub);
void			ray_cast(t_cub3d *cub);
void			init_camera(t_cast *cast, t_path pars, int x);
void			init_dir(t_map map, t_cast *cast);
void			init_plane(t_cast *cast);
void			check_dir_plane(t_cub3d *cub);
void			init_img_struct(t_cub3d *cub);
void			display(t_cub3d *cub);
void			game_over(t_cub3d *cub);
void			you_win(t_cub3d *cub);
/*
** IMAGES
*/
void			set_images(t_cub3d *cub);
void			print_img(int side, t_cub3d *cub, int x, double dst);
void			print_img3_1(t_print *print, t_cub3d *cub, int side, int x);
void			print_img3_2(t_print *print, t_cub3d *cub, int side, int x);
void			save(t_cub3d *cub);
int				find_pos_y(t_print *print, t_cub3d *cub, t_image *tex);
int				tab_text(t_image *img);
void			my_mlx_pixel_put(t_image *img, int x, int y, int color);
void			init_world_color(t_cub3d *cub, int *sky, int *floor);
void			put_mini_map(t_cub3d *cub);
int				get_img_info(t_image *img, void *mlx_ptr, char *path_tex);
void			print_weap(t_cub3d *cub);
void			print_lifebarre(t_cub3d *cub);
void			print_over_win(t_cub3d *cub, int bool);
/*
** SPRITES
*/
void			print_sprit(t_cub3d *cub, double *wdst, int nb_sprit);
void			find_sp_dst(t_cub3d *cub, int *ord, double *dst);
void			find_color_goal(t_cub3d *cub, double *wdst, t_sprit *sp, int d);
void			find_color_sp(t_cub3d *cub, double *wdst, t_sprit *sp, int d);
/*
** EVENT
*/
int				refresh(t_cub3d *cub);
void			event(t_cub3d *cub);
void			check_key_on(t_cub3d *cub);
void			init_move_ev(t_move	*move);
void			init_speed(t_speed *spe);
int				key_hook(int keycode, t_cub3d *cub);
int				mouse_hook(int button, int x, int y, t_cub3d *cub);
int				check_wall(int x, int y, t_cub3d *cub);
int				key_release(int keycode, t_move *move);
void			move_w_s(t_cub3d *cub, int keycode);
void			move_a_d(t_cub3d *cub, int keycode);
void			rotate_g_dr(t_cub3d *cub, int keycode);
/*
** OTHER
*/
int				close_prog(t_cub3d *cub);
void			free_struct(t_path *pars, t_map *map);
void			free_img(t_image *img);
void			free_tab_int(t_image *img);
int				darkness_mode(int color, double wall_dist);
void			find_goal(t_cub3d *cub, double spd, char id);
void			check_color(t_cub3d *cub);
/*
** A DEGAGER
*/
void			print_int(t_map *coor);
#endif
