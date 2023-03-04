/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:35:41 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 17:17:34 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_engine.h"

void	rotate_counter_clockwise(t_cub *data, float ratio)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir[0];
	data->player.dir[0] = data->player.dir[0] * cos(-ratio)
		- data->player.dir[1] * sin(-ratio);
	data->player.dir[1] = old_dir_x * sin(-ratio)
		+ data->player.dir[1] * cos(-ratio);
	old_plane_x = data->player.plane[0];
	data->player.plane[0] = data->player.plane[0] * cos(-ratio)
		- data->player.plane[1] * sin(-ratio);
	data->player.plane[1] = old_plane_x * sin(-ratio)
		+ data->player.plane[1] * cos(-ratio);
}

void	rotate_clockwise(t_cub *data, float ratio)
{
	float	old_dir_x;
	float	old_plane_x;

	old_dir_x = data->player.dir[0];
	data->player.dir[0] = data->player.dir[0] * cos(ratio)
		- data->player.dir[1] * sin(ratio);
	data->player.dir[1] = old_dir_x * sin(ratio)
		+ data->player.dir[1] * cos(ratio);
	old_plane_x = data->player.plane[0];
	data->player.plane[0] = data->player.plane[0] * cos(ratio)
		- data->player.plane[1] * sin(ratio);
	data->player.plane[1] = old_plane_x * sin(ratio)
		+ data->player.plane[1] * cos(ratio);
}
