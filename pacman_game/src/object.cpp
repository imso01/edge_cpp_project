#include "object.h"

// static unsigned short color_o[] = {RED, YELLOW, GREEN, BLUE, WHITE, BLACK};

object::object()
{
    
}

object::object(int x, int y, int w, int h, int ci, int dir)
{
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->ci = ci;
    this->dir = dir;
    
}

int object::getX()
{
    return (this->x);
}

int object::getY()
{
    return (this->y);
}

int object::getW()
{
    return (this->w);
}

int object::getH()
{
    return (this->h);
}

int object::getCi()
{
    return (this->ci);
}

int object::getDir()
{
    return (this->dir);
}

void object::setX(int x)
{
    this->x = x;
}
void object::setY(int y)
{
    this->y = y;
}

void object::setW(int w)
{
    this->w = w;
}

void object::setH(int h)
{
    this->h = h;
}

void object::setCi(int ci)
{
    this->ci = ci;
}

void object::setDir(int dir)
{
    this->dir = dir;
}

// void object::Draw_Object()
// {
//     Lcd_Draw_Box(this->x, this->y, this->w, this->h, color_o[this->ci]);
// }