/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5]parsing_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:36 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 17:30:26 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_color_elements(char **color, char *tmp)
{
	if (ft_strncmp(tmp, "F ", 2) == 0)
		return (add_last_color(color[0], tmp));
	else if (ft_strncmp(tmp, "C ", 2) == 0)
		return (add_last_color(color[1], tmp));
	return (0);
}

int	add_last_color(char *color, char *tmp)
{
	if (color)
		free(color);
	color = ft_strdup(tmp + 2);
	if (!color)
		return (free(color), 1);
	return (1);
}
