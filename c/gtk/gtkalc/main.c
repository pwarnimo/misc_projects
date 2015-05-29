#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>
#include <string.h>

int currentVal = 0;
char currentOp;

void getDigit(GtkButton *button, gpointer data) {
	const char *op = gtk_button_get_label(button);
	GtkEntry *display = data;
	const char *text = gtk_entry_get_text(GTK_ENTRY(data));

	//currentVal = atoi(text);
	printf("Stored val = %d\n", currentVal);

	switch (*op) {
		case '=':
			printf("OP = Equals\n");
		break;

		case '+':
			printf("OP = Addition");
			currentVal = currentVal + atoi(text);
			
		break;

		default:
			if (strcmp(text, "0") == 0) {
				gtk_entry_set_text(GTK_ENTRY(data), "");
			}

			gtk_entry_append_text(GTK_ENTRY(data), op);
			printf("DISPLAY = %s\n", text);
		break;
	}
}

int main(int argc, char *argv[]) {
	printf("GTKalc 0.1\n");

	GtkWidget *window;
	GtkWidget *vbox;
	GtkWidget *table;

	GtkWidget *menubar;
	GtkWidget *filemenu;
	GtkWidget *file;
	GtkWidget *quit;
	
	GtkWidget *statusbar;

	GtkWidget *button;
	GtkWidget *display;

	char *buttonCaptions[16] = {
		"7", "8", "9", "/",
		"4", "5", "6", "*",
		"1", "2", "3", "-",
		"0", ",", "=", "+"
	};

	GtkAccelGroup *accel_group = NULL;
	
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 250);
	gtk_window_set_title(GTK_WINDOW(window), "GTKalc");

	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	filemenu = gtk_menu_new();

	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	file = gtk_menu_item_new_with_mnemonic("_File");
	quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, accel_group);

	gtk_widget_add_accelerator(quit, "activate", accel_group, GDK_q, GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);

	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 3);

	display = gtk_entry_new();	
	gtk_entry_set_text(GTK_ENTRY(display), "0");
	gtk_box_pack_start(GTK_BOX(vbox), display, FALSE, FALSE, 1);

	// Main calculator buttons

	table = gtk_table_new(4, 4, TRUE);
	gtk_table_set_row_spacings(GTK_TABLE(table), 2);
	gtk_table_set_col_spacings(GTK_TABLE(table), 2);

	int x = 0;
	int y = 0;
	int pos = 0;

	for (y = 0; y < 4; y++) {
		for (x = 0; x < 4; x++) {
			button = gtk_button_new_with_label(buttonCaptions[pos]);
			g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(getDigit), G_OBJECT(display));
			gtk_table_attach_defaults(GTK_TABLE(table), button, x, x+1, y, y+1);
			pos++;
		}
	}

	gtk_box_pack_start(GTK_BOX(vbox), table, TRUE, TRUE, 1);

	// Statusbar definition

	statusbar = gtk_statusbar_new();
	gtk_box_pack_end(GTK_BOX(vbox), statusbar, FALSE, FALSE, 1);

	g_signal_connect(G_OBJECT(quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	// READY FOR INPUT
	gchar *str;
	str = "Ready";
	gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), str), str);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
