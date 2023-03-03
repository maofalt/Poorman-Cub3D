/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]dda_calculation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:05:15 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
