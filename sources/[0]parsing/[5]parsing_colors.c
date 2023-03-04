/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5]parsing_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:36 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 16:07:08 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_color_elements(char **color, char *line, int *mask)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (!tmp)
		return (ft_putstr_fd("Error\nInvalid text line\n", 1), 0);
	if (!tmp[0] || tmp[1] == 0 || tmp[2] != NULL)
		return (free_double_char(tmp), 0);
	if (ft_strncmp(tmp[0], "F", 2) == 0)
	{
		*mask = *mask | 8;
		return (add_last_color(&color[0], tmp));
	}
	else if (ft_strncmp(tmp[0], "C", 2) == 0)
	{
		*mask = *mask | 16;
		return (add_last_color(&color[1], tmp));
	}
	free_double_char(tmp);
	return (0);
}

int	add_last_color(char **color, char **tmp)
{
	char	**tmp2;

	if (*color)
		free(*color);
	tmp2 = ft_split(tmp[1], '\n');
	free_double_char(tmp);
	if (!tmp2)
		return (free_double_char(tmp2), 1);
	*color = ft_strdup(tmp2[0]);
	if (!*color)
		return (free_double_char(tmp2), 1);
	free_double_char(tmp2);
	return (1);
}
