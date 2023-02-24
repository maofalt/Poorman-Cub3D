/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [9]transform_map_for_flood.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:39:01 by motero            #+#    #+#             */
/*   Updated: 2023/02/24 18:14:05 by motero           ###   ########.fr       */
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
