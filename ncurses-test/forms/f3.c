#include <form.h>
#include <stdlib.h>

FIELD **fi;
FORM *fo;

void quit(void) {
	int i;

	unpost_form(fo);
	free_form(fo);

	for (i = 0; i <= 3; i++) {
		free_field(fi[i]);
	}

	free(fi);
	endwin();
}

int main(int argc, char *argv[]) {
	int ch;
	int i;

	initscr();
	atexit(quit);
	clear();
	noecho();
	curs_set(0);
	cbreak();
	keypad(stdscr, TRUE);
	start_color();

	init_pair(1, COLOR_YELLOW, COLOR_BLUE);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);

	bkgd(COLOR_PAIR(1));

	fi = (FIELD **)calloc(4, sizeof(FIELD *));
	fi[0] = new_field(1, 10, 2, 3, 0, 0);
	fi[1] = new_field(1, 10, 2, 18, 0, 0);
	fi[2] = new_field(1, 15, 2, 33, 0, 0);
	fi[3] = 0;

	for (i = 0; i < 3; i++) {
		set_field_fore(fi[i], COLOR_PAIR(2));
		set_field_back(fi[i], COLOR_PAIR(2));
		field_opts_off(fi[i], O_AUTOSKIP);
	}

	set_field_type(fi[0], TYPE_INTEGER, 0, -9999999, 9999999);
	set_field_type(fi[1], TYPE_NUMERIC, 3, -9999999.999, 9999999.999);
	field_opts_off(fi[2], O_EDIT);

	fo = new_form(fi);
	post_form(fo);

	mvaddstr(2, 15, "+");
	mvaddstr(2, 30, "=");
	mvaddstr(5, 3, "Programm mittels F2-Funktionstaste beenden");

	refresh();

	while ((ch = getch()) != KEY_F(2)) {
		double z1;
		double z2;
		char str[20];

		switch (ch) {
			case KEY_RIGHT: {
				form_driver(fo, REQ_NEXT_FIELD);

				if (field_index(current_field(fo)) == 2) {
					z1 = atof(field_buffer(fi[0], 0));
					z2 = atof(field_buffer(fi[1], 0));
					snprintf(str, 20, "%f", z1 + z2);
					set_field_buffer(fi[2], 0, str);
					refresh();
				}

				break;
			}

			case KEY_LEFT:
				form_driver(fo, REQ_PREV_FIELD);
				break;

			default:
				form_driver(fo, ch);
		}
	}

	return 0;
}
