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
    bool mines_array[MS_HEIGHT][MS_WIDTH];
    int touching[MS_HEIGHT][MS_WIDTH];
    bool seen[MS_HEIGHT][MS_WIDTH];
};

void clear_map(minesweep *m) {
    int i, j;

    for (i = 0; i < MS_HEIGHT; i++) {
        for (j = 0; j < MS_WIDTH; j++) {
            m->mines_array[i][j] = 0;
            m->touching[i][j] = 0;
            m->seen[i][j] = 0;
        }
    }
}

void place_mine(minesweep *m) {
    bool placed = 0;
    int x_pos, y_pos;
    while (!placed) {
        x_pos = rand() % MS_WIDTH;
        y_pos = rand() % MS_HEIGHT;
        if (!m->mines_array[y_pos][x_pos]) {
            placed = 1;
            m->mines_array[y_pos][x_pos] = 1;
        }
    }
}

void init_map(minesweep *m) {
    int i;
    for (i = 0; i < NUM_MINES; i++) {
        place_mine(m);
    }
}

void render_mines_map(minesweep *m) {
    int i, j;
    for (i = 0; i < MS_HEIGHT; i++) {
        for (j = 0; j < MS_WIDTH; j++) {
            if (m->mines_array[j][i]) {
                mvprintw(j, i, "*");
            }
        }
    }
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
    minesweep *m = new minesweep;

    clear_map(m);
    init_map(m);
    render_mines_map(m);

    do {
        in = getch();
    } while (in != 27);

	endwin();
}
