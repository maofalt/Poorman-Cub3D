/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:31:11 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 23:16:10 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdint.h>
# include <stdio.h>
# include "libft.h"
# include "../gnl/get_next_line.h"
# include "structures.h"
# include "colors.h"
# include "mlx_int.h"
# include "mlx_engine.h"
# include <mlx.h>

/*############################################################################*/
/*                              PARSING FUNCTIONS                             */
/*############################################################################*/

int		main_parsing(t_cub	*data, char *path);

/*############################################################################*/
/*                              CHECK VALID FILE                              */
/*############################################################################*/
int		valid_file(char	*path);
int		check_extension(char *file, char *extension);
int		file_empty(int fd);

/*############################################################################*/
/*                              CHECK FILE ELEMENTS                           */
/*############################################################################*/

int		parsing_text(t_cub *data, char *path);
int		parsing_lines_before_map(char *path, char **textures, char **colors);
void	free_double_char(char **array);

/*############################################################################*/
/*                              CHECK TEXTURE ELEMENTS                        */
/*############################################################################*/

int		check_texture_elements(char **tmp, char **textures);
int		add_last_texture(char *texture, char *tmp);

/*############################################################################*/
/*                              CHECK TEXTURE ELEMENTS                        */
/*############################################################################*/

int		valide_textures(char **textures);
int		check_textures_extension(char **textures);
int		check_textures_validity(char **textures);

/*############################################################################*/
/*                              CHECK COLOR ELEMENTS                          */
/*############################################################################*/

int		check_color_elements(char **color, char **tmp);
int		add_last_color(char *color, char *tmp);

/*############################################################################*/
/*                              CHECK COLOR ELEMENTS                          */
/*############################################################################*/

int		valide_colors(char **colors);
int		valid_characters(char **colors);
int		range_colors(char **colors);
int		range_colors(char **colors);

/*############################################################################*/
/*                              CHECK MAP                                     */
/*############################################################################*/
int		check_map(t_cub	*data);

/*############################################################################*/
/*                              store into t_cub                              */
/*############################################################################*/

int		textures_to_data(t_cub *data, char **textures);
int		colors_to_data(t_cub *data, char **colors);
#endif
