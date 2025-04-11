#include "defined.h"
#include "car.h"
#include "device_driver.h"

car::car(int x, int y, int w, int h, int ci, int dir) : object(x, y, w, h, ci, dir)
{
}

void car::Car_Move(char map[24][32])
{
    if (map[this->y / 10][(this->x + (CAR_STEP * this->dir)) / 10] == '1')
        this->dir = -this->dir;
    else if (((this->x + (CAR_STEP * this->dir)) % 10 != 0) && (map[this->y / 10][(this->x + (CAR_STEP * this->dir * 2)) / 10] == '1'))
        this->dir = -this->dir;
    else
        this->x += CAR_STEP * this->dir;
}

void car::Draw_Object()
{
    // Lcd_Draw_Box(this->x, this->y, this->w, this->h, color_o[this->ci]);
    
    static unsigned short color_c[] = {RED, YELLOW, GREEN, BLUE, WHITE, BLACK};

    unsigned char car_arr[CAR_SIZE_Y][CAR_SIZE_X] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 0, 0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    
    for (int i = 0; i < CAR_SIZE_Y; i++) 
    {
        for (int j = 0; j < CAR_SIZE_X; j++) 
        {
            if (car_arr[i][j] == 1)
                Lcd_Put_Pixel(this->x + j, this->y + i, color_c[this->ci]);
            else
                Lcd_Put_Pixel(this->x + j, this->y + i, BLACK);
        }
    }
}