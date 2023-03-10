/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_engine.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:41:27 by motero            #+#    #+#             */
/*   Updated: 2023/03/04 17:07:16 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_ENGINE_H
# define MLX_ENGINE_H

# include "mlx.h"
# include "mlx_int.h"
# include "structures.h"
# include "colors.h"
# include "cub3D.h"
# include "my_maths.h"
# include <math.h>

/*############################################################################*/
/*                              BUTTONS DEFINITION                            */
/*############################################################################*/

# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define MINUS_PAD 65453
# define PLUS_PAD 65451
# define ONE_PAD 65436
# define TWO_PAD 65433
# define THREE_PAD 65435
# define FOUR_PAD 65430
# define FIVE_PAD 65437
# define SIX_PAD 65432
# define MINUS_KEY 45
# define PLUS_KEY 61
# define BRACE_L_KEY 91
# define BRACE_R_KEY 93
# define D_KEY 100
# define C_KEY 99
# define Z_KEY 122
# define Q_KEY 113
# define S_KEY 115
# define A_KEY 97
# define W_KEY 119

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

# ifndef FOV
#  define FOV 90
# endif

/*############################################################################*/
/*                              DRAW FUNCTIONS                                */
/*############################################################################*/

void	img_pix_put(t_img_data *img, int x, int y, int color);
void	draw_celling_floor(t_cub *data);

/*############################################################################*/
/*                              MLX_ENGINE FUNCTIONS                          */
/*############################################################################*/

int		ft_mlx_initialize_pointers(t_cub *data);
int		ft_mlx_create_window_and_image(t_cub *data);

/*############################################################################*/
/*                              MLX_ENGINE HOOKS                          */
/*############################################################################*/

void	ft_mlx_engine(t_cub *data);
int		ft_handle_boutonpress(int buttonsym, int x, int y, t_cub *data);
int		ft_handle_keyrelease(int keysym, t_cub *data);
int		ft_destroy_window(t_cub *data);
int		ft_handle_keypress(int keysym, t_cub *data);

/*############################################################################*/
/*                              KEYPRESS EVENTS                               */
/*############################################################################*/

void	ft_destroy_window_button(int keysym, t_cub *data);
void	ft_movements_keys(int keysym, t_cub *data);
void	ft_keyboard_press(int keysym, t_cub *data);

/*############################################################################*/
/*                             MOVING ACTIONS                                 */
/*############################################################################*/
void	move_forward(t_cub *data);
void	move_backward(t_cub *data);
void	move_left(t_cub *data);
void	move_right(t_cub *data);

/*############################################################################*/
/*                             ROTATING ACTIONS                               */
/*############################################################################*/
void	rotate_counter_clockwise(t_cub *data, float ratio);
void	rotate_clockwise(t_cub *data, float ratio);

#endif