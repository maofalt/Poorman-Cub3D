/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]check_valid_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:33:33 by motero            #+#    #+#             */
/*   Updated: 2023/02/25 00:16:19 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/* Checks if file is valid and if it has the correct extension
**	Check if valid extension .cub
**	Check if file is valid (fd != -1)
**	Check if file is empty
** Returns 1 if valid, 0 if not
*/
int	valid_file(char	*path)
{
	int	fd;

	if (!path || path[0] == '\0')
		return (ft_putstr_fd("Error\nNo file specified\n", 1), 0);
	if (!check_extension(path, ".cub"))
		return (ft_putstr_fd("Error\nInvalid file extension\n", 1), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nOpen() returned -1\n", 1), 0);
	if (file_empty(fd))
		return (close(fd), ft_putstr_fd("Error\nFile is empty\n", 1), 0);
	return (close(fd), 1);
}

int	check_extension(char *file, char *extension)
{
	return (!(ft_strncmp(file + (ft_strlen(file) - 4), \
			extension, ft_strlen(file))));
}

int	file_empty(int fd)
{
	char	*line;
	int		ret;

	line = get_next_line(fd);
	ret = 0;
	if (!line)
		ret = 1;
	free(line);
	get_next_line(-1);
	return (ret);
}
