/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:16:07 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 22:29:47 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdint.h>
# include "libft.h"
# include "../gnl/get_next_line.h"
# include "structures.h"
# include "parsing.h"
# include "mlx_engine.h"
# include "mlx_int.h"
# include "colors.h"
# include "raycasting.h"
# include "maths.h"

# ifndef FOV
#  define FOV 60
# endif


/*############################################################################*/
/*                              GENERAL FUNCTIONS                             */
/*############################################################################*/
void	free_everything(t_cub data);

#endif