/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:31:11 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 15:34:31 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdint.h>
# include "libft.h"
# include "../gnl/get_next_line.h"
# include "mlx_int.h"
# include "structures.h"

/*############################################################################*/
/*                              PARSING FUNCTIONS                             */
/*############################################################################*/

int	main_parsing(t_cub	*data, char *path);

/*############################################################################*/
/*                              CHECK VALID FILE                              */
/*############################################################################*/
int	valid_file(char	*path);
int	check_extension(char *file);
int	file_empty(int fd);

#endif
