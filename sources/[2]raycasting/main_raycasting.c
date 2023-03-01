/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:39 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:07:42 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

/* We render image if update == 1, in this case if a hook or **
**event has modified underlying constants*/
int	ft_render(t_cub *data)
{
	if (data->win_ptr == NULL)
		return (1);
	data->update = 1;
	if (data->update)
	{
		draw_celling_floor(data);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->screen.mlx_img, 0, 0);
		data->update = 0;
	}
	return (0);
}