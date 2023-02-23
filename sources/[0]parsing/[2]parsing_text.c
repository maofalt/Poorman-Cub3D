/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:54 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 00:07:14 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing_text(t_cub *data, char *path)
{
	char		**textures;
	char		**colors;
	char		**map;

	(void)map;
	textures = ft_calloc(5, sizeof(char *));
	if (!textures)
		return (ft_putstr_fd("Error malloc\n", 2), 0);
	textures[4] = NULL;
	colors = ft_calloc(3, sizeof(char *));
	if (!colors)
		return (free_double_char(textures), ft_putstr_fd("Error malloc\n", 2), 0);
	colors[2] = NULL;
	if (!parsing_lines_before_map(path, textures, colors))
		return (ft_putstr_fd("Error\nIncorrect Map Information1\n", 2), 0);
	printf("textures1: %s, %s, %s, %s\n", textures[0], textures[1], textures[2], textures[3]);
	if (!valide_textures(textures))
		return (ft_putstr_fd("Error\nIncorrect Map Information2\n", 2), 0);
	if (!valide_colors(colors))
		return (ft_putstr_fd("Error\nIncorrect Map Colors\n", 2), 0);
	printf("textures: %s, %s, %s, %s\n", textures[0], textures[1], textures[2], textures[3]);
	printf("colors: %s, %s\n", colors[0], colors[1]);
	if (!textures_to_data(data, textures))
		return (ft_putstr_fd("Error\nUnexpected termination3\n", 2), 0);
	if (!colors_to_data(data, colors))
		return (ft_putstr_fd("Error\nUnexpected termination4\n", 2), 0);
	return (1);
}

int	parsing_lines_before_map(char *path, char **textures, char **colors)
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
	while (line && mask != 31)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			printf("line: |%s|\n", line);
			tmp = ft_split(line, ' ');
			if (!tmp)
				return (ft_putstr_fd("Error\nIncorrect Map Information\n", 2), 0);
			else if (check_texture_elements(tmp, textures, &mask) || check_color_elements(colors, tmp, &mask))
				;
			else
			{
				if (tmp)
					free_double_char(tmp);
				free(line);
				get_next_line(-1);
				return (ft_putstr_fd("Error\nIncorrect Map Information33\n", 2), 0);
			}
		}
		if (tmp)
			free_double_char(tmp);
		tmp = NULL;
		free(line);
		line = get_next_line(fd);
	}
	printf("textures inside : %s, %s, %s, %s\n", textures[0], textures[1], textures[2], textures[3]);
	free(line);
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
