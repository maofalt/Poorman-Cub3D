/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]main_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:30:35 by motero            #+#    #+#             */
/*   Updated: 2023/02/23 19:42:30 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main_parsing(t_cub	*data, char *path)
{
	if (!valid_file(path))
		return (1);
	if (!parsing_text(data, path))
		return (1);
	return (0);
}