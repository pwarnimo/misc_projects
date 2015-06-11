#include <menu.h>
#include <stdlib.h>

ITEM **it;
MENU *me;
WINDOW *win;

void quit(void) {
	int i;

	unpost_menu(me);
	free_menu(me);

	for (i = 0; i <= 4; i++) {
		free_item(it[i]);
	}

	free(it);
	delwin(win);

	endwin();
}

int main(int argc, char *argv[]) {
	int ch;

	initscr();
	atexit(quit);
	clear();
	noecho();
	curs_set(0);
	cbreak();
	nl();
	keypad(stdscr, TRUE);
	start_color();

	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	init_pair(2, COLOR_BLUE, COLOR_YELLOW);

	bkgd(COLOR_PAIR(1));

	it = (ITEM **)calloc(5, sizeof(ITEM *));
	it[0] = new_item("SERV", "Server Overview");
	it[1] = new_item("SVCS", "Services Management");
	it[2] = new_item("USER", "User management");
	it[3] = new_item("SETT", "Settings");
	it[4] = new_item("EXIT", "Close this program");
	it[5] = 0;
	me = new_menu(it);

	win = newwin(9, 30, 3, 2);
	set_menu_win(me, win);
	set_menu_sub(me, derwin(win, 5, 28, 3, 2));
	box(win, 0, 0);
	mvwaddstr(win, 1, 2 , "*** SRVMON MENU ***");
	set_menu_fore(me, COLOR_PAIR(1)|A_REVERSE);
	set_menu_back(me, COLOR_PAIR(1));
	wbkgd(win, COLOR_PAIR(2));

	post_menu(me);

	mvaddstr(15, 2, "<F9> = Close");

	refresh();
	wrefresh(win);

	while ((ch = getch()) != KEY_F(9)) {
		switch(ch) {
			case KEY_DOWN:
				menu_driver(me, REQ_DOWN_ITEM);
				break;

			case KEY_UP:
				menu_driver(me, REQ_UP_ITEM);
				break;

			case 0xA:
				if (item_index(current_item(me)) == 3) {
					exit(0);
				}
		}

		wrefresh(win);
	}

	return 0;
}
