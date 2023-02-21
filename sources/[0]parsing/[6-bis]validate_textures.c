/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [6-bis]validate_textures.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:44 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 18:34:23 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valide_textures(char **textures)
{
	if (!textures[0] || !textures[1] || !textures[2] || !textures[3])
		return (0);
	if (!trim_textures_str(textures))
		return (0);
	if (check_textures_extension(textures))
		return (0);
	if (check_textures_validity(textures))
		return (0);
	return (1);
}

int	trim_textures_str(char **textures)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < 4)
	{
		tmp = ft_strtrim(textures[i], " ");
		if (!tmp)
			return (free(tmp), 0);
		free(textures[i]);
		textures[i] = tmp;
		i++;
	}
	return (1);
}

int	check_textures_extension(char **textures)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_extension(textures[i], ".xpm"))
			return (0);
		i++;
	}
	return (1);
}

int	check_textures_validity(char **textures)
{
	int	i;
	int	fd;

	i = 0;
	while (i < 4)
	{
		fd = open(textures[i], O_RDONLY);
		if (fd == -1)
			return (close(fd), 0);
		close(fd);
		i++;
	}
	return (1);
}
