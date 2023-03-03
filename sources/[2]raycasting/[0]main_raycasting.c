/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]main_raycasting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:07:58 by motero           ###   ########.fr       */
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
