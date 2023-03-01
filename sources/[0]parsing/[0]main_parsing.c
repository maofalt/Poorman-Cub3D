/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]main_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanthoma <yanthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:30:35 by motero            #+#    #+#             */
/*   Updated: 2023/03/01 23:59:12 by yanthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	main_parsing(t_cub	*data, char *path)
{
	if (!valid_file(path))
		return (1);
	if (!parsing_text(data, path))
		return (1);
	if (!check_wall(data->map))
		return (printf("nein\n"), 1);
	if (!get_player_pos(data->map))
		return (printf("more tha one or none nigga\n"), 1);
	free_double_char(data->map);
	return (0);
}
