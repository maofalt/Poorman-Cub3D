/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/03/02 18:42:18 by motero           ###   ########.fr       */
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
** cameraX is the x coordinate on the camera plane th that current x-coordinate
** of the screen represents (this way the right side of the screen is 1 and the
** the center is 0, the left side is -1)
** The direction ray can be calculated as the sum of direction vector and a port 
** of the camera plane vector
** This has to be done for each x-coordinate and y-coordinate of the vector
*/

void	calculate_ray_angle(t_cub *data)
{
	int			x;
	int			y;
	double		cameraX;
	t_dda		*dda;

	dda = &(data->dda);
	x = 0;
	dda->pos = data->player.pos;
	// printf("player pos: %f, %f\n", dda->pos[0], dda->pos[1]);
	// printf("player dir: %f, %f\n", data->player.dir[0], data->player.dir[1]);
	// printf("player plane: %f, %f\n---------------------\n", data->player.plane[0], data->player.plane[1]);
	while (x < WINDOW_WIDTH)
	{
		dda->hit = 0;
		cameraX = 2 * x / (double)WINDOW_WIDTH - 1;
		dda->rayDir[0] = data->player.dir[0] + data->player.plane[0] * cameraX;
		dda->rayDir[1] = data->player.dir[1] + data->player.plane[1] * cameraX;
		//which box of the map we're in
		dda->map = (t_vector_i){(int)dda->pos[0], (int)dda->pos[1]};
		//printf("map: %d, %d\n", dda->map[0], dda->map[1]);
		calculate_length_ray(dda);
		//printf("before sideDist[0] = %f, sideDist[1] = %f\n", dda->sideDist[0], dda->sideDist[1]);
		calculate_step_sideDist(dda);
		//printf("after sideDist[0] = %f, sideDist[1] = %f\n", dda->sideDist[0], dda->sideDist[1]);
		perform_dda(data);
		calculate_distance_projection(data);
		calculate_line_height(data);
		chose_color_wall(data);
		y = dda->drawStart;
	//	printf("drawStart: %d, drawEnd: %d\n===========\n", dda->drawStart, dda->drawEnd);
		while (y <= dda->drawEnd)
		{
			img_pix_put(&((*data).screen), x, y, dda->color);
			y++;
		}
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
	//printf("deltaDist[0] = %f, deltaDist[1] = %f\n", dda->deltaDist[0], dda->deltaDist[1]);
}

/*
** caclulate the step and initial sideDist
*/
void	calculate_step_sideDist(t_dda *dda)
{
	if (dda->rayDir[0] < 0)
	{
		dda->step[0] = -1;
		dda->sideDist[0] = (dda->pos[0] - dda->map[0]) * dda->deltaDist[0];
	}
	else
	{
		dda->step[0] = 1;
		dda->sideDist[0] = (dda->map[0] + 1.0 - dda->pos[0]) * dda->deltaDist[0];
	}
	if (dda->rayDir[1] < 0)
	{
		dda->step[1] = -1;
		dda->sideDist[1] = (dda->pos[1] - dda->map[1]) * dda->deltaDist[1];
	}
	else
	{
		dda->step[1] = 1;
		dda->sideDist[1] = (dda->map[1] + 1.0 - dda->pos[1]) * dda->deltaDist[1];
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
		//printf("sideDist[0] = %f, sideDist[1] = %f\n", dda->sideDist[0], dda->sideDist[1]);
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
		printf("map[0] = %d, map[1] = %d\n", dda->map[0], dda->map[1]);
		//printf("map[%d][%d] = |%c|\n", dda->map[0], dda->map[1], data->map[dda->map[0]][dda->map[1]]);
		if (data->map[dda->map[0]][dda->map[1]] == '1')
		{
		//	printf("hit  at map[%d][%d] = |%c|\n", dda->map[0], dda->map[1], data->map[dda->map[0]][dda->map[1]]);
			dda->hit = 1;
		}
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
	//printf("perpWallDist = %f\n", dda->perpWallDist);
}

void	calculate_line_height(t_cub *data)
{
	t_dda	*dda;

	//printf("----calculate line height------\n");
	dda = &(data->dda);
	dda->lineHeight = (int)(WINDOW_HEIGHT / dda->perpWallDist);
	//printf("lineHeight = %d\n", dda->lineHeight);
	dda->drawStart = -dda->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (dda->drawStart < 0)
		dda->drawStart = 0;
	//printf("drawStart = %d\n", dda->drawStart);
	dda->drawEnd = dda->lineHeight / 2 + WINDOW_HEIGHT / 2;
	if (dda->drawEnd >= WINDOW_HEIGHT)
		dda->drawEnd = WINDOW_HEIGHT - 1;
	// printf("drawEnd = %d\n", dda->drawEnd);
	// printf("----end calculate line height------\n");
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