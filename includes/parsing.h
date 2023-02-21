/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:31:11 by motero            #+#    #+#             */
/*   Updated: 2023/02/21 17:18:46 by motero           ###   ########.fr       */
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

int		main_parsing(t_cub	*data, char *path);

/*############################################################################*/
/*                              CHECK VALID FILE                              */
/*############################################################################*/
int		valid_file(char	*path);
int		check_extension(char *file);
int		file_empty(int fd);

/*############################################################################*/
/*                              CHECK FILE ELEMENTS                           */
/*############################################################################*/

int		parsing_text(t_cub *data, char *path);
int		parsing_lines_before_map(char *path, char **textures, char **colors);
char	*ft_clean_whitespaces(char *line);

/*############################################################################*/
/*                              CHECK TEXTURE ELEMENTS                        */
/*############################################################################*/

int		check_texture_elements(char *tmp, char **textures);
int		add_last_texture(char *texture, char *tmp);

/*############################################################################*/
/*                              CHECK COLOR ELEMENTS                          */
/*############################################################################*/

int		check_color_elements(char **color, char *tmp);
int		add_last_color(char *color, char *tmp);

/*############################################################################*/
/*                              CHECK COLOR ELEMENTS                          */
/*############################################################################*/

int		check_map(t_cub	*data);

#endif
