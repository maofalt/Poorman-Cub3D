/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:31:11 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:32:14 by motero           ###   ########.fr       */
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
# include "my_maths.h"
# include "raycasting.h"
# include <mlx.h>
# include <math.h>


# include <wchar.h>
# include <uchar.h>
# include <locale.h>

/*############################################################################*/
/*                              PARSING FUNCTIONS                             */
/*############################################################################*/

int		main_parsing(t_cub	*data, char *path);
int		initialize_double_char(char **array, int size);
int		nbr_commas(char *str);
void	print_error(char *message);

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
int		init_textures_colors(char ***textures, char ***colors);
int		parsing_lines(char *path, char **textures, char **colors, char ***map);
void	free_double_char(char **array);
void	free_all(char **textures, char **colors, char **map);

/*############################################################################*/
/*                              CHECK TEXTURE ELEMENTS                        */
/*############################################################################*/

int		check_texture_elements(char **tmp, char **textures, int *mask);
int		add_last_texture(char **texture, char *tmp);

/*############################################################################*/
/*                              CHECK TEXTURE ELEMENTS                        */
/*############################################################################*/

int		valide_textures(char **textures);
int		check_textures_extension(char **textures);
int		check_textures_validity(char **textures);

/*############################################################################*/
/*                              CHECK COLOR ELEMENTS                          */
/*############################################################################*/

int		check_color_elements(char **color, char **tmp, int *mask);
int		add_last_color(char **color, char *tmp);

/*############################################################################*/
/*                              CHECK COLOR ELEMENTS                          */
/*############################################################################*/

int		valide_colors(char **colors);
int		check_commas(char *str);
int		check_digits(char *str);
int		check_nbrs(char **nbrs);
int		valid_characters(char **colors);
int		range_colors(char **colors);
int		check_color_range(char *color);

/*############################################################################*/
/*                              CHECK MAP                                     */
/*############################################################################*/
int		parse_map(char	*line, char ***map, int fd);
int		check_map(char ***map);
int		check_valid_map_characters(char **map);
int		valid_characters_map(char c);
int		check_valid_map_no_split(char **map);
int		line_is_empty(char *line);
void	print_map(char **map);

/*############################################################################*/
/*                              store into t_cub                              */
/*############################################################################*/

int		textures_to_data(t_cub *data, char **textures);
int		colors_to_data(t_cub *data, char **colors);

/*############################################################################*/
/*                              MAP PREPARATION FOR FLOOD                     */
/*############################################################################*/

int		map_trim(char ***map);
void	free_uneeded_lines(char ***map, int i);
int		transform_map(char ***map);
int		get_map_height(char **map);
int		get_map_width(char **map);
void	fill_map(char ***map, int height, int width);
void	copy_map(char ***new_map, char **map, int height, int width);

/*############################################################################*/
/*                              initiazlize player  structure                 */
/*############################################################################*/
int     initialize_player(t_cub *data);
void    initialize_player_pos(t_cub *data);
void    initialize_player_dir(t_cub *data);
void    initialize_player_plane(t_cub *data);
#endif
