#ifndef CHERRY_H
#define CHERRY_H

class cherry
{
    public:
        int x[2][3];
        int y[2][3];
        bool cherryExistance[3];
        int cherryArr[10][10];

        cherry(); // 생성자 선언

        void drawCherry(int num, int mapNum);
        void eraseCherry(int cherryNum, int mapNum);
};

#endif