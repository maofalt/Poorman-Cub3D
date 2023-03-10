/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [9]transform_map_for_flood.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanthoma <yanthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:39:01 by motero            #+#    #+#             */
/*   Updated: 2023/03/01 23:38:14 by yanthoma         ###   ########.fr       */
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
** After empting the lines of iuncessary characters, we start from the bottom 
** of the map and we check if the line is empty.
** If it is, we free the line, set it to NULLS and we move the pointer 
** to the next (reversely) line.
** If the line is not empty, we stop the loop and we return 1.
*/

int	map_trim(char ***map)
{
	int	i;
	int	j;

	i = 0;
	while ((*map)[i])
	{
		j = ft_strlen((*map)[i]) - 1;
		while ((j >= 0) && ((*map)[i][j] == ' ' || (*map)[i][j] == '\n'))
		{
			(*map)[i][j] = '\0';
			j--;
		}
		i++;
	}
	free_uneeded_lines(map, i);
	return (1);
}

void	free_uneeded_lines(char ***map, int i)
{
	i--;
	while (i >= 0)
	{
		if ((*map)[i][0] == 0)
		{
			free((*map)[i]);
			(*map)[i] = NULL;
		}
		else
			break ;
		i--;
	}
}

/*
** Transform the map for flood fill algorithm
** 1- get the size of the maps
** 2- create a new map with the size of the old map 
** size map = (height of the map + 2) * (size of the line + 2)
** 3- fill al the map with *
** 4- copy the old map in the new map starting from the second line 
** and the second column
** 5- free the old map
** 6- print the new map
** 7- return the new map
*/

int	transform_map(char ***map)
{
	int			i;
	int			height;
	int			width;
	char		**new_map;

	height = get_map_height(*map);
	width = get_map_width(*map);
	new_map = malloc(sizeof(char *) * (height + 3));
	if (!new_map)
		return (0);
	new_map[height + 2] = NULL;
	i = 0;
	while (i < height + 2)
	{
		new_map[i] = malloc(sizeof(char) * (width + 3));
		if (!new_map[i])
			return (free_double_char(new_map), 0);
		i++;
	}
	fill_map(&new_map, height, width);
	copy_map(&new_map, *map, height, width);
	free_double_char(*map);
	*map = new_map;
	return (1);
}

int	get_map_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	get_map_width(char **map)
{
	int	i;
	int	j;
	int	max;

	max = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			j++;
		}
		if (j > max)
			max = j;
		i++;
	}
	return (max);
}
