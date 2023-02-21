/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5-bis]valid_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:36 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 18:51:58 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	valid_colors(char **colors)
{
	if (!trim_spaces(colors))
		return (0);
	if (!valid_characters(colors))
		return (0);
	if (!range_colors(colors))
		return (0);
	return (1);
}

/* Fonction that will trim front and back space of each color string
**
*/
int	trim_spaces(char **colors)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	i = 0;
	while (i < 3)
	{
		tmp = trim_front(colors[i], " ");
		if (!tmp)
			return (0);
		tmp2 = trim_back(tmp, " ");
		if (!tmp2)
			return (free(tmp), 0);
		free(colors[i]);
		colors[i] = tmp2;
		i++;
	}
	return (1);
}

char	*trim_front(char *str, char *set)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && ft_strchr(set, str[i]))
		i++;
	tmp = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!tmp)
		return (NULL);
	while (str[i])
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	return (tmp);
}

char	*trim_back(char *str, char *set)
{
	int		i;
	char	*tmp;

	i = ft_strlen(str) - 1;
	while (i >= 0 && ft_strchr(set, str[i]))
		i--;
	tmp = malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	ft_strlcpy(tmp, str, i + 2);
	return (tmp);
}

int	valid_characters(char **colors)
{
	int	i;
	int	j;
	int	nbr_comma;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (colors[i][j])
		{
			if (!ft_isdigit(colors[i][j]) || colors[i][j] != ',')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

