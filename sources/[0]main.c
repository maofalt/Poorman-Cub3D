/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:11:18 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 17:06:12 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_everything(t_cub data)
{
	if (data.win_ptr != NULL)
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	data.win_ptr = NULL;
	if (data.texture[0].mlx_img != NULL)
		mlx_destroy_image(data.mlx_ptr, data.texture[0].mlx_img);
	if (data.texture[1].mlx_img != NULL)
		mlx_destroy_image(data.mlx_ptr, data.texture[1].mlx_img);
	if (data.texture[2].mlx_img != NULL)
		mlx_destroy_image(data.mlx_ptr, data.texture[2].mlx_img);
	if (data.texture[3].mlx_img != NULL)
		mlx_destroy_image(data.mlx_ptr, data.texture[3].mlx_img);
	mlx_destroy_image(data.mlx_ptr, data.screen.mlx_img);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	if (data.map != NULL)
		free_double_char(data.map);
}

int	main(int argc, char **argv)
{
	t_cub	data;

	(void)argv;
	if (argc != 2)
		return (printf("Error\nToo many Arguments"), 1);
	ft_memset(&data, 0, sizeof(t_cub));
	ft_mlx_initialize_pointers(&data);
	if (data.mlx_ptr == NULL)
		return (1);
	data.update = 1;
	if (!main_parsing(&data, argv[1]))
		return (free_everything(data), 1);
	if (mlx_loop_hook(data.mlx_ptr, &ft_render, &data))
		ft_mlx_engine(&data);
	free_everything(data);
}
