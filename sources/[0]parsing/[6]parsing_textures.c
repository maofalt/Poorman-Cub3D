/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [6]parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:44 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 17:30:44 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_texture_elements(char *tmp, char **textures)
{
	if (ft_strncmp(tmp, "NO ", 3) == 0)
		return (add_last_texture(textures[0], tmp));
	else if (ft_strncmp(tmp, "EA ", 3) == 0)
		return (add_last_texture(textures[1], tmp));
	else if (ft_strncmp(tmp, "SO ", 3) == 0)
		return (add_last_texture(textures[2], tmp));
	else if (ft_strncmp(tmp, "WE ", 3) == 0)
		return (add_last_texture(textures[3], tmp));
	return (0);
}

int	add_last_texture(char *texture, char *tmp)
{
	if (texture)
		free(texture);
	texture = ft_strdup(tmp + 3);
	if (!texture)
		return (free(texture), 1);
	return (1);
}
