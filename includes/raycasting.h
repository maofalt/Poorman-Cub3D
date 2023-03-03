/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:01:22 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 00:13:37 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# ifndef FOV
#  define FOV 60
# endif

# include "mlx.h"
# include "mlx_int.h"
# include "mlx_engine.h"
# include <stdlib.h>
# include <stdint.h>
# include "structures.h"
# include "my_maths.h"
# include <math.h>

/*############################################################################*/
/*                          RAYCASTINGFUNCTIONS                               */
/*############################################################################*/
int		ft_render(t_cub *data);
void	calculate_ray_angle(t_cub *data);
void	calculate_length_ray(t_dda *dda);
void	calculate_step_side_dist(t_dda *dda);
void	perform_dda(t_cub *data);
void	calculate_distance_projection(t_cub *data);
void	calculate_line_height(t_cub *data);
void	chose_color_wall(t_cub *data);

/*############################################################################*/
/*                         TEXTURE MAPPING                                    */
/*############################################################################*/
void	texturise_wall(t_cub *data);
int		determine_texture(t_cub *data);
int		determine_wall_x_hit(t_cub *data, int tex_num);
void	copy_coresponding_pixel(t_cub *data, int tex_num, int tex_x);
int		get_pixel(t_cub *data, int tex_num, int tex_x);

#endif