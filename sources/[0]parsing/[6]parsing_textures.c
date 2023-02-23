/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [6]parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:44 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 00:20:40 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_texture_elements(char **tmp, char **textures)
{
	if (!tmp[0] || tmp[1] == NULL || tmp[2] != 0)
		return (0);
	if (ft_strncmp(tmp[0], "NO", 3) == 0)
		return (add_last_texture(textures[0], tmp[1]));
	else if (ft_strncmp(tmp[0], "EA", 3) == 0)
		return (add_last_texture(textures[1], tmp[1]));
	else if (ft_strncmp(tmp[0], "SO", 3) == 0)
		return (add_last_texture(textures[2], tmp[1]));
	else if (ft_strncmp(tmp[0], "WE", 3) == 0)
		return (add_last_texture(textures[3], tmp[1]));
	return (0);
}

int	add_last_texture(char *texture, char *tmp)
{
	if (texture)
		free(texture);
	texture = ft_strdup(tmp);
	if (!texture)
		return (free(texture), 1);
	return (1);
}
