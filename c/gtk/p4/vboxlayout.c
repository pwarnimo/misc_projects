#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *vbox;

	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *button3;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "GtkVBox");
	gtk_window_set_default_size(GTK_WINDOW(window), 290, 200);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

	vbox = gtk_vbox_new(TRUE, 1);
	gtk_container_add(GTK_CONTAINER(window), vbox);

	button1 = gtk_button_new_with_label("Btn1");
	button2 = gtk_button_new_with_label("Btn2");
	button3 = gtk_button_new_with_label("Btn3");

	gtk_box_pack_start(GTK_BOX(vbox), button1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), button3, TRUE, TRUE, 0);

	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
