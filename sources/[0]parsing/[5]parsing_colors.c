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

int	check_color_elements(char **color, char **tmp)
{
	if (!tmp[0] || tmp[1] == 0 || tmp[2] != NULL)
		return (0);
	if (ft_strncmp(tmp[0], "F", 2) == 0)
		return (add_last_color(color[0], tmp[1]));
	else if (ft_strncmp(tmp[0], "C", 2) == 0)
		return (add_last_color(color[1], tmp[1]));
	return (0);
}

int	add_last_color(char *color, char *tmp)
{
	if (color)
		free(color);
	color = ft_strdup(tmp);
	if (!color)
		return (free(color), 1);
	return (1);
}
