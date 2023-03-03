/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:02:23 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

/* We render image if update == 1, in this case if a hook or **
**event has modified underlying constants*/
int	ft_render(t_cub *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (data->update)
	{
		draw_celling_floor(data);
		calculate_ray_angle(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->screen.mlx_img, 0, 0);
		data->update = 0;
	}
	return (0);
}

/**
** Caclulate of each ray angle corresponding for each pixel of the screen
** ie each column of the screen
** and store it in the ray_angle array
** The ray start at the player position
** camera_x is the x coordinate on the camera plane th that current x-coordinate
** of the screen represents (this way the right side of the screen is 1 and the
** the center is 0, the left side is -1)
** The direction ray can be calculated as the sum of direction vector and a port 
** of the camera plane vector
** This has to be done for each x-coordinate and y-coordinate of the vector
*/

void	calculate_ray_angle(t_cub *data)
{
	int			x;
	double		camera_x;
	t_dda		*dda;

	dda = &(data->dda);
	x = 0;
	dda->pos = data->player.pos;
	while (x < WINDOW_WIDTH)
	{
		dda->hit = 0;
		camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
		dda->rayDir[0] = data->player.dir[0] + data->player.plane[0] * camera_x;
		dda->rayDir[1] = data->player.dir[1] + data->player.plane[1] * camera_x;
		dda->map = (t_vector_i){(int)dda->pos[0], (int)dda->pos[1]};
		calculate_length_ray(dda);
		calculate_step_side_dist(dda);
		perform_dda(data);
		calculate_distance_projection(data);
		calculate_line_height(data);
		dda->x = x;
		texturise_wall(data);
		x++;
	}
	data->update = 0;
}

//length of ray from one x or y-side to next x or y-side
void	calculate_length_ray(t_dda *dda)
{
	if (dda->rayDir[0] == 0)
		dda->deltaDist[0] = 1e30;
	else
		dda->deltaDist[0] = fabs(1 / dda->rayDir[0]);
	if (dda->rayDir[1] == 0)
		dda->deltaDist[1] = 1e30;
	else
		dda->deltaDist[1] = fabs(1 / dda->rayDir[1]);
}

/*
** caclulate the step and initial sideDist
*/
void	calculate_step_side_dist(t_dda *dda)
{
	if (dda->rayDir[0] < 0)
	{
		dda->step[0] = -1;
		dda->sideDist[0] = (dda->pos[0] - dda->map[0]) * dda->deltaDist[0];
	}
	else
	{
		dda->step[0] = 1;
		dda->sideDist[0] = (dda->map[0] + 1.0
				- dda->pos[0]) * dda->deltaDist[0];
	}
	if (dda->rayDir[1] < 0)
	{
		dda->step[1] = -1;
		dda->sideDist[1] = (dda->pos[1] - dda->map[1]) * dda->deltaDist[1];
	}
	else
	{
		dda->step[1] = 1;
		dda->sideDist[1] = (dda->map[1] + 1.0
				- dda->pos[1]) * dda->deltaDist[1];
	}
}

/*
** perform DDA
*/
void	perform_dda(t_cub *data)
{
	t_dda	*dda;

	dda = &(data->dda);
	while (dda->hit == 0)
	{
		if (dda->sideDist[0] < dda->sideDist[1])
		{
			dda->sideDist[0] += dda->deltaDist[0];
			dda->map[0] += dda->step[0];
			dda->side = 0;
		}
		else
		{
			dda->sideDist[1] += dda->deltaDist[1];
			dda->map[1] += dda->step[1];
			dda->side = 1;
		}
		if (data->map[dda->map[0]][dda->map[1]] == '1')
			dda->hit = 1;
	}
}

/*
** Calculate distance project on camerase direction
*/

void	calculate_distance_projection(t_cub *data)
{
	t_dda	*dda;

	dda = &(data->dda);
	if (dda->side == 0)
		dda->perpWallDist = (dda->sideDist[0] - dda->deltaDist[0]);
	else
		dda->perpWallDist = (dda->sideDist[1] - dda->deltaDist[1]);
}

void	calculate_line_height(t_cub *data)
{
	t_dda	*dda;

	dda = &(data->dda);
	dda->lineHeight = (int)(WINDOW_HEIGHT / dda->perpWallDist);
	dda->drawStart = -dda->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (dda->drawStart < 0)
		dda->drawStart = 0;
	dda->drawEnd = dda->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (dda->drawEnd >= WINDOW_HEIGHT)
		dda->drawEnd = WINDOW_HEIGHT - 1;
}

void	chose_color_wall(t_cub *data)
{
	t_dda	*dda;

	dda = &(data->dda);
	if (dda->side == 0)
	{
		if (dda->rayDir[0] > 0)
			dda->color = 0x00FF0000;
		else
			dda->color = 0x0000FF00;
	}
	else
	{
		if (dda->rayDir[1] > 0)
			dda->color = 0x000000FF;
		else
			dda->color = 0x00FFFF00;
	}
}

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
		if (dda->rayDir[0] > 0)
			tex_num = 3;
		else
			tex_num = 1;
	}
	else
	{
		if (dda->rayDir[1] > 0)
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
		wall_x = dda->pos[1] + dda->perpWallDist * dda->rayDir[1];
	else
		wall_x = dda->pos[0] + dda->perpWallDist * dda->rayDir[0];
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)data->texture[tex_num].size[0]);
	if (dda->side == 0 && dda->rayDir[0] > 0)
		tex_x = data->texture[tex_num].size[0] - tex_x - 1;
	if (dda->side == 1 && dda->rayDir[1] < 0)
		tex_x = data->texture[tex_num].size[0] - tex_x - 1;
	return (tex_x);
}

void	copy_coresponding_pixel(t_cub *data, int tex_num, int tex_x)
{
	const float	step = \
	 1.0 * data->texture[tex_num].size[1] / data->dda.lineHeight;
	float		tex_pos;
	t_dda		*dda;
	int			y;
	int			pixel;
	t_img_data	*img;

	img = (&data->texture[tex_num]);
	dda = &(data->dda);
	tex_pos = (dda->drawStart - WINDOW_HEIGHT / 2 + dda->lineHeight / 2) * step;
	y = dda->drawStart;
	dda->tex_y = (int)tex_pos & (data->texture[tex_num].size[0] - 1);
	while (y < dda->drawEnd)
	{
		dda->tex_y = (int)tex_pos;
		tex_pos += step;
		int addon = dda->tex_y * img->line_len + tex_x * 4;
		pixel = *(unsigned int *)(data->texture[tex_num].addr + addon);
		dda->color = pixel;
		img_pix_put(&((*data).screen), dda->x, y, dda->color);
		y++;
	}
}
