/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [9]transform_map_for_flood.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:39:01 by motero            #+#    #+#             */
/*   Updated: 2023/02/24 17:29:04 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*
** The map has been checked that consists only of valid characters
** and that it s no splitted.
** We now need to trim the space and new lines at the end end of each line
** and at the end of the file, after the end of the map.
** If there is an error during transformation, we return 0
** else we return 1
*/

int	map_trim(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] && (map[i][j] == ' ' || map[i][j] == '\n'))
		{
			map[i][j] = '\0';
			j--;
		}
		i++;
	}
	print_map(map);
	return (1);
}
