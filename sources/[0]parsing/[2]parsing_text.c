/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:54 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:35:54 by motero           ###   ########.fr       */
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

	if (!init_textures_colors(&textures, &colors))
		return (print_error("Error malloc"), 0);
	if (!parsing_lines(path, textures, colors, &map))
		return (free_all(textures, colors, map), \
		print_error("Incorrect Map Information while parse"), 0);
	if (!valide_textures(textures))
		return (free_all(textures, colors, map), \
		print_error("Incorrect Map Information2"), 0);
	if (!valide_colors(colors))
		return (free_all(textures, colors, map), \
		print_error("Incorrect Map Colors"), 0);
	if (!textures_to_data(data, textures))
		return (free_all(textures, colors, map), \
		print_error("Unexpected termination"), 0);
	if (!colors_to_data(data, colors))
		return (free_all(textures, colors, map), \
		print_error("Unexpected termination"), 0);
	if (!check_map(&map))
		return (free_all(textures, colors, map), 0);
	data->map = map;
	return (free_all(textures, colors, NULL), 1);
}

int	init_textures_colors(char ***textures, char ***colors)
{
	*textures = ft_calloc(5, sizeof(char *));
	if (!*textures)
		return (print_error("Error malloc\n"), 0);
	if (!initialize_double_char(*textures, 5))
		return (free_double_char(*textures), print_error("Error malloc"), 0);
	*colors = ft_calloc(3, sizeof(char *));
	if (!*colors)
		return (free_double_char(*textures), print_error("Error malloc"), 0);
	if (!initialize_double_char(*colors, 3))
		return (free_double_char(*textures), free_double_char(*colors), \
		print_error("Error malloc"), 0);
	return (1);
}

void	free_tmp_and_line(char ***tmp, char **line)
{
	if (*tmp)
		free_double_char(*tmp);
	*tmp = NULL;
	if (*line)
		free(*line);
	*line = NULL;
}

void	finish_file_read(int *fd)
{
	close(*fd);
	*fd = -1;
	get_next_line(-1);
}

int	parsing_lines(char *path, char **textures, char **colors, char ***map)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		mask;

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
			else if (check_texture_elements(tmp, textures, &mask) || \
			check_color_elements(colors, tmp, &mask))
				;
			else if (mask >= 31 && parse_map(line, map, fd))
			{
				free_double_char(tmp);
				break ;
			}
			else
			{
				free_tmp_and_line(&tmp, &line);
				finish_file_read(&fd);
				return (ft_putstr_fd("Error\nParse error\n", 1), 0);
			}
		}
		free_tmp_and_line(&tmp, &line);
		line = get_next_line(fd);
	}
	finish_file_read(&fd);
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
