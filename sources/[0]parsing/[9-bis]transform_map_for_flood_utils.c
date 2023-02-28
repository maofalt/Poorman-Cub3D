/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [9-bis]transform_map_for_flood_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:39:01 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:22:00 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	fill_map(char ***map, int height, int width)
{
	int				i;
	int				j;
	const char		fill = '*';

	i = 0;
	while (i < height + 2)
	{
		j = 0;
		while (j < width + 2)
		{
			(*map)[i][j] = fill;
			j++;
		}
		(*map)[i][j] = '\0';
		i++;
	}
}

void	copy_map(char ***new_map, char **map, int height, int width)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	len = 0;
	while (i < height + 1)
	{
		j = 1;
		while (j < width + 1)
		{
			len = ft_strlen(map[i - 1]);
			if ((len + 1) > j && map[i - 1][j - 1] != ' ' \
			&& map[i - 1][j - 1] != '\0')
				(*new_map)[i][j] = map[i - 1][j - 1];
			j++;
		}
		i++;
	}
}
