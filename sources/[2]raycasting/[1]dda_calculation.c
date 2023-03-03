/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]dda_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:17:44 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//length of ray from one x or y-side to next x or y-side
void	calculate_length_ray(t_dda *dda)
{
	if (dda->ray_dir[0] == 0)
		dda->delta_dist[0] = 1e30;
	else
		dda->delta_dist[0] = fabs(1 / dda->ray_dir[0]);
	if (dda->ray_dir[1] == 0)
		dda->delta_dist[1] = 1e30;
	else
		dda->delta_dist[1] = fabs(1 / dda->ray_dir[1]);
}

/*
** caclulate the step and initial side_dist
*/
void	calculate_step_side_dist(t_dda *dda)
{
	if (dda->ray_dir[0] < 0)
	{
		dda->step[0] = -1;
		dda->side_dist[0] = (dda->pos[0] - dda->map[0]) * dda->delta_dist[0];
	}
	else
	{
		dda->step[0] = 1;
		dda->side_dist[0] = (dda->map[0] + 1.0
				- dda->pos[0]) * dda->delta_dist[0];
	}
	if (dda->ray_dir[1] < 0)
	{
		dda->step[1] = -1;
		dda->side_dist[1] = (dda->pos[1] - dda->map[1]) * dda->delta_dist[1];
	}
	else
	{
		dda->step[1] = 1;
		dda->side_dist[1] = (dda->map[1] + 1.0
				- dda->pos[1]) * dda->delta_dist[1];
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
		if (dda->side_dist[0] < dda->side_dist[1])
		{
			dda->side_dist[0] += dda->delta_dist[0];
			dda->map[0] += dda->step[0];
			dda->side = 0;
		}
		else
		{
			dda->side_dist[1] += dda->delta_dist[1];
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
		dda->perp_wall_dist = (dda->side_dist[0] - dda->delta_dist[0]);
	else
		dda->perp_wall_dist = (dda->side_dist[1] - dda->delta_dist[1]);
}

void	calculate_line_height(t_cub *data)
{
	t_dda	*dda;

	dda = &(data->dda);
	dda->line_height = (int)(WINDOW_HEIGHT / dda->perp_wall_dist);
	dda->draw_start = -dda->line_height / 2 + WINDOW_HEIGHT / 2;
	if (dda->draw_start < 0)
		dda->draw_start = 0;
	dda->draw_end = dda->line_height / 2 + WINDOW_HEIGHT / 2;
	if (dda->draw_end >= WINDOW_HEIGHT)
		dda->draw_end = WINDOW_HEIGHT - 1;
}
