/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [8]parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:03:30 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 17:31:15 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parse_map(char	*line, char ***map, int fd)
{
	char	*join;
	char	*tmp;

	tmp = NULL;
	join = NULL;
	while (line)
	{
		tmp = ft_strjoin(join, line);
		if (!tmp)
			return (0);
		free(join);
		free(line);
		line = NULL;
		join = tmp;
		line = get_next_line(fd);
	}
	*map = ft_split(join, '\n');
	free(join);
	if (!*map)
		return (0);
	print_map(*map);
	return (1);
}

/* print a char **
*/

void	print_map(char **map)
{
	int	i;

	printf("****map\n");
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
