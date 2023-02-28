/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:35:41 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:25:30 by motero           ###   ########.fr       */
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
	(void)data;
	(void)x;
	(void)y;
	ft_printf("Button1 pressed with id %d\n", buttonsym);
	if (buttonsym == Button1)
		ft_printf("Button1 pressed\n");
	return (0);
}

int	ft_handle_keypress(int keysym, t_cub *data)
{
	ft_destroy_window_button(keysym, data);
	if (keysym == UP_KEY || keysym == DOWN_KEY || keysym == RIGHT_KEY
		|| keysym == LEFT_KEY)
		ft_movements_keys(keysym, data);
	ft_keyboard_press(keysym, data);
	data->update = 1;
	return (0);
}

