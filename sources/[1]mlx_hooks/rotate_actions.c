/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:35:41 by motero            #+#    #+#             */
/*   Updated: 2023/03/03 18:02:45 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_engine.h"

void	rotate_counter_clockwise(t_cub *data)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir[0];
	data->player.dir[0] = data->player.dir[0] * cos(-0.1)
		- data->player.dir[1] * sin(-0.1);
	data->player.dir[1] = old_dir_x * sin(-0.1)
		+ data->player.dir[1] * cos(-0.1);
	old_plane_x = data->player.plane[0];
	data->player.plane[0] = data->player.plane[0] * cos(-0.1)
		- data->player.plane[1] * sin(-0.1);
	data->player.plane[1] = old_plane_x * sin(-0.1)
		+ data->player.plane[1] * cos(-0.1);
}

void	rotate_clockwise(t_cub *data)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir[0];
	data->player.dir[0] = data->player.dir[0] * cos(0.1)
		- data->player.dir[1] * sin(0.1);
	data->player.dir[1] = old_dir_x * sin(0.1) + data->player.dir[1] * cos(0.1);
	old_plane_x = data->player.plane[0];
	data->player.plane[0] = data->player.plane[0] * cos(0.1)
		- data->player.plane[1] * sin(0.1);
	data->player.plane[1] = old_plane_x * sin(0.1)
		+ data->player.plane[1] * cos(0.1);
}
