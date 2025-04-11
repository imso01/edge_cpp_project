#include "defined.h"
#include "frog.h"

frog::frog(int x, int y, int w, int h, int ci, int dir) : object(x, y, w, h, ci, dir)
{
}

void frog::Frog_Move(int k, char map[24][32])
{
    //0:up 1:down 2:left 3:right
    if (k == 0 && this->y > Y_MIN && map[(this->y - FROG_STEP) / 10][this->x / 10] != '1')
        this->y -= FROG_STEP;
    else if (k == 1 && (this->y + this->h < Y_MAX) && map[(this->y + FROG_STEP) / 10][this->x / 10] != '1')
        this->y += FROG_STEP;
    else if (k == 2 && (this->x > X_MIN) && map[this->y / 10][(this->x - FROG_STEP) / 10] != '1')
        this->x -= FROG_STEP;
    else if (k == 3 && (this->x + this->w < X_MAX) && map[this->y / 10][(this->x + FROG_STEP) / 10] != '1')	
        this->x += FROG_STEP;
}

void frog::Draw_Object()
{
    static unsigned short color_f[] = {RED, YELLOW, GREEN, BLUE, WHITE, BLACK};
    // Lcd_Draw_Box(this->x, this->y, this->w, this->h, color_o[this->ci]);

    unsigned char pacman_arr[FROG_SIZE_Y][FROG_SIZE_X] = {
      {0, 0, 1, 1, 1, 1, 1, 1, 0, 0}, 
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}, 
      {1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
      {1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 1, 0, 0, 0}, 
      {1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
      {0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
      {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    };
    
    for (int i = 0; i < FROG_SIZE_Y; i++) 
    {
        for (int j = 0; j < FROG_SIZE_X; j++) 
        {
            if (pacman_arr[i][j] == 1)
                Lcd_Put_Pixel(this->x + j, this->y + i, color_f[this->ci]);
            else
                Lcd_Put_Pixel(this->x + j, this->y + i, BLACK);
        }
    }
}