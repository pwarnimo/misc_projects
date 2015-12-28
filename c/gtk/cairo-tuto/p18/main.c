#include <cairo.h>
#include <gtk/gtk.h>

static void do_drawing(cairo_t *);

struct {
	cairo_surface_t *surface;
} glob;

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
	do_drawing(cr);

	return FALSE;
}

static void do_drawing(cairo_t *cr) {
	cairo_set_source_rgb(cr, 0, 0, 0);
	cairo_mask_surface(cr, glob.surface, 0, 0);
	cairo_fill(cr);
}

static void create_surface() {
	glob.surface = cairo_image_surface_create_from_png("mask.png");
}

static void destroy_surface() {
	cairo_surface_destroy(glob.surface);
}

int main(int argc, char *argv[]) {
	GtkWidget *window;
	GtkWidget *darea;

	gtk_init(&argc, &argv);

	create_surface();

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	darea = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(window), darea);

	g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(on_draw_event), NULL);
	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 305, 100);
	gtk_window_set_title(GTK_WINDOW(window), "MASK");

	gtk_widget_show_all(window);

	gtk_main();

	destroy_surface();

	return 0;
}
