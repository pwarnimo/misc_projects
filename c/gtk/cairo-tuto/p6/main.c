#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>

static void do_drawing(cairo_t *, GtkWidget *);

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	do_drawing(cr, widget);

	return FALSE;
}

static void do_drawing(cairo_t *cr, GtkWidget *widget) {
	cairo_set_line_width(cr, 10);

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_BUTT);
	cairo_move_to(cr, 30, 50);
	cairo_line_to(cr, 150, 50);
	cairo_stroke(cr);

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
	cairo_move_to(cr, 30, 90);
	cairo_line_to(cr, 150, 90);
	cairo_stroke(cr);

	cairo_set_line_cap(cr, CAIRO_LINE_CAP_SQUARE);
	cairo_move_to(cr, 30, 130);
	cairo_line_to(cr, 150, 130);
	cairo_stroke(cr);
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
	gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);
	gtk_window_set_title(GTK_WINDOW(window), "Pen");

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
