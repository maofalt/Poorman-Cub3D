/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]texture_mapping.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:17:44 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

/*
** Choose the color pixel based on the texture and the side
** of the wall (if the wall is at the NORTH or SOUTH or EAST or WEST)
** and the x position of the wall
** We use wallX  which represents the exact blue where the wall was hit
** It is calculate by calculating the x o y coordinate in te wolrd
** then substracting the integeger value  of the wall off the coordinate
** We use the texture to get the color of the pixel
*/

void	texturise_wall(t_cub *data)
{
	int		tex_num;
	int		tex_x;
	t_dda	*dda;

	dda = &(data->dda);
	tex_num = determine_texture(data);
	tex_x = determine_wall_x_hit(data, tex_num);
	copy_coresponding_pixel(data, tex_num, tex_x);
}

int	determine_texture(t_cub *data)
{
	int		tex_num;
	t_dda	*dda;

	dda = &(data->dda);
	tex_num = 0;
	if (dda->side == 0)
	{
		if (dda->ray_dir[0] > 0)
			tex_num = 3;
		else
			tex_num = 1;
	}
	else
	{
		if (dda->ray_dir[1] > 0)
			tex_num = 2;
		else
			tex_num = 0;
	}
	return (tex_num);
}

int	determine_wall_x_hit(t_cub *data, int tex_num)
{
	float	wall_x;
	int		tex_x;
	t_dda	*dda;

	dda = &(data->dda);
	if (dda->side == 0)
		wall_x = dda->pos[1] + dda->perp_wall_dist * dda->ray_dir[1];
	else
		wall_x = dda->pos[0] + dda->perp_wall_dist * dda->ray_dir[0];
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->texture[tex_num].size[0]);
	if (dda->side == 0 && dda->ray_dir[0] > 0)
		tex_x = data->texture[tex_num].size[0] - tex_x - 1;
	if (dda->side == 1 && dda->ray_dir[1] < 0)
		tex_x = data->texture[tex_num].size[0] - tex_x - 1;
	return (tex_x);
}

void	copy_coresponding_pixel(t_cub *data, int tex_num, int tex_x)
{
	const float	step = \
	1.0 * data->texture[tex_num].size[1] / data->dda.line_height;
	t_dda		*dda;
	int			y;
	int			pixel;
	t_img_data	*img;

	img = (&data->texture[tex_num]);
	dda = &(data->dda);
	dda->tex_pos = (dda->draw_start - WINDOW_HEIGHT / 2
			+ dda->line_height / 2) * step;
	y = dda->draw_start;
	dda->tex_y = (int)dda->tex_pos & (data->texture[tex_num].size[0] - 1);
	while (y < dda->draw_end)
	{
		dda->tex_y = (int)dda->tex_pos;
		dda->tex_pos += step;
		pixel = get_pixel(data, tex_num, tex_x);
		dda->color = pixel;
		img_pix_put(&((*data).screen), dda->x, y, dda->color);
		y++;
	}
}

int	get_pixel(t_cub *data, int tex_num, int tex_x)
{
	int			addon;
	t_img_data	*img;

	img = (&data->texture[tex_num]);
	addon = data->dda.tex_y * img->line_len + tex_x * 4;
	return (*(unsigned int *)(data->texture[tex_num].addr + addon));
}
