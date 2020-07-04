/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:34:06 by vmoreau           #+#    #+#             */
/*   Updated: 2020/06/25 18:23:17 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_sp
{
	double	x;
	double	y;
	int		bool;
}				t_sp;
typedef struct	s_print
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		color;
	int		y;
	int		start;
	int		color_sky;
	int		color_floor;
	double	wall_dist;
}				t_print;

typedef struct	s_speed
{
	double rot_spe;
	double mov_spe;
}				t_speed;
typedef struct	s_move
{
	int w_on;
	int s_on;
	int a_on;
	int d_on;
	int g_on;
	int dr_on;
	int dm;
	int shot;
	int sprint;
	int slow;
}				t_move;
typedef struct	s_map
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;
	int		**map;
	double	pos_x;
	double	pos_y;
	char	dir;
	int		nb_sprit;
	int		bool_sprit;
	int		nb_goal;
	int		nb_goal_start;
	t_sp	*sprit;
}				t_map;
typedef struct	s_path
{
	int		scrwidth;
	int		scrheight;
	int		save;
	char	*pars_no;
	char	*pars_so;
	char	*pars_ea;
	char	*pars_we;
	char	*pars_s;
	char	*pars_f;
	char	*pars_c;
	char	*error;
}				t_path;
typedef struct	s_coor_vec
{
	double	x_f;
	double	y_f;
	int		x_i;
	int		y_i;
}				t_coor_vec;
typedef struct	s_sprit
{
	t_coor_vec	sprite;
	t_coor_vec	trans;
	t_coor_vec	sp_size;
	t_coor_vec	draw_start;
	t_coor_vec	draw_end;
	t_coor_vec	tex;
	int			scr_x;
	int			color;
}				t_sprit;
typedef struct	s_cast
{
	t_coor_vec	dir;
	t_coor_vec	plane;
	t_coor_vec	ray_dir;
	t_coor_vec	side_dist;
	t_coor_vec	delta_dist;
	t_coor_vec	map;
	t_coor_vec	step;
	t_coor_vec	pos_tex;
	double		wall_dist;
	double		*sprit_dst;
	int			sprit_side;
}				t_cast;
typedef struct	s_image
{
	void	*img;
	void	*adr;
	char	*path;
	int		*iadr;
	int		**tiadr;
	int		hp;
	int		g_o;
	int		free;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		img_h;
	int		img_w;
	double	dist;
}				t_image;
typedef struct	s_tex
{
	t_image tex_no;
	t_image tex_so;
	t_image tex_ea;
	t_image tex_we;
	t_image tex_s;
	t_image weap;
	t_image lifbar;
	t_image g_o;
	t_image goal;
	t_image y_w;
}				t_tex;
typedef struct	s_cub3d
{
	t_map	map;
	t_path	pars;
	t_cast	cast;
	t_image img;
	t_image img2;
	t_tex	tex;
	t_move	move;
	t_speed spe;
	int		bool;
	int		boolimg;
}				t_cub3d;

#endif
