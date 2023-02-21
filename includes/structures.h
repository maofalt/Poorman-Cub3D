#ifndef STRUCTURES_H
# define STRUCTURES_H

# include <stdint.h>
# include "libft.h"
# include "get_next_line.h"
# include "mlx_int.h"
#include "parsing.h"

/*############################################################################*/
/*                              STRUCTURES                                    */
/*############################################################################*/

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
	int			**map;
	t_image		sprite[4];
}	t_cub;


#endif