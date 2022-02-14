#include <stdio.h>
#include <curses.h>
#include <stdlib.h>

int i;
int j;
int height = 20;
int width = 20;
int gameover;
int score;
int x;
int y;
int fruit_x;
int fruit_y;

void draw(void);

int main()
{
    draw();
    return 0;
}

void draw()
{
    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}