/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 03:24:57 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 16:58:23 by motero           ###   ########.fr       */
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

/* bpp = bits per pixel */
typedef struct s_img_data
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_vector_i	size;
}	t_img_data;

/* Parsing structure for CUB3D stocking information from .cub file
** a wolrd map in a 2D int array of MAPWIDTH * MAPHEIGHT
** a array  of size 4 of sprites using t_image from the mlx
** in the order from indx 0 to 3 : N, S, E, W
** a uint_32_t for the color of the floor
** a uint_32_t for the color of the ceiling
*/

typedef struct s_player
{
	t_vector_f	pos;
	t_vector_f	dir;
	t_vector_f	plane;
}				t_player;

typedef struct s_dda
{
	t_vector_f	ray_dir;
	t_vector_f	side_dist;
	t_vector_f	delta_dist;
	t_vector_i	map;
	t_vector_f	pos;
	t_vector_i	step;
	uint32_t	color;
	float		perp_wall_dist;
	float		tex_pos;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			hit;
	int			side;
	int			tex_y;
	int			x;
	t_vector_i	mouse;
}				t_dda;

typedef struct s_cub
{
	t_img_data	texture[4];
	t_img_data	screen;
	uint32_t	floor;
	uint32_t	celling;
	t_player	player;
	t_dda		dda;
	size_t		mapwidth;
	size_t		mapheight;
	t_img		img;
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	int			update;
}				t_cub;

typedef struct s_data
{
	char		**textures;
	char		**colors;
	char		***map;
}				t_data;

#endif