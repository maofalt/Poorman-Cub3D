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
	free_everything(data);
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

int	ft_handle_boutonpress(int buttonsym, int x, int y, t_data *data)
{

	return (0);
}