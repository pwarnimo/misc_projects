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

	it = (ITEM **)calloc(5, sizeof(ITEM *));
	it[0] = new_item("M1", "Menueeintrag 1");
	it[1] = new_item("M2", "Menueeintrag 2");
	it[2] = new_item("M3", "Menueeintrag 3");
	it[3] = new_item("Ende", "Programm beenden");
	it[4] = 0;
	
	me = new_menu(it);

	win = newwin(8, 30, 5, 5);
	set_menu_win(me, win);
	set_menu_sub(me, derwin(win, 4, 28, 3, 2));
	box(win, 0, 0);
	mvwaddstr(win, 1, 2, "***** Testmenü *****");
	post_menu(me);

	mvaddstr(14, 3, "Programm mittels Menü oder F2-Funktionstaste beenden");

	refresh();
	wrefresh(win);

	while ((ch = getch()) != KEY_F(2)) {
		switch (ch) {
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
