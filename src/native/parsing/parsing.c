/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 12:10:14 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 19:15:53 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../header/cub3d.h"

void		free_split(char **split)
{
	int i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	pars_texture(char **split, t_path *pars)
{
	if (pars->pars_no == NULL && ft_strcmp(split[0], "NO") == 0)
		pars->pars_no = ft_strdup(split[1]);
	else if (pars->pars_so == NULL && ft_strcmp(split[0], "SO") == 0)
		pars->pars_so = ft_strdup(split[1]);
	else if (pars->pars_we == NULL && ft_strcmp(split[0], "WE") == 0)
		pars->pars_we = ft_strdup(split[1]);
	else if (pars->pars_ea == NULL && ft_strcmp(split[0], "EA") == 0)
		pars->pars_ea = ft_strdup(split[1]);
	else if (pars->pars_s == NULL && ft_strcmp(split[0], "S") == 0)
		pars->pars_s = ft_strdup(split[1]);
	else if (pars->pars_f == NULL && ft_strcmp(split[0], "F") == 0)
		pars->pars_f = ft_strdup(split[1]);
	else if (pars->pars_c == NULL && ft_strcmp(split[0], "C") == 0)
		pars->pars_c = ft_strdup(split[1]);
	else
		return (-2);
	if (split[2] != NULL)
		return (-2);
	else
		return (1);
}

static int	check_reso(char **split, t_path *pars)
{
	if (pars->scrheight != 0 && pars->scrwidth != 0)
		return (-1);
	if (split[1] != NULL && split[2] != NULL && split[3] == NULL &&
		strisnum(split[1]) == 1 && strisnum(split[2]) == 1)
	{
		pars->scrwidth = ft_atoi(split[1]);
		pars->scrheight = ft_atoi(split[2]);
		if (pars->scrheight > 0 && pars->scrwidth > 0)
			return (1);
		else
			return (-1);
	}
	else
		return (-1);
}

static int	pars_line(char **split, t_path *pars)
{
	int ret;

	if (split[0] == '\0')
		ret = 1;
	else if (ft_strcmp(split[0], "R") == 0)
		ret = check_reso(split, pars);
	else if (ft_strcmp(split[0], "NO") == 0 || ft_strcmp(split[0], "SO") == 0 ||
			ft_strcmp(split[0], "WE") == 0 || ft_strcmp(split[0], "EA") == 0 ||
			ft_strcmp(split[0], "S") == 0 || ft_strcmp(split[0], "F") == 0 ||
			ft_strcmp(split[0], "C") == 0)
		ret = pars_texture(split, pars);
	else if (pars->scrheight != 0 && pars->scrwidth != 0 &&
			pars->pars_no != NULL && pars->pars_so != NULL &&
			pars->pars_ea != NULL && pars->pars_we != NULL &&
			pars->pars_s != NULL && pars->pars_f != NULL &&
			pars->pars_c != NULL && (split[0][0] >= '0' && split[0][0] <= '9'))
		ret = 2;
	else
		ret = -2;
	free_split(split);
	return (ret);
}

int			parsing_fd(t_path *pars, t_map *map, char *fdm)
{
	int		fd;
	char	*str;
	int		ret;
	char	**split;

	str = NULL;
	ret = 1;
	init_struct_pars(pars, map);
	fd = open(fdm, O_RDONLY);
	if (fd == -1)
		ret = -1;
	while (ret == 1)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1 || ret == 0)
			break ;
		split = ft_split(str, ' ');
		ret = pars_line(split, pars);
		if (ret != 2)
			free(str);
	}
	if (ret <= 0)
		set_ret_error(&ret, pars);
	ret == 2 ? ret = pars_map(map, fd, str, pars) : ret;
	return (ret);
}
