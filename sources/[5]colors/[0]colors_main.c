/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [0]colors_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motero <motero@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:03:21 by motero            #+#    #+#             */
/*   Updated: 2023/02/22 22:03:39 by motero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.h"

/* Encode of 4 unint8_t into a utin32_t, so mlx is able to read RGB in Hex,**
** thourgh bit shifting. */
uint32_t	encode_rgb(uint8_t hue, uint8_t red, uint8_t green, uint8_t blue)
{
	return (hue << 24 | red << 16 | green << 8 | blue);
}
