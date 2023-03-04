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

int	initialize_parsing_lines(char **line, int *mask, char	*path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nOpen() returned -1\n", 1), -1);
	*line = get_next_line(fd);
	*mask = 0;
	return (fd);
}

int	read_line(char **line, int fd)
{
	if (*line)
		free(*line);
	*line = get_next_line(fd);
	return (1);
}

int	parsing_lines(char *path, char **textures, char **colors, char ***map)
{
	int		fd;
	char	*line;
	int		mask;

	fd = initialize_parsing_lines(&line, &mask, path);
	if (fd == -1)
		return (0);
	while (line)
	{
		if ((line[0] == '\n' || line[0] == '\0') && read_line(&line, fd))
			continue ;
		if (mask >= 31 && parse_map(line, map, fd))
			return (finish_file_read(&fd), 1);
		else if (!check_texture_elements(line, textures, &mask) && \
			!check_color_elements(colors, line, &mask))
			return (free(line), finish_file_read(&fd),
				ft_putstr_fd("Error\nParse error\n", 1), 0);
		read_line(&line, fd);
	}
	return (finish_file_read(&fd), 1);
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
