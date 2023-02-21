#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdint.h>
# include "libft.h"
# include "get_next_line.h"
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
** http://gcc.gnu.org/onlinedocs/gcc-4.6.1/gcc/Vector-Extensions.html#Vector-Extensions
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

typdef struct s_cub
{
	uint32_t	floor;
	uint32_t	celling;
	size_t		mapwidth;
	size_t		mapheight;
	int			**map;
	t_img		texture[4];
}				t_cub;

#endif