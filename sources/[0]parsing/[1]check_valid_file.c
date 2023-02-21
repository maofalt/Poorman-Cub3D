/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [1]check_valid_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:33:33 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 15:34:57 by motero           ###   ########.fr       */
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
		return (ft_putstr_fd("Error: No file specified", 2), 0);
	if (!check_extension(path))
		return (ft_putstr_fd("Error: Invalid file extension", 2), 0);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error: Open() returned -1", 2), 0);
	if (file_emtpy(fd))
		return (close(fd), ft_putstr_fd("Error: File is empty", 2), 0);
	return (close(fd), 1);
}

int	check_extension(char *file)
{
	return (!(ft_strncmp(file + (ft_strlen(file) - 4),
				".cub", ft_strlen(file))));
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
