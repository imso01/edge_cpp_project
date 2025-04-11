#ifndef CAR_H
#define CAR_H

#include "object.h"

class car : public object
{
    public:
        car(int x, int y, int w, int h, int ci, int dir);
        
        void Car_Move(char map[24][32]);
        virtual void Draw_Object();
};

#endif