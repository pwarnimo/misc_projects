#include <cairo.h>
#include <math.h>
#include <gtk/gtk.h>

void do_drawing(cairo_t *);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	do_drawing(cr);

	return FALSE;
}

void do_drawing(cairo_t *cr) {
	gint i;
	
	for (i = 1; i <= 10; i++) {
		cairo_set_source_rgba(cr, 0, 0, 1, i * 0.1);
		cairo_rectangle(cr, 50 * i, 20, 40, 40);
		cairo_fill(cr);
	}
}

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

	g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 800, 200);
	gtk_window_set_title(GTK_WINDOW(window), "Transparency");

	gtk_widget_set_app_paintable(window, TRUE);
	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
