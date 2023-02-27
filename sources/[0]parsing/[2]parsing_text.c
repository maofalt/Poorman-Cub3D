/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:54 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 02:27:55 by motero           ###   ########.fr       */
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
		return (ft_putstr_fd("Error malloc\n", 1), 0);
	if (!initialize_double_char(textures, 5))
		return (free_double_char(textures), ft_putstr_fd("Error malloc\n", 1), 0);
	colors = ft_calloc(3, sizeof(char *));
	if (!colors)
		return (free_double_char(textures), ft_putstr_fd("Error malloc\n", 1), 0);
	if (!initialize_double_char(colors, 3))
		return (free_double_char(textures), free_double_char(colors), ft_putstr_fd("Error malloc\n", 1), 0);
	if (!parsing_lines(path, textures, colors, &map))
		return (free_all(textures, colors, map), ft_putstr_fd("Error\nIncorrect Map Information while parse\n", 1), 0);
	if (!valide_textures(textures))
	{
		free_all(textures, colors, map);
		return (ft_putstr_fd("Error\nIncorrect Map Information2\n", 1), 0);
	}
	if (!valide_colors(colors))
		return (free_all(textures, colors, map), ft_putstr_fd("Error\nIncorrect Map Colors\n", 1), 0);
	if (!textures_to_data(data, textures))
		return (free_all(textures, colors, map), ft_putstr_fd("Error\nUnexpected termination3\n", 1), 0);
	if (!colors_to_data(data, colors))
		return (free_all(textures, colors, map), ft_putstr_fd("Error\nUnexpected termination4\n", 1), 0);
	if (!check_map(&map))
		return (free_all(textures, colors, map), 0);
	data->map = map;
	free_all(textures, colors, NULL);
	return (1);
}

int	parsing_lines(char *path, char **textures, char **colors, char ***map)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		mask;

	tmp = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nOpen() returned -1\n", 1), 0);
	line = get_next_line(fd);
	mask = 0;
	while (line)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			tmp = ft_split(line, ' ');
			if (!tmp)
				return (ft_putstr_fd("Error\nInvalid text line\n", 1), 0);
			else if (check_texture_elements(tmp, textures, &mask) || check_color_elements(colors, tmp, &mask))
				;
			else if (mask >= 31 && parse_map(line, map, fd))
			{
				free_double_char(tmp);
				break ;
			}
			else
			{
				if (tmp)
					free_double_char(tmp);
				if (line)
					free(line);
				line = NULL;
				get_next_line(-1);
				close(fd);
				return (ft_putstr_fd("Error\nParse error\n", 1), 0);
			}
		}
		if (tmp)
			free_double_char(tmp);
		tmp = NULL;
		if (line)
			free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	close(fd);
	get_next_line(-1);
	return (1);
}

void	free_double_char(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(char **textures, char **colors, char **map)
{
	free_double_char(textures);
	free_double_char(colors);
	if (map)
		free_double_char(map);
}
