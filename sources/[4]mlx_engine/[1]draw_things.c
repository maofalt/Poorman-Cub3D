/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:35:41 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:25:30 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_engine.h"

void	img_pix_put(t_img_data *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	rectangle(t_img_data *img, t_vector_i pos, t_vector_i size, int color)
{
	int	x;
	int	y;

	y = pos[1];
	while (y < pos[1] + size[1])
	{
		x = pos[0];
		while (x < pos[0] + size[0])
		{
			img_pix_put(img, x, y, color);
			x++;
		}
		y++;
	}
}

/*
** Function that draw the celling and floor of the map
** ussing the rectangle function and the color of the celling and floor
** already stored on the map structure
** as well using the  SCREEN_HEIGHT and SCREEN_WIDTH defined on the mlx_engine.h
*/

void	draw_celling_floor(t_cub *data)
{
	t_vector_i	pos;
	t_vector_i	size;
	t_img_data	img;

	img = data->screen;
	pos[0] = 0;
	pos[1] = 0;
	size[0] = WINDOW_WIDTH;
	size[1] = WINDOW_HEIGHT / 2;
	rectangle(&img, pos, size, data->celling);
	pos[0] = 0;
	pos[1] = WINDOW_HEIGHT / 2;
	size[0] = WINDOW_WIDTH;
	size[1] = WINDOW_HEIGHT / 2;
	rectangle(&img, pos, size, data->floor);
}