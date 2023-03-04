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

void	move_forward(t_cub *data)
{
	t_dda			dda;
	t_player		player;
	t_vector_i		next_coord;
	const float		move_speed = 0.35;

	dda = data->dda;
	player = data->player;
	next_coord[0] = (int)(dda.pos[0] + player.dir[0] * move_speed);
	next_coord[1] = (int)(dda.pos[1] + player.dir[1] * move_speed);
	if (data->map[next_coord[0]][(int)(dda.pos[1])] != '1')
		data->player.pos[0] += player.dir[0] * move_speed;
	if (data->map[(int)(dda.pos[0])][next_coord[1]] != '1')
		data->player.pos[1] += player.dir[1] * move_speed;
}

void	move_backward(t_cub *data)
{
	t_dda			dda;
	t_player		player;
	t_vector_i		next_coord;
	const float		move_speed = 0.35;

	dda = data->dda;
	player = data->player;
	next_coord[0] = (int)(dda.pos[0] - player.dir[0] * move_speed);
	next_coord[1] = (int)(dda.pos[1] - player.dir[1] * move_speed);
	if (data->map[next_coord[0]][(int)(dda.pos[1])] != '1')
		data->player.pos[0] -= player.dir[0] * move_speed;
	if (data->map[(int)(dda.pos[0])][next_coord[1]] != '1')
		data->player.pos[1] -= player.dir[1] * move_speed;
}	

void	move_left(t_cub *data)
{
	t_dda			dda;
	t_player		player;
	t_vector_i		next_coord;
	const float		move_speed = 0.35;

	dda = data->dda;
	player = data->player;
	next_coord[0] = (int)(dda.pos[0] - player.plane[0] * move_speed);
	next_coord[1] = (int)(dda.pos[1] - player.plane[1] * move_speed);
	if (data->map[next_coord[0]][(int)(dda.pos[1])] != '1')
		data->player.pos[0] -= player.plane[0] * move_speed;
	if (data->map[(int)(dda.pos[0])][next_coord[1]] != '1')
		data->player.pos[1] -= player.plane[1] * move_speed;
}

void	move_right(t_cub *data)
{
	t_dda			dda;
	t_player		player;
	t_vector_i		next_coord;
	const float		move_speed = 0.35;

	dda = data->dda;
	player = data->player;
	next_coord[0] = (int)(dda.pos[0] + player.plane[0] * move_speed);
	next_coord[1] = (int)(dda.pos[1] + player.plane[1] * move_speed);
	if (data->map[next_coord[0]][(int)(dda.pos[1])] != '1')
		data->player.pos[0] += player.plane[0] * move_speed;
	if (data->map[(int)(dda.pos[0])][next_coord[1]] != '1')
		data->player.pos[1] += player.plane[1] * move_speed;
}
