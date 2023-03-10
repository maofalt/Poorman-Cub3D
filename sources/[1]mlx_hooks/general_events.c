/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_events.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:35:41 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 17:08:02 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_engine.h"

int	ft_destroy_window(t_cub *data)
{	
	free_everything(*data);
	exit(1);
	return (0);
}

int	ft_handle_keyrelease(int keysym, t_cub *data)
{
	(void)data;
	if (keysym == XK_Escape)
		ft_printf("EScape released\n");
	return (0);
}

int	ft_handle_boutonpress(int buttonsym, int x, int y, t_cub *data)
{
	(void)x;
	(void)y;
	if (buttonsym == 1)
		rotate_counter_clockwise(data, 0.1);
	if (buttonsym == 3)
		rotate_clockwise(data, 0.1);
	data->update = 1;
	return (0);
}

int	ft_handle_keypress(int keysym, t_cub *data)
{
	ft_destroy_window_button(keysym, data);
	if (keysym == W_KEY || keysym == S_KEY || keysym == D_KEY
		|| keysym == A_KEY || keysym == LEFT_KEY || keysym == RIGHT_KEY)
		ft_movements_keys(keysym, data);
	ft_keyboard_press(keysym, data);
	data->update = 1;
	return (0);
}
