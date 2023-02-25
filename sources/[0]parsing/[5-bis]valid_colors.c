/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5-bis]valid_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:36 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 20:59:25 by motero           ###   ########.fr       */
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

int	valid_characters(char **colors)
{
	int		i;
	int		j;
	int		k;
	char	**nbrs;

	i = 0;
	nbrs = NULL;
	k = 0;
	while (i < 2)
	{
		nbrs = ft_split(colors[i], ',');
		if (!nbrs)
			return (0);
		if (nbrs[0] == NULL || nbrs[1] == NULL || nbrs[2] == NULL || nbrs[3] != NULL)
			return (0);
		k = 0;
		while (nbrs[k])
		{
			j = 0;
			while (nbrs[k][j])
			{
				if (!ft_isdigit(nbrs[k][j]))
					return (free_double_char(nbrs), 0);
				j++;
			}	
			k++;
		}
		free_double_char(nbrs);
		i++;
	}
	return (1);
}

/* 
** The code above does the following: int range_colors()
** check if there are 3 positive number for both colorat 
** 1-  we split the  two string with ',' as a delimiter with ft_split()
** 2 - we traverse each string, and eeach traversal we sum the new 
** int value (values[i][j] - '0') and we multiply the preview number by 10 
** (e.g. nbr = nbr * 10 + (values[i][j]) - '0')
** 3-We check fi the new numbrer is comprised betwen [0,255] if not we 
** return 0, without forgettin to free.
*/
int	range_colors(char **colors)
{
	int		i;
	int		j;
	int		k;
	int		nbr;
	char	**nbrs;

	i = 0;
	nbrs = NULL;
	while (i < 2)
	{
		nbrs = ft_split(colors[i], ',');
		if (!nbrs)
			return (0);
		j = 0;
		while (nbrs[j])
		{
			nbr = 0;
			k = 0;
			while (nbrs[j][k])
			{
				nbr = nbr * 10 + (nbrs[j][k] - '0');
				k++;
			}
			if (nbr < 0 || nbr > 255)
				return (free_double_char(nbrs), 0);
			j++;
		}
		free_double_char(nbrs);
		i++;
	}
	return (1);
}
