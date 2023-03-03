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

void	ft_destroy_window_button(int keysym, t_cub *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
}


	/* Events catching movements and moving into the fractal window*/
void	ft_movements_keys(int keysym, t_cub *data)
{
	t_dda			dda;
	t_player		player;
	const float		move_speed = 0.35;	

	dda = data->dda;
	player = data->player;
	if (data->update)
		return ;
	printf("key pressed: %d\n", keysym);
	if (keysym == W_KEY)
	{
		if (data->map[(int)(dda.pos[0] + player.dir[0] * move_speed)][(int)(dda.pos[1])] != '1')
			data->player.pos[0] += player.dir[0] * move_speed;
		if (data->map[(int)(dda.pos[0])][(int)(dda.pos[1] + player.dir[1] * move_speed)] != '1')
			data->player.pos[1] += player.dir[1] * move_speed;
	}
	else if (keysym == S_KEY)
	{
		if (data->map[(int)(dda.pos[0] - player.dir[0] * move_speed)][(int)(dda.pos[1])] != '1')
			data->player.pos[0] -= player.dir[0] * move_speed;
		if (data->map[(int)(dda.pos[0])][(int)(dda.pos[1] - player.dir[1] * move_speed)] != '1')
			data->player.pos[1] -= player.dir[1] * move_speed;
	}
	else if (keysym == A_KEY)
	{
		if (data->map[(int)(dda.pos[0] - player.plane[0] * move_speed)][(int)(dda.pos[1])] != '1')
			data->player.pos[0] -= player.plane[0] * move_speed;
		if (data->map[(int)(dda.pos[0])][(int)(dda.pos[1] - player.plane[1] * move_speed)] != '1')
			data->player.pos[1] -= player.plane[1] * move_speed;
	}
	else if (keysym == D_KEY)
	{
		if (data->map[(int)(dda.pos[0] + player.plane[0] * move_speed)][(int)(dda.pos[1])] != '1')
			data->player.pos[0] += player.plane[0] * move_speed;
		if (data->map[(int)(dda.pos[0])][(int)(dda.pos[1] + player.plane[1] * move_speed)] != '1')
			data->player.pos[1] += player.plane[1] * move_speed;
	}
	else if (keysym == LEFT_KEY)
	{
		data->player.dir[0] = player.dir[0] * cos(-0.1) - player.dir[1] * sin(-0.1);
		data->player.dir[1] = player.dir[0] * sin(-0.1) + player.dir[1] * cos(-0.1);
		data->player.plane[0] = player.plane[0] * cos(-0.1) - player.plane[1] * sin(-0.1);
		data->player.plane[1] = player.plane[0] * sin(-0.1) + player.plane[1] * cos(-0.1);
	}
	else if (keysym == RIGHT_KEY)
	{
		data->player.dir[0] = player.dir[0] * cos(0.1) - player.dir[1] * sin(0.1);
		data->player.dir[1] = player.dir[0] * sin(0.1) + player.dir[1] * cos(0.1);
		data->player.plane[0] = player.plane[0] * cos(0.1) - player.plane[1] * sin(0.1);
		data->player.plane[1] = player.plane[0] * sin(0.1) + player.plane[1] * cos(0.1);
	}
	data->update = 1;
}

/*
** If the up arrow is pressed, the player will move forward: add dirX to posX, 
** and dirY to posY. This assumes that dirX and dirY are normalized vectors 
** (their length is 1), but they were initially set like this, so it's ok. 
** There's also a simple collision detection built in, namely if the new position 
** will be inside a wall, you won't move. This collision detection can be improved however,
** for example by checking if a circle around the player won't go inside the wall instead 
**of just a single point.
** The same is done if you press the down arrow, but then the direction is subtracted instead.
*/
void	ft_keyboard_press(int keysym, t_cub *data)
{
    (void)data;
    (void)keysym;
}