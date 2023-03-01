/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:41:27 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 23:18:03 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ENGINE_H
# define MLX_ENGINE_H

# include "mlx.h"
# include "mlx_int.h"
# include "structures.h"
# include "colors.h"
# include "cub3D.h"


# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

/*############################################################################*/
/*                              MLX_ENGINE FUNCTIONS                          */
/*############################################################################*/

int	ft_mlx_initialize_pointers(t_cub *data);
int	ft_mlx_create_window_and_image(t_cub *data);

#endif