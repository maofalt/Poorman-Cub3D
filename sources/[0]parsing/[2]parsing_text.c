/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:54 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 17:32:32 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	parsing_text(t_cub *data, char *path)
{
	char		*textures[4];
	char		*colors[2];

	(void)data;
	ft_memset(textures, 0, sizeof(char) * 4);
	ft_memset(colors, 0, sizeof(uint32_t) * 2);
	if (!parsing_lines_before_map(path, textures, colors))
		return (ft_putstr_fd("Incorrect Map Information\n", 2), 0);
	return (1);
}

int	parsing_lines_before_map(char *path, char **textures, char **colors)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error: Open() returned -1", 2), 0);
	line = get_next_line(fd);
	while (!line)
	{
		if (line[0] != '\n' && line[0] != '\0')
		{
			tmp = ft_clean_whitespaces(line);
			if (check_texture_elements(tmp, textures))
				;
			else if (check_color_elements(colors, tmp))
				;
			else
				return (ft_putstr_fd("Incorrect Map Information\n", 2), 0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

char	*ft_clean_whitespaces(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	tmp = &line[i];
	return (tmp);
}
