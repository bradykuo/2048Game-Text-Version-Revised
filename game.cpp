#include "2048.h"
#include "exception.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

game::game() : score(0) {}  // Constructor implementation

void game::upmove(int a[4][4]) {
    int i, j, li, ri;
    for (j = 0; j < 4; j++) {
        li = 0, ri = j;
        for (i = 1; i < 4; i++) {
            if (a[i][j] != 0) {
                if (a[i - 1][j] == 0 || a[i - 1][j] == a[i][j]) {
                    if (a[li][ri] == a[i][j]) {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    } else {
                        if (a[li][ri] == 0) {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[++li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else li++;
            }
        }
    }
}

void game::downmove(int a[4][4]) {
    int i, j, li, ri;
    for (j = 0; j < 4; j++) {
        li = 3, ri = j;
        for (i = 2; i >= 0; i--) {
            if (a[i][j] != 0) {
                if (a[i + 1][j] == 0 || a[i + 1][j] == a[i][j]) {
                    if (a[li][ri] == a[i][j]) {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    } else {
                        if (a[li][ri] == 0) {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[--li][ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else li--;
            }
        }
    }
}

void game::leftmove(int a[4][4]) {
    int i, j, li, ri;
    for (i = 0; i < 4; i++) {
        li = i, ri = 0;
        for (j = 1; j < 4; j++) {
            if (a[i][j] != 0) {
                if (a[i][j - 1] == 0 || a[i][j - 1] == a[i][j]) {
                    if (a[li][ri] == a[i][j]) {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    } else {
                        if (a[li][ri] == 0) {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[li][++ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else ri++;
            }
        }
    }
}

void game::rightmove(int a[4][4]) {
    int i, j, li, ri;
    for (i = 0; i < 4; i++) {
        li = i, ri = 3;
        for (j = 2; j >= 0; j--) {
            if (a[i][j] != 0) {
                if (a[i][j + 1] == 0 || a[i][j + 1] == a[i][j]) {
                    if (a[li][ri] == a[i][j]) {
                        a[li][ri] *= 2;
                        a[i][j] = 0;
                        score += a[li][ri];
                    } else {
                        if (a[li][ri] == 0) {
                            a[li][ri] = a[i][j];
                            a[i][j] = 0;
                        } else {
                            a[li][--ri] = a[i][j];
                            a[i][j] = 0;
                        }
                    }
                } else ri--;
            }
        }
    }
}

void game::fun1(int i, int j, int li, int ri, int n, int a[4][4]) {
    int t = 0;
    while (t < n) {
        if (a[i][j] != 0) {
            if (a[i - 1][j - 1] == 0 || a[i - 1][j - 1] == a[i][j]) {
                if (a[li][ri] == a[i][j]) {
                    a[li][ri] *= 2;
                    a[i][j] = 0;
                    score += a[li][ri];
                } else {
                    if (a[li][ri] == 0) {
                        a[li][ri] = a[i][j];
                        a[i][j] = 0;
                    } else {
                        a[++li][++ri] = a[i][j];
                        a[i][j] = 0;
                    }
                }
            } else {
                li++;
                ri++;
            }
        }
        i++;
        j++;
        t++;
    }
}

void game::fun2(int i, int j, int li, int ri, int n, int a[4][4]) {
    int t = 0;
    while (t < n) {
        if (a[i][j] != 0) {
            if (a[i - 1][j + 1] == 0 || a[i - 1][j + 1] == a[i][j]) {
                if (a[li][ri] == a[i][j]) {
                    a[li][ri] *= 2;
                    a[i][j] = 0;
                    score += a[li][ri];
                } else {
                    if (a[li][ri] == 0) {
                        a[li][ri] = a[i][j];
                        a[i][j] = 0;
                    } else {
                        a[++li][--ri] = a[i][j];
                        a[i][j] = 0;
                    }
                }
            } else {
                li++;
                ri--;
            }
        }
        i++;
        j--;
        t++;
    }
}

void game::fun3(int i, int j, int li, int ri, int n, int a[4][4]) {
    int t = 0;
    while (t < n) {
        if (a[i][j] != 0) {
            if (a[i + 1][j + 1] == 0 || a[i + 1][j + 1] == a[i][j]) {
                if (a[li][ri] == a[i][j]) {
                    a[li][ri] *= 2;
                    a[i][j] = 0;
                    score += a[li][ri];
                } else {
                    if (a[li][ri] == 0) {
                        a[li][ri] = a[i][j];
                        a[i][j] = 0;
                    } else {
                        a[--li][--ri] = a[i][j];
                        a[i][j] = 0;
                    }
                }
            } else {
                li--;
                ri--;
            }
        }
        i--;
        j--;
        t++;
    }
}

void game::fun4(int i, int j, int li, int ri, int n, int a[4][4]) {
    int t = 0;
    while (t < n) {
        if (a[i][j] != 0) {
            if (a[i + 1][j - 1] == 0 || a[i + 1][j - 1] == a[i][j]) {
                if (a[li][ri] == a[i][j]) {
                    a[li][ri] *= 2;
                    a[i][j] = 0;
                    score += a[li][ri];
                } else {
                    if (a[li][ri] == 0) {
                        a[li][ri] = a[i][j];
                        a[i][j] = 0;
                    } else {
                        a[--li][++ri] = a[i][j];
                        a[i][j] = 0;
                    }
                }
            } else {
                li--;
                ri++;
            }
        }
        i--;
        j++;
        t++;
    }
}

void game::upperleftmove(int a[4][4]) {
    fun1(1, 3, 0, 2, 1, a);
    fun1(1, 2, 0, 1, 2, a);
    fun1(1, 1, 0, 0, 3, a);
    fun1(2, 1, 1, 0, 2, a);
    fun1(3, 1, 2, 0, 1, a);
}

void game::upperrightmove(int a[4][4]) {
    fun2(1, 0, 0, 1, 1, a);
    fun2(1, 1, 0, 2, 2, a);
    fun2(1, 2, 0, 3, 3, a);
    fun2(2, 2, 1, 3, 2, a);
    fun2(3, 2, 2, 3, 1, a);
}

void game::lowerrightmove(int a[4][4]) {
    fun3(2, 0, 3, 1, 1, a);
    fun3(2, 1, 3, 2, 2, a);
    fun3(2, 2, 3, 3, 3, a);
    fun3(1, 2, 2, 3, 2, a);
    fun3(0, 2, 1, 3, 1, a);
}

void game::lowerleftmove(int a[4][4]) {
    fun4(0, 1, 1, 0, 1, a);
    fun4(1, 1, 2, 0, 2, a);
    fun4(2, 1, 3, 0, 3, a);
    fun4(2, 2, 3, 1, 2, a);
    fun4(2, 3, 3, 2, 1, a);
}

void game::addblock(int a[4][4]) {
    int li, ri;
    srand(time(0));
    while (1) {
        li = rand() % 4;
        ri = rand() % 4;
        if (a[li][ri] == 0) {
            a[li][ri] = pow(2, li % 2 + 1);
            break;
        }
    }
}

void game::disp(int a[4][4]) {
    cout << "\n\t\t\tPress Esc anytime to quit the game";
    cout << "\n\n\n\n";
    int i, j;
    for (i = 0; i < 4; i++) {
        cout << "\t\t\t\t-----------------\n\t\t\t\t";
        for (j = 0; j < 4; j++) {
            if (a[i][j] == 0) cout << "|   ";
            else
                cout << "| " << a[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "\t\t\t\t-----------------\n";
    cout << "\t\tScore : " << score << "\n\n";
    cout << "\tQ : upperleft\tW : up  \tE : upperright\tD : right\n";
    cout << "\tC : lowerright\tX : down\tZ : lowerleft\tA : left\n";
    cout << "\tS : save\tL : load\n\n";
}

void game::save(int a[4][4]) {
    fstream gameFile;
    gameFile.open("test.txt", ios::out | ios::trunc);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            gameFile << a[i][j] << " ";
    gameFile.close();
}

void game::load(int a[4][4]) {
    ifstream gameFile;
    gameFile.open("test.txt");
    try {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                gameFile >> a[i][j];
                if (a[i][j] % 2 != 0 || a[i][j] < 0)
                    throw FileCorruptedException();
            }
        }
    }
    catch(FileCorruptedException &filecorruptedexception) {
        cout << "Exception occurred : " << filecorruptedexception.what() << endl;
        int i1, i2, i3, i4;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                a[i][j] = 0;
        srand(time(0));
        i1 = rand() % 4;
        i2 = rand() % 4;
        while (1) {
            i3 = rand() % 4;
            i4 = rand() % 4;
            if (i3 != i1 && i4 != i2)
                break;
        }
        a[i1][i2] = 2;
        a[i3][i4] = 4;
        score = 0;
    }
    gameFile.close();
}

int game::check(int tmp[4][4], int a[4][4]) {
    int fl = 1, i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (tmp[i][j] != a[i][j]) {
                fl = 0;
                break;
            }
    return fl;
}

int game::checkover(int a[4][4]) {
    int fl = 0, gl = 0, i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j] == 0) {
                fl = 1;
                break;
            }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (a[i + 1][j] == a[i][j] || a[i][j + 1] == a[i][j] || 
                a[i - 1][j + 1] == a[i][j] || a[i + 1][j + 1] == a[i][j]) {
                gl = 1;
                break;
            }

    if (fl || gl) return 1;
    else return 0;
}

int game::checkwin(int a[4][4]) {
    int fl = 0, i, j;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++)
            if (a[i][j] == 2048) {
                fl = 1;
                break;
            }

    if (fl == 0) return 1;
    else return 0;
}