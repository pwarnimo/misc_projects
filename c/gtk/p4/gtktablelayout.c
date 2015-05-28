#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
	GtkWidget *window;

	GtkWidget *table;
	GtkWidget *button;

	char *values[16] = {
		"7", "8", "9", "/",
		"4", "5", "6", "*",
		"1", "2", "3", "-",
		"0", ".", "=", "+"
	};

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GtkTable");
	gtk_window_set_default_size(GTK_WINDOW(window), 290, 200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	gtk_container_set_border_width(GTK_CONTAINER(window), 5);

	table = gtk_table_new(4, 4, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(table), 2);

	int x = 0;
	int y = 0;
	int pos = 0;

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			button = gtk_button_new_with_label(values[pos]);
			gtk_table_attach_defaults(GTK_TABLE(table), button, x, x+1, y, y+1);
			pos++;
		}
	}

	gtk_container_add(GTK_CONTAINER(window), table);

	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
