// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void f_fill(char **tab, int width, int height, int row, int col)
// {
//     if (row < 0 || col < 0 || row >= height || col >= width)
//         return;
//     if (tab[row][col] == 'F' || tab[row][col] != '0')
//         return;
//     tab[row][col] = 'F';
//     f_fill(tab, width, height, row -1, col);
//     f_fill(tab, width, height, row +1, col);
//     f_fill(tab, width, height, row, col - 1);
//     f_fill(tab, width, height, row, col + 1);
// }

// void flood_fill(char **tab, int width, int height, int xstart, int ystart)
// {
//     f_fill(tab, width, height, xstart, ystart);
// }

// int check_player(char c)
// {
//     return(c == 'N' || c == 'W' || c == 'E' || c == 'S');
// }


// int	get_player_pos(char **map)
// {
// 	int x;
// 	int	y;
//     int pos;
//     int player;

//     player = 0;
//     y = 0;
// 	while (map[y])
//     {
//         x = 0;
//         while (map[y][x])
//         {
//             if (check_player(map[y][x]))
// 	        {
//                 pos = ((y << 16) | x);
//                 player++;
//             }
//             x++;
//         }
//         y++;
//     }
//     if (player == 1)
//         return (pos);
//     return (0);
// 	/* to decode the parameter :
// 	*y = (pos >> 16) & 0xFFFF;
//     *x = pos & 0xFFFF; */
// }

// int check_case(char **map)
// {
//     int x;
//     int y;
    
//     y = 0;

//     while (map[y])
//     {
//         x = 0;
//         while(map[y][x])
//         {
//             if (map[y][x] == '0')
//             {
//                 if (!check_player(map[y][x -1]) && map[y][x -1]  > '1')
//                     return(0);
//                 if (!check_player(map[y][x + 1]) && map[y][x + 1]  > '1')
//                     return(0);
//                 if (!check_player(map[y + 1][x]) && map[y + 1][x] > '1')
//                     return(0);
//                 if (!check_player(map[y -1][x]) && map[y - 1][x]  > '1')
//                     return(0);
//             }
//             x++;
//         }   
//         y++;
//     }
//     return (1);
// }
