/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [4]check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:13:25 by motero            #+#    #+#             */
/*   Updated: 2023/02/24 23:55:12 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map(char ***map)
{
	if (!check_valid_map_characters(*map))
		return (ft_putstr_fd("Error\nInvalid characters in map\n", 2), 0);
	if (!check_valid_map_no_split(*map))
		return (ft_putstr_fd("Error\nMap is splitted\n", 2), 0);
	if (!map_trim(map))
		return (ft_putstr_fd("Error\nDuring cleansing\n", 2), 0);
	if (!transform_map(map))
		return (ft_putstr_fd("Error\nUnexpected failure\n", 2), 0);
	return (1);
}

/* function that will check if the map has only valid characters
** valid characters are 0, 1 N, S, E W ' ' or '\n'
** if not, it will return 0
** else it will return 1
*/
int	check_valid_map_characters(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!valid_characters_map(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	valid_characters_map(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'\
		|| c == 'W' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

/*
** This function will check if the map is not splited by empty lines.
** We will check if the line is empty  with line_is_empty, 
** which returns 1 if it is empty
** and 0 if it is not.
** Once a line is empty, we will check if the subsequents lines are empty too.
** If they are not, it means that the map is splited by empty lines.
** If it is the case, we will return 0.
** If we reach the end of the map, it means that the map is valid 
** and we will return 1.
 */
int	check_valid_map_no_split(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (line_is_empty(map[i]))
		{
			i++;
			while (map[i])
			{
				if (!line_is_empty(map[i]))
					return (0);
				i++;
				if (!map[i])
					return (1);
			}
		}
		i++;
	}
	return (1);
}

/* Line is empty is   all he characters are a space and finishes 
** by \n or if there is only one \n, It returns 1 if it is empty
** Otherwise it returns 0
*/
int	line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
