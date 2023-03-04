/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [10]initialize_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:39:01 by motero            #+#    #+#             */
/*   Updated: 2023/03/03 18:01:29 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** intiialize the t_player structure
** 1 - intialize the position of the player into the map as a t_vector_f pos
** 2 - initialize the direction of the player as a t_vector_f dir
** 3 - initialize the plane of the player as a t_vector_f plane which represents
** the camera plane
*/
int	initialize_player(t_cub *data)
{
	initialize_player_pos(data);
	initialize_player_dir(data);
	initialize_player_plane(data);
	data->dda.pos = data->player.pos;
	return (1);
}

/*
** Look for NSEW in the map and set the position of the player accorindgly
** and initialize the t_vector_f pos of the player
*/
void	initialize_player_pos(t_cub *data)
{
	int	x;
	int	y;	

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'N' || data->map[x][y] == 'S' ||
				data->map[x][y] == 'E' || data->map[x][y] == 'W')
			{
				data->player.pos[0] = x + 0.5;
				data->player.pos[1] = y + 0.5;
				return ;
			}
			y++;
		}
		x++;
	}
}

/*
** Initialize the direction of the player as a t_vector_f dir
** depending on the position of the player in the map
** and the orientation of the player "N", "S", "E", "W"
*/
void	initialize_player_dir(t_cub *data)
{
	char	orientation;

	orientation = data->map[(int)data->player.pos[0]][(int)data->player.pos[1]];
	if (orientation == 'N')
	{
		data->player.dir[0] = -1;
		data->player.dir[1] = 0;
	}
	else if (orientation == 'S')
	{
		data->player.dir[0] = 1;
		data->player.dir[1] = 0;
	}
	else if (orientation == 'E')
	{
		data->player.dir[0] = 0;
		data->player.dir[1] = 1;
	}
	else if (orientation == 'W')
	{
		data->player.dir[0] = 0;
		data->player.dir[1] = -1;
	}
}

/*
** Intiialize the  camera plane which is perpendicylar to the direction of the
** player and is used to calculate the ray direction
*/
void	initialize_player_plane(t_cub *data)
{
	char	direction;

	direction = data->map[(int)data->player.pos[0]][(int)data->player.pos[1]];
	if (direction == 'N')
	{
		data->player.plane[0] = 0;
		data->player.plane[1] = -0.66;
	}
	else if (direction == 'S')
	{
		data->player.plane[0] = 0;
		data->player.plane[1] = 0.66;
	}
	else if (direction == 'E')
	{
		data->player.plane[0] = -0.66;
		data->player.plane[1] = 0;
	}
	else if (direction == 'W')
	{
		data->player.plane[0] = 0.66;
		data->player.plane[1] = 0;
	}
}
