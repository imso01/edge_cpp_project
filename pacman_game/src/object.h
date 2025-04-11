#ifndef OBJECT_H
#define OBJECT_H

#include "lcd.h"

class object
{
	protected:
		int x,y;
		int w,h;
		int ci;
		int dir;
    public:
		object();
		object(int x, int y, int w, int h, int ci, int dir);

		int getX();
		int getY();
		int getW();
		int getH();
		int getCi();
		int getDir();

		void setX(int x);
		void setY(int y);
		void setW(int w);
		void setH(int h);
		void setCi(int ci);
		void setDir(int dir);
		
		virtual void Draw_Object() = 0;
};

#endif