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
# define X_KEY 122
# define Z_KEY 120
# define Q_KEY 113
# define S_KEY 100
# define A_KEY 97


# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

/*############################################################################*/
/*                              MLX_ENGINE FUNCTIONS                          */
/*############################################################################*/

int	    ft_mlx_initialize_pointers(t_cub *data);
int	    ft_mlx_create_window_and_image(t_cub *data);

/*############################################################################*/
/*                              MLX_ENGINE HOOKS                          */
/*############################################################################*/

void	ft_mlx_engine(t_cub *data);
int	    ft_handle_boutonpress(int buttonsym, int x, int y, t_cub *data);
int	    ft_handle_keyrelease(int keysym, t_cub *data);
int	    ft_destroy_window(t_cub *data);
int 	ft_handle_keypress(int keysym, t_cub *data);

/*############################################################################*/
/*                              KEYPRESS EVENTS                               */
/*############################################################################*/

void	ft_destroy_window_button(int keysym, t_cub *data);
void	ft_movements_keys(int keysym, t_cub *data);
void	ft_keyboard_press(int keysym, t_cub *data);

#endif