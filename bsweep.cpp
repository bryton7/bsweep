#include <stdio.h>
#include <iostream>
#include <ostream>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <ncurses.h>

#define MS_HEIGHT 16
#define MS_WIDTH  16
#define NUM_MINES 40

using namespace std;

class minesweep
{
public:
    bool mines_array[MS_WIDTH][MS_HEIGHT];
    int touching[MS_WIDTH][MS_HEIGHT];
    bool seen[MS_WIDTH][MS_HEIGHT];
};

void clear_map(minesweep *m) {
    int i, j;

    for (i = 0; i < MS_HEIGHT; i++) {
        for (j = 0; j < MS_HEIGHT; j++) {
            m->mines_array[i][j] = 0;
            m->touching[i][j] = 0;
            m->seen[i][j] = 0;
        }
    }
}

void init_map(minesweep *m) {

}

int main(int argc, char *argv[])
{
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    start_color();
	init_pair(COLOR_RED, COLOR_RED, COLOR_BLACK);                                
    init_pair(COLOR_GREEN, COLOR_GREEN, COLOR_BLACK);                            
    init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);                          
    init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);                              
    init_pair(COLOR_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);                        
    init_pair(COLOR_CYAN, COLOR_CYAN, COLOR_BLACK);                              
    init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK); 

    

    wchar_t in;

    do {
        in = getch();
    } while (in != 27);

	endwin();
}
