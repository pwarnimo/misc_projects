#include <gtk/gtk.h>

void show_about(GtkWidget *widget, gpointer data) {
	GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file("srvmon.png", NULL);

	GtkWidget *dialog = gtk_about_dialog_new();

	gtk_about_dialog_set_name(GTK_ABOUT_DIALOG(dialog), "SRVMON NOTIFICATOR");
	gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "1.0 R2");
	gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "(c) Pol Warnimont");
	gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(dialog), "The SRVMON NOTIFICATOR is a simple check tool.");
	gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(dialog), "https://github.com/pwarnimo/srvmon");
	gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog), pixbuf);

	g_object_unref(pixbuf), pixbuf = NULL;

	gtk_dialog_run(GTK_DIALOG(dialog));
	
	gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *about;
	GdkPixbuf *battery;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 150);
	gtk_window_set_title(GTK_WINDOW(window), "SRVMON");

	gtk_container_set_border_width(GTK_CONTAINER(window), 15);
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK);

	battery = gtk_image_get_pixbuf(GTK_IMAGE(gtk_image_new_from_file("srvmon.png")));

	g_signal_connect(G_OBJECT(window), "button-press-event", G_CALLBACK(show_about), (gpointer)window);
	g_signal_connect_swapped(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
