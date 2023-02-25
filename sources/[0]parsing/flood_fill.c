#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void f_fill(char **tab, int width, int height, int row, int col)
{
    if (row < 0 || col < 0 || row >= height || col >= width)
        return;
    if (tab[row][col] == 'F' || tab[row][col] != '0')
        return;
    tab[row][col] = 'F';
    f_fill(tab, width, height, row -1, col);
    f_fill(tab, width, height, row +1, col);
    f_fill(tab, width, height, row, col - 1);
    f_fill(tab, width, height, row, col + 1);
}

void flood_fill(char **tab, int width, int height, int xstart, int ystart)
{
    f_fill(tab, width, height, xstart, ystart);
}

int check_player(char c)
{
    return(c == 'N' || c == 'W' || c == 'E' || c == 'S');
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
	/* to decode the parameter :
	*y = (pos >> 16) & 0xFFFF;
    *x = pos & 0xFFFF; */
}

int main()
{
   int i, j;
   (void)j;
    char *test[] = {
"***********************************\0",
"*1111111111111111111111111*********\0",
"*1000000000110000000000001*********\0",
"*1011000001110000000000001*********\0",
"*1001000000000000000000001*********\0",
"*111111111011000001110000000000001*\0",
"*100000000011000001110111111111111*\0",
"*11110111111111011100000010001*****\0,"
"*11110111111111011101010010001*****\0",
"*11000000110101011100000010001*****\0",
"*10000000000000001100000010001*****\0",
"*10000000000000001101010010001*****\0",
"*11000001110101011111011110N0111***\0",
"*11110111*1110101*101111010001*****\0",
"*11111111*1111111*111111111111*****\0",
"***********************************\0",
        NULL
    };




    // Get the dimensions of the array
    int height = 0;
    int width = strlen(test[0]);
    while (test[height] != NULL) {
        height++;
    }

    // Allocate a new 2D array
    char **copy = (char **) malloc(height * sizeof(char *));
    for (i = 0; i < height; i++) {
        copy[i] = (char *) malloc((width + 1) * sizeof(char));
        strcpy(copy[i], test[i]);
    }

    // Perform flood fill on the copy
    int x;
    int y;
    int pos;

    pos = get_player_pos(copy);
    y = (pos >> 16) & 0xFFFF;
    x = pos & 0xFFFF;
    printf("x = %d y = %d\n", x, y);
    copy[y][x] = '0';
    flood_fill(copy, width, height, y, x);

    // Print the original array
    printf("Original array:\n");
    for (i = 0; i < height; i++) {
        printf("%s\n", test[i]);
    }

    // Print the copy array
    printf("Copy array:\n");
    for (i = 0; i < height; i++) {
        printf("%s\n", copy[i]);
    }

    // Deallocate memory
    for (i = 0; i < height; i++) {
        free(copy[i]);
    }
    free(copy);

    return 0;
}
