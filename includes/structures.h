/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:24:57 by motero            #+#    #+#             */
/*   Updated: 2023/02/27 03:25:12 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdint.h>
# include <stdio.h>
# include "libft.h"
# include "../gnl/get_next_line.h"
# include "colors.h"
# include "mlx_int.h"

/*############################################################################*/
/*                              STRUCTURES                                    */
/*############################################################################*/

/* bpp = bits per pixel */
typedef struct s_img_data
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img_data;

/* Vector structure for 2D float vector
** Vector structure for 2D unsigned int vector
** Vector structure for 2D int vectors
** causes the compiler to set the mode for foo, 
** to be 16 bytes, divided into int sized units.
** SIMD vectorrization 
** https://users.ece.cmu.edu/~franzf/teaching/slides-18-645-simd.pdf
** 
*/

typedef float			t_vector_f __attribute__((vector_size (8)));
typedef unsigned int	t_vector_u __attribute__((vector_size (8)));
typedef int				t_vector_i __attribute__((vector_size (8)));

/* Parsing structure for CUB3D stocking information from .cub file
** a wolrd map in a 2D int array of MAPWIDTH * MAPHEIGHT
** a array  of size 4 of sprites using t_image from the mlx
** in the order from indx 0 to 3 : N, S, E, W
** a uint_32_t for the color of the floor
** a uint_32_t for the color of the ceiling
*/

typedef struct s_cub
{
	uint32_t	floor;
	uint32_t	celling;
	size_t		mapwidth;
	size_t		mapheight;
	char		**map;
	t_vector_f	player_pos;
	t_img_data	texture[4];
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_img_data	screen;
}				t_cub;

#endif