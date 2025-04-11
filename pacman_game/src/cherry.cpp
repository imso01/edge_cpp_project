#include "cherry.h"
#include "defined.h"
#include "device_driver.h"

cherry::cherry()
{
    // x와 y 초기화
    int tempX[2][3] = {
        {16, 2, 6},
        {26, 11, 6}
    };
    int tempY[2][3] = {
        {20, 2, 18},
        {17, 8, 11}
    };

    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j) {
            x[i][j] = tempX[i][j];
            y[i][j] = tempY[i][j];
        }

    // cherryExistance 초기화
    cherryExistance[0] = true;
    cherryExistance[1] = true;
    cherryExistance[2] = true;

    // cherryArr 초기화
    int tempArr[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 3, 0, 3, 0, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 3, 0, 0, 0},
        {0, 0, 3, 0, 0, 0, 0, 3, 0, 0},
        {0, 2, 2, 2, 0, 0, 2, 2, 2, 0},
        {0, 2, 2, 2, 0, 0, 2, 2, 2, 0},
        {0, 2, 2, 2, 0, 0, 2, 2, 2, 0},
        {0, 2, 2, 2, 0, 0, 2, 2, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cherryArr[i][j] = tempArr[i][j];
}

void cherry::drawCherry(int num, int mapNum)
{
    int x = this->x[mapNum][num] * 10;
    int y = this->y[mapNum][num] * 10;

    for (int i = 0; i < FROG_SIZE_Y; i++) 
    {
        for (int j = 0; j < FROG_SIZE_X; j++) 
        {
            if (cherryArr[i][j] == 2)
                Lcd_Put_Pixel(x + j, y + i, RED);
            else if (cherryArr[i][j] == 3)
                Lcd_Put_Pixel(x + j, y + i, GREEN);
        }
    }
}

void cherry::eraseCherry(int cherryNum, int mapNum)
{
    if (cherryNum == 0)
        return ;

    int x = this->x[mapNum][cherryNum - 1] * 10;
    int y = this->y[mapNum][cherryNum - 1] * 10;

    for (int i = 0; i < FROG_SIZE_Y; i++) 
    {
        for (int j = 0; j < FROG_SIZE_X; j++) 
        {
            Lcd_Put_Pixel(x + j, y + i, BLACK);
        }
    }
}