/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmoreau <vmoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:41 by vmoreau           #+#    #+#             */
/*   Updated: 2020/05/27 18:33:16 by vmoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../header/cub3d.h"

static unsigned char	*file_header_bmp(int filesize)
{
	unsigned char	*bmpfileheader;

	if (!(bmpfileheader = malloc(14 * sizeof(unsigned char))))
		exit(EXIT_FAILURE);
	ft_bzero(bmpfileheader, 14);
	bmpfileheader[0] = 'B';
	bmpfileheader[1] = 'M';
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	bmpfileheader[10] = 54;
	return (bmpfileheader);
}

static unsigned char	*info_header_bmp(t_cub3d *cub)
{
	unsigned char	*bmpinfoheader;

	if (!(bmpinfoheader = malloc(40 * sizeof(unsigned char))))
		exit(EXIT_FAILURE);
	ft_bzero(bmpinfoheader, 40);
	bmpinfoheader[0] = 40;
	bmpinfoheader[4] = (unsigned char)(cub->pars.scrwidth);
	bmpinfoheader[5] = (unsigned char)(cub->pars.scrwidth >> 8);
	bmpinfoheader[6] = (unsigned char)(cub->pars.scrwidth >> 16);
	bmpinfoheader[7] = (unsigned char)(cub->pars.scrwidth >> 24);
	bmpinfoheader[8] = (unsigned char)(cub->pars.scrheight);
	bmpinfoheader[9] = (unsigned char)(cub->pars.scrheight >> 8);
	bmpinfoheader[10] = (unsigned char)(cub->pars.scrheight >> 16);
	bmpinfoheader[11] = (unsigned char)(cub->pars.scrheight >> 24);
	bmpinfoheader[12] = 1;
	bmpinfoheader[14] = 32;
	return (bmpinfoheader);
}

static void				write_data(int file, char *data, t_cub3d *cub)
{
	int		line;
	int		pos;
	int		color;

	line = cub->pars.scrheight - 1;
	while (line >= 0)
	{
		pos = 0;
		while (pos < cub->pars.scrwidth)
		{
			color = *(unsigned int*)(data +
									(line * cub->img.line_length + pos * 4));
			write(file, &color, 4);
			pos++;
		}
		line--;
	}
}

void					save(t_cub3d *cub)
{
	int				filesize;
	int				file;
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;

	filesize = 54 + 4 * cub->pars.scrwidth * cub->pars.scrheight;
	file = open("screenshot/screenshot.bmp", O_WRONLY | O_CREAT |
											O_TRUNC, 0755);
	bmpfileheader = file_header_bmp(filesize);
	write(file, bmpfileheader, 14);
	free(bmpfileheader);
	bmpinfoheader = info_header_bmp(cub);
	write(file, bmpinfoheader, 40);
	free(bmpinfoheader);
	write_data(file, cub->img.adr, cub);
	ft_printf("%s%sSCREENSHOT TAKEN\n", NC, GREEN);
	ft_printf("%sScreenshot stocked in ==> %s", YELLOW, CYAN);
	system("cd screenshot && pwd");
	system("open screenshot/screenshot.bmp");
	ft_printf("%s", NC);
	if (cub->pars.save == 1)
		exit(EXIT_SUCCESS);
}
