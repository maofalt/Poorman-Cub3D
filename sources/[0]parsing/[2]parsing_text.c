/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:54 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 17:01:18 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*function that will print the encoded rgb colors of f
**
**loor and celling that are in uuint32_t
*/
void	print_colors(t_cub *data)
{
	printf("floor = %d\n", data->floor);
	printf("celling = %d\n", data->celling);
}

int	parsing_text(t_cub *data, char *path)
{
	char		**textures;
	char		**colors;
	char		**map;

	map = NULL;
	textures = ft_calloc(5, sizeof(char *));
	if (!textures)
		return (ft_putstr_fd("Error malloc\n", 2), 0);
	textures[4] = NULL;
	colors = ft_calloc(3, sizeof(char *));
	if (!colors)
		return (free_double_char(textures), ft_putstr_fd("Error malloc\n", 2), 0);
	colors[2] = NULL;
	if (!parsing_lines(path, textures, colors, map))
		return (ft_putstr_fd("Error\nIncorrect Map Information\n", 2), 0);
	if (!valide_textures(textures))
		return (ft_putstr_fd("Error\nIncorrect Map Information2\n", 2), 0);
	if (!valide_colors(colors))
		return (ft_putstr_fd("Error\nIncorrect Map Colors\n", 2), 0);
	if (!textures_to_data(data, textures))
		return (ft_putstr_fd("Error\nUnexpected termination3\n", 2), 0);
	if (!colors_to_data(data, colors))
		return (ft_putstr_fd("Error\nUnexpected termination4\n", 2), 0);
	return (1);
}

int	parsing_lines(char *path, char **textures, char **colors, char **map)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		mask;

	tmp = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nOpen() returned -1\n", 2), 0);
	line = get_next_line(fd);
	mask = 0;
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			tmp = ft_split(line, ' ');
			if (!tmp)
				return (ft_putstr_fd("Error\nIncorrect Map Information\n", 2), 0);
			else if (check_texture_elements(tmp, textures, &mask) || check_color_elements(colors, tmp, &mask))
				;
			else if (mask >= 31 && parse_map(line, map, fd))
				;
			else
			{
				if (tmp)
					free_double_char(tmp);
				if (line)
					free(line);
				line = NULL;
				get_next_line(-1);
				return (ft_putstr_fd("Error\nIncorrect Map Information33\n", 2), 0);
			}
		}
		if (tmp)
			free_double_char(tmp);
		tmp = NULL;
		if (line)
			free(line);
		line = get_next_line(fd);
	}
	get_next_line(-1);
	return (1);
}

/*
** Free a double  char array
*/

void	free_double_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
}

