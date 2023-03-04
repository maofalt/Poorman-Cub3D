/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:28 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 17:15:52 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_engine.h"

int	ft_handle_mouse(int x, int y, t_cub *data)
{
	t_dda	*dda;
	int		dir;

	(void)y;
	dda = &(data->dda);
	dir = x - dda->mouse[0];
	if (dir < 0)
		rotate_counter_clockwise(data, -dir * 0.045);
	else if (dir > 0)
		rotate_clockwise(data, dir * 0.045);
	if (dir)
		data->update = 1;
	dda->mouse[0] = x;
	return (1);
}

/*Hooks (boutton press, button reease, destoy window,**
** key release and mxloop here)*/
void	ft_mlx_engine(t_cub *data)
{
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
		&ft_handle_boutonpress, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0L, &ft_destroy_window, data);
	mlx_key_hook(data->win_ptr, &ft_handle_keyrelease, data);
	mlx_hook(data->win_ptr, 6, (1L << 6), &ft_handle_mouse, data);
	mlx_loop(data->mlx_ptr);
}
