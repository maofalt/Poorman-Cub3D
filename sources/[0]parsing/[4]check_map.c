/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [4]check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:13:25 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 23:45:12 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_map(char **map)
{
	if (!check_valid_map_characters(map))
		return (0);
	if (!check_valid_map_no_split(map))
		return (0);
	if (!map_trim_EOL_spaces(map))
		return (0);
	if (map_trim_EOF_newlines(map))
		return (0);
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
			if (valid_characters(map[i][j]))
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

int	check_valid_map_no_split(char **map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			c = map[i][j];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == '1' || c == '0')
			{
				if (map[i][j + 1] == '\0' && map[i + 1] == NULL)
					return (0);
			}
			else if (c == ' ')
			{
				
			}
			else if (c == '\n')
			j++;
		}
		i++;
	}
	return (1);
}