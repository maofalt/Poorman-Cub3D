/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:01:22 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:01:27 by motero           ###   ########.fr       */
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
# include "maths.h"

/*############################################################################*/
/*                          RAYCASTINGFUNCTIONS                               */
/*############################################################################*/
int	ft_render(t_cub*data);

#endif