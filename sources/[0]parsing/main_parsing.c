/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanthoma <yanthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:30:35 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 13:13:39 by yanthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/structures.h"

int	get_nb_line(char *path)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1 || !check_extension(path))
		return (ft_putstr_fd("Error\nInvalid file\n", 2), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), free(line), 0);
	while (line)
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close (fd);
	return (i);
}

int	get_height(t_cub *data)
{
	int	i;

	i = 0;
	while (data->map[i])
		i++;
	return (i);
}

void	fill_line(t_cub *data, char *line, int len, int x)
{
	int	i;

	i = 0;
	while (i < len)
	{
		data->map[x][i] = line[i];
		i++;
	}
	data->map[x][i] = '\0';
	return ;
}

int	init_map(t_cub *data, t_cub *map, char *path, int x)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nInvalid file\n", 2), 1);
	line = get_next_line(fd);
	while (line)
	{
		len = 0;
		while (line[len] && line[len] != '\n')
			len++;
		map->map[x] = ft_calloc(sizeof(char), (len + 1));
		data->map[x] = ft_calloc(sizeof(char), (len + 1));
		if (!data->map[x] || !map->map[x])
			return (free(line), close(fd), 1);
		fill_line(data, line, len, x);
		free(line);
		line = get_next_line(fd);
		x++;
	}
	data->map[x] = NULL;
	map->map[x] = NULL;
	return (close(fd), 0);
}

int	parsing(t_cub *data, t_cub *map, char *path)
{
	int		len;

	len = get_nb_line(path);
	if (len == -1)
		return (1);
	else if (len == 0)
		return (ft_putstr_fd("Error\nMap empty n_n\n", 2), 1);
	map->map = ft_calloc(sizeof(char *), (len + 1));
	data->map = ft_calloc(sizeof(char *), (len + 1));
	if (!data->map || !map->map)
		return (ft_putstr_fd("Error\nMap empty n_n\n", 2), 1);
	if (init_map(data, map, path, 0))
		return (1);
	data->mapwidth = ft_strlen(data->map[0]) * 32;
	data->mapheight = get_height(data) * 32;
	if (!get_nb_coll(data))
		return (1);
	return (0);
}
