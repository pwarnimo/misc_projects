#include <gtk/gtk.h>
#include <gdk/gdkkeysyms.h>

int main(int argc, char *argv[]) {
	// WIDGETS

	GtkWidget *window;
	GtkWidget *vbox;
	
	GtkWidget *menubar;
	GtkWidget *filemenu;
	GtkWidget *file;
	GtkWidget *new;
	GtkWidget *open;
	GtkWidget *save;
	GtkWidget *saveas;
	GtkWidget *quit;
	GtkWidget *editmenu;
	GtkWidget *edit;
	GtkWidget *prefs;
	GtkWidget *helpmenu;
	GtkWidget *help;
	GtkWidget *documentation;
	GtkWidget *about;
	GtkWidget *mmiViewMenu;
	GtkWidget *mmiView;
	GtkWidget *mmiSBShow;

	GtkWidget *tbMain;
	GtkToolItem *tbtnNew;
	GtkToolItem *tbtnOpen;
	GtkToolItem *tbtnSave;
	GtkToolItem *tbtnPrefs;
	GtkToolItem *tbSep;

	GtkWidget *sbMain;

	GtkWidget *sep;

	// OTHER VARS

	GtkAccelGroup *accel_group = NULL;

	// FORM CREATION
	
	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
	gtk_window_set_title(GTK_WINDOW(window), "Minidraw/GTK");

	// FORM CONTROLS

	vbox = gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	menubar = gtk_menu_bar_new();
	filemenu = gtk_menu_new();
	editmenu = gtk_menu_new();
	helpmenu = gtk_menu_new();
	mmiViewMenu = gtk_menu_new();

	accel_group = gtk_accel_group_new();
	gtk_window_add_accel_group(GTK_WINDOW(window), accel_group);

	sep = gtk_separator_menu_item_new();

	file = gtk_menu_item_new_with_mnemonic("_File");
	new = gtk_image_menu_item_new_from_stock(GTK_STOCK_NEW, NULL);
	open = gtk_image_menu_item_new_from_stock(GTK_STOCK_OPEN, NULL);
	save = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE, NULL);
	saveas = gtk_image_menu_item_new_from_stock(GTK_STOCK_SAVE_AS, NULL);
	quit = gtk_image_menu_item_new_from_stock(GTK_STOCK_QUIT, NULL);
	
	edit = gtk_menu_item_new_with_mnemonic("_Edit");
	prefs = gtk_image_menu_item_new_from_stock(GTK_STOCK_PREFERENCES, NULL);
	
	mmiView = gtk_menu_item_new_with_mnemonic("_View");
	mmiSBShow = gtk_check_menu_item_new_with_label("Show Statusbar");
	gtk_check_menu_item_set_active(GTK_CHECK_MENU_ITEM(mmiSBShow), TRUE);

	help = gtk_menu_item_new_with_mnemonic("_Help");
	documentation = gtk_image_menu_item_new_from_stock(GTK_STOCK_HELP, NULL);
	about = gtk_image_menu_item_new_from_stock(GTK_STOCK_ABOUT, NULL);
	
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(file), filemenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(edit), editmenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(help), helpmenu);
	gtk_menu_item_set_submenu(GTK_MENU_ITEM(mmiView), mmiViewMenu);

	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), new);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), open);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), save);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), saveas);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), sep);
	gtk_menu_shell_append(GTK_MENU_SHELL(filemenu), quit);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), file);
	
	gtk_menu_shell_append(GTK_MENU_SHELL(editmenu), prefs);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), edit);

	gtk_menu_shell_append(GTK_MENU_SHELL(mmiViewMenu), mmiSBShow);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), mmiView);

	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), documentation);
	gtk_menu_shell_append(GTK_MENU_SHELL(helpmenu), about);
	gtk_menu_shell_append(GTK_MENU_SHELL(menubar), help);

	gtk_box_pack_start(GTK_BOX(vbox), menubar, FALSE, FALSE, 0);

	tbMain = gtk_toolbar_new();
	gtk_toolbar_set_style(GTK_TOOLBAR(tbMain), GTK_TOOLBAR_ICONS);

	gtk_container_set_border_width(GTK_CONTAINER(tbMain), 1);

	tbSep = gtk_separator_tool_item_new();

	tbtnNew = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
	gtk_toolbar_insert(GTK_TOOLBAR(tbMain), tbtnNew, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(tbMain), tbSep, -1);
	tbtnOpen = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
	gtk_toolbar_insert(GTK_TOOLBAR(tbMain), tbtnOpen, -1);
	tbtnSave = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
	gtk_toolbar_insert(GTK_TOOLBAR(tbMain), tbtnSave, -1);
	gtk_toolbar_insert(GTK_TOOLBAR(tbMain), tbSep, -1);
	tbtnPrefs = gtk_tool_button_new_from_stock(GTK_STOCK_PREFERENCES);
	gtk_toolbar_insert(GTK_TOOLBAR(tbMain), tbtnPrefs, -1);

	gtk_box_pack_start(GTK_BOX(vbox), tbMain, FALSE, FALSE, 0);

	sbMain = gtk_statusbar_new();
	gtk_box_pack_end(GTK_BOX(vbox), sbMain, FALSE, FALSE, 0);

	// SIGNAL DEFINITIONS

	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
