/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [7]store_into_data_struct.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:28:12 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 22:37:05 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	textures_to_data(t_cub *data, char **textures)
{
	int		i;
	int		width;
	int		height;

	i = 0;
	width = WINDOW_WIDTH;
	height = WINDOW_HEIGHT;
	while (textures[i])
	{
		printf("textures[%d] = %s\n", i, textures[i]);
		data->texture[i].mlx_img = mlx_xpm_file_to_image(&data->mlx_ptr, textures[i], &width, &height);
		if (data->texture[i].mlx_img)
			return (0);
		i++;
	}
	return (1);
}

int	colors_to_data(t_cub *data, char **colors)
{
	int		i;
	char	**tmp;

	tmp = NULL;
	i = 0;
	while (colors[i])
	{
		tmp = ft_split(colors[i], ',');
		if (!tmp)
			return (0);
		if (i == 0)
			data->floor = encode_rgb(1, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		else
			data->celling = encode_rgb(1, ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		free_double_char(tmp);
		i++;
	}
	return (1);
}