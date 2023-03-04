/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [2]parsing_text.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:54 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:35:54 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*function that will print the encoded rgb colors of f
**
**loor and celling that are in uuint32_t
*/
void	print_colors(t_cub *data)
{
	printf("floor = %d\n", data->floor);
	printf("celling = %d\n", data->celling);
}

int	parsing_text(t_cub *data, char *path)
{
	char		**textures;
	char		**colors;
	char		**map;

	map = NULL;
	if (!init_textures_colors(&textures, &colors))
		return (print_error("Error malloc"), 0);
	if (!parsing_lines(path, textures, colors, &map))
		return (free_all(textures, colors, map), \
		print_error("Incorrect Map Information while parse"), 0);
	if (!valide_textures(textures))
		return (free_all(textures, colors, map), print_error("Wrong Info"), 0);
	if (!valide_colors(colors))
		return (free_all(textures, colors, map), \
		print_error("Incorrect Map Colors"), 0);
	if (!textures_to_data(data, textures))
		return (free_all(textures, colors, map), \
		print_error("Unexpected termination"), 0);
	if (!colors_to_data(data, colors))
		return (free_all(textures, colors, map), \
		print_error("Unexpected termination"), 0);
	if (!check_map(&map))
		return (free_all(textures, colors, map), 0);
	data->map = map;
	return (free_all(textures, colors, NULL), 1);
}

int	init_textures_colors(char ***textures, char ***colors)
{
	*textures = ft_calloc(5, sizeof(char *));
	if (!*textures)
		return (print_error("Error malloc\n"), 0);
	if (!initialize_double_char(*textures, 5))
		return (free_double_char(*textures), print_error("Error malloc"), 0);
	*colors = ft_calloc(3, sizeof(char *));
	if (!*colors)
		return (free_double_char(*textures), print_error("Error malloc"), 0);
	if (!initialize_double_char(*colors, 3))
		return (free_double_char(*textures), free_double_char(*colors), \
		print_error("Error malloc"), 0);
	return (1);
}

void	free_tmp_and_line(char ***tmp, char **line)
{
	if (*tmp)
		free_double_char(*tmp);
	*tmp = NULL;
	if (*line)
		free(*line);
	*line = NULL;
}

void	finish_file_read(int *fd)
{
	close(*fd);
	*fd = -1;
	get_next_line(-1);
}
