/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [5-bis]check_color_range.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:28:36 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:14:47 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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
int	check_color_range(char *color)
{
	char	**nbrs;
	int		j;
	int		k;
	int		nbr;

	nbrs = ft_split(color, ',');
	if (!nbrs)
		return (0);
	j = 0;
	while (nbrs[j])
	{
		nbr = 0;
		k = 0;
		while (nbrs[j][k])
			nbr = nbr * 10 + (nbrs[j][k++] - '0');
		if (nbr < 0 || nbr > 255)
			return (free_double_char(nbrs), 0);
		j++;
	}
	free_double_char(nbrs);
	return (1);
}

int	range_colors(char **colors)
{
	return (check_color_range(colors[0]) && check_color_range(colors[1]));
}
