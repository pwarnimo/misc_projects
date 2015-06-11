#include <curses.h>
#include <stdlib.h>

WINDOW *win;

void quit(void) {
	delwin(win);
	endwin();
}

int main(int argc, char *argv[]) {
	initscr();
	atexit(quit);
	clear();
	noecho();
	curs_set(0);
	cbreak();
	keypad(stdscr, 1);

	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);

	win = newwin(5, 20, 10, 10);

	bkgd(COLOR_PAIR(1));
	wbkgd(win, COLOR_PAIR(2));

	mvaddstr(5, 5, "stdscr");
	mvwaddstr(win, 3, 3, "Hallo win");

	box(win, 0, 0);
	mvhline(7, 1, ACS_BULLET, 20);

	refresh();
	wrefresh(win);

	while (getch() != KEY_F(2)) {
	}

	return 0;
}
