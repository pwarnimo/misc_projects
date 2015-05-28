#include <curses.h>
#include <stdlib.h>

void quit() {
	endwin();
}

int main(void) {
	int x;
	int y;

	initscr();
	atexit(quit);
	curs_set(0);

	mvprintw(3, 5, "LINES: %d", LINES);
	mvprintw(4, 5, "COLS:  %d", COLS);

	getyx(stdscr, y, x);
	mvprintw(5, 5, "Cursor pos :    [%d,%d]", y, x);

	getbegyx(stdscr, y, x);
	mvprintw(6, 5, "Coord. origin : [%d,%d]", y, x);

	getmaxyx(stdscr, y, x);
	mvprintw(7, 5, "Window size :   [%d,%d]", y, x);

	mvaddstr(11, 2, "Press any key to exit!");
	refresh();

	getch();
	return(0);
}
