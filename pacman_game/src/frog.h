#ifndef FROG_H
#define FROG_H

#include "object.h"

class frog : public object
{
    public:
        frog(int x, int y, int w, int h, int ci, int dir);
        
        void Frog_Move(int k, char map[24][32]);
        virtual void Draw_Object();
};

#endif