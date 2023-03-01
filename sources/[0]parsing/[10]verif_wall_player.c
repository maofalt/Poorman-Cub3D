/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   [10]verif_wall_player.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanthoma <yanthoma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:02:42 by yanthoma          #+#    #+#             */
/*   Updated: 2023/03/01 19:58:15 by yanthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

/*verify that the map is walled and has the only one player
we have a bonus useless floodfill

to decode the parameter from get_player_pos:
*y = (pos >> 16) & 0xFFFF;
*x = pos & 0xFFFF; 
*/

int check_player(char c)
{
    return(c == 'N' || c == 'W' || c == 'E' || c == 'S');
}

int check_wall(char **map)
{
    int x;
    int y;
    
    y = 0;

    while (map[y])
    {
        x = 0;
        while(map[y][x])
        {
            if (map[y][x] == '0')
            {
                if (!check_player(map[y][x -1]) && map[y][x -1]  > '1')
                    return(0);
                if (!check_player(map[y][x + 1]) && map[y][x + 1]  > '1')
                    return(0);
                if (!check_player(map[y + 1][x]) && map[y + 1][x] > '1')
                    return(0);
                if (!check_player(map[y -1][x]) && map[y - 1][x]  > '1')
                    return(0);
            }
            x++;
        }   
        y++;
    }
    return (1);
}

int	get_player_pos(char **map)
{
	int x;
	int	y;
    int pos;
    int player;

    player = 0;
    y = 0;
	while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (check_player(map[y][x]))
	        {
                pos = ((y << 16) | x);
                player++;
            }
            x++;
        }
        y++;
    }
    if (player == 1)
        return (pos);
    return (0);
}