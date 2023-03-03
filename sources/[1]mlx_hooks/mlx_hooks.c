/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:34:28 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:24:53 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_engine.h"

/*Hooks (boutton press, button reease, destoy window,**
** key release and mxloop here)*/
void	ft_mlx_engine(t_cub *data)
{
	mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
		&ft_handle_boutonpress, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0L, &ft_destroy_window, data);
	mlx_key_hook(data->win_ptr, &ft_handle_keyrelease, data);
	mlx_loop(data->mlx_ptr);
}
