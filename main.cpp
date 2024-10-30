#include <iostream>
#include <fstream>
#include "2048.h"
#include "exception.h"
#include <cstdlib>
#include <ctime>
#include <termios.h>
#include <unistd.h>
using namespace std;

// Function to get a single character from input without waiting for Enter
char getChar() {
    char buf = 0;
    struct termios old;
    tcgetattr(0, &old);  // Get current terminal settings
    
    struct termios newSettings = old;  // Create new settings based on old
    newSettings.c_lflag &= ~ICANON;
    newSettings.c_lflag &= ~ECHO;
    newSettings.c_cc[VMIN] = 1;
    newSettings.c_cc[VTIME] = 0;
    
    if (tcsetattr(0, TCSANOW, &newSettings) < 0) {
        perror("tcsetattr ICANON");
    }
    
    if (read(0, &buf, 1) < 0) {
        perror("read()");
    }
    
    if (tcsetattr(0, TCSADRAIN, &old) < 0) {
        perror("tcsetattr ~ICANON");
    }
    
    return buf;
}

// Function to clear screen
void clearScreen() {
    cout << "\033[2J\033[H";
}

int main() {
    cout << "\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
    getChar();

    while (true) {
        clearScreen();
        game g;
        int i1, i2, i3, i4, i, j;
        int a[4][4] = {{0}};    // Properly initialize with braces
        int tmp[4][4] = {{0}};  // Properly initialize with braces

        // Initialize random seed
        srand(time(0));
        i1 = rand() % 4;
        i2 = rand() % 4;
        do {
            i3 = rand() % 4;
            i4 = rand() % 4;
        } while (i3 == i1 && i4 == i2);

        a[i1][i2] = 2;
        a[i3][i4] = 4;
        g.score = 0;
        g.disp(a);

        while (true) {
            // Copy current state
            for (i = 0; i < 4; i++) {
                for (j = 0; j < 4; j++) {
                    tmp[i][j] = a[i][j];
                }
            }

            char ch = getChar();
            clearScreen();

            // Game controls
            switch(ch) {
                case 'w': case 'W':  // Up
                    g.upmove(a);
                    break;
                case 'x': case 'X':  // Down
                    g.downmove(a);
                    break;
                case 'a': case 'A':  // Left
                    g.leftmove(a);
                    break;
                case 'd': case 'D':  // Right
                    g.rightmove(a);
                    break;
                case 'e': case 'E':  // Upper right
                    g.upperrightmove(a);
                    break;
                case 'c': case 'C':  // Lower right
                    g.lowerrightmove(a);
                    break;
                case 'q': case 'Q':  // Upper left
                    g.upperleftmove(a);
                    break;
                case 'z': case 'Z':  // Lower left
                    g.lowerleftmove(a);
                    break;
                case 's': case 'S':  // Save
                    g.save(a);
                    break;
                case 'l': case 'L':  // Load
                    g.load(a);
                    break;
                case 'b': case 'B': case 27:  // Quit (q or ESC)
                    return 0;
            }

            if (!g.check(tmp, a)) {
                g.addblock(a);
            }

            g.disp(a);

            if (!g.checkover(a)) {
                cout << "\n\n\t\t\tGAME OVER!!\n\n\n";
                cout << "\t\tPress any key to start new game...\n";
                getChar();
                break;
            }

            if (!g.checkwin(a)) {
                cout << "\n\n\t\t\tYOU WIN!!\n\n\n";
                cout << "\t\tPress any key to start new game...\n";
                getChar();
                break;
            }
        }
    }
    return 0;
}