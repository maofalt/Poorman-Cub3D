/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [6]parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:44 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 02:32:51 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_texture_elements(char *line, char **textures, int *mask)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!tmp)
		return (ft_putstr_fd("Error\nInvalid text line\n", 1), 0);
	if (!tmp[0] || tmp[1] == NULL || tmp[1][0] == '\n' || tmp[2] != 0)
		return (free_double_char(tmp), 0);
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
	{
		*mask = *mask | 1;
		return (add_last_texture(&textures[0], tmp));
	}
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
	{
		*mask = *mask | 2;
		return (add_last_texture(&textures[1], tmp));
	}
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
	{
		*mask = *mask | 4;
		return (add_last_texture(&textures[2], tmp));
	}
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
	{
		*mask = *mask | 8;
		return (add_last_texture(&textures[3], tmp));
	}
	free_double_char(tmp);
	return (0);
}

int	add_last_texture(char **texture, char **tmp)
{
	char	**tmp2;

	if (*texture)
		free(*texture);
	tmp2 = ft_split(tmp[1], '\n');
	free_double_char(tmp);
	if (!tmp2)
		return (free_double_char(tmp2), 0);
	*texture = ft_strdup(tmp2[0]);
	free_double_char(tmp2);
	if (!*texture)
		return (free(*texture), 0);
	return (1);
}
