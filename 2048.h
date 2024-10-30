#ifndef GAME_H
#define GAME_H

#include <iostream>

class game {
public:
    game();  // Only declaration, no implementation

    void upmove(int[4][4]);
    void upperrightmove(int[4][4]);
    void upperleftmove(int[4][4]);
    void downmove(int[4][4]);
    void lowerrightmove(int[4][4]);
    void lowerleftmove(int[4][4]);
    void leftmove(int[4][4]);
    void rightmove(int[4][4]);
    void addblock(int[4][4]);
    void disp(int[4][4]);
    void save(int[4][4]);
    void load(int[4][4]);
    int check(int[4][4], int[4][4]);
    int checkover(int[4][4]);
    int checkwin(int[4][4]);
    int score;

private:
    void fun1(int i, int j, int li, int ri, int n, int[4][4]);
    void fun2(int i, int j, int li, int ri, int n, int[4][4]);
    void fun3(int i, int j, int li, int ri, int n, int[4][4]);
    void fun4(int i, int j, int li, int ri, int n, int[4][4]);
};

#endif