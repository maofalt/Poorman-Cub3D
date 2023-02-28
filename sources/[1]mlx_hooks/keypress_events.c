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
    (void)keysym;
    (void)data;
    if (keysym == UP_KEY || keysym == RIGHT_KEY)
        printf("UP or RIGHT pressed\n");
    if (keysym == UP_KEY || keysym == DOWN_KEY)
        printf("UP or DOWN pressed\n");
    else if (keysym == RIGHT_KEY || keysym == LEFT_KEY)
        printf("RIGHT or LEFT pressed\n");
}

void	ft_keyboard_press(int keysym, t_cub *data)
{
    (void)keysym;
    (void)data;
    if (keysym == Z_KEY)
        printf("Z pressed\n");
    else if (keysym == Z_KEY)
        printf("S pressed\n");
    else if (keysym == Z_KEY)
        printf("Q pressed\n");
    else if (keysym == D_KEY)
        printf("D pressed\n");
}