/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5-bis]valid_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:36 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:16:06 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valide_colors(char **colors)
{
	if (!valid_characters(colors))
		return (0);
	if (!range_colors(colors))
		return (0);
	return (1);
}

int	check_commas(char *str)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	while (str[i])
	{
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (0);
	return (1);
}

int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_nbrs(char **nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		if (!check_digits(nbrs[i]))
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}

int	valid_characters(char **colors)
{
	int		i;
	char	**nbrs;

	i = 0;
	nbrs = NULL;
	while (i < 2)
	{
		if (!check_commas(colors[i]))
			return (0);
		nbrs = ft_split(colors[i++], ',');
		if (!nbrs)
			return (0);
		if (!check_nbrs(nbrs))
			return (free_double_char(nbrs), 0);
		free_double_char(nbrs);
	}
	return (1);
}
