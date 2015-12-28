#include <cairo.h>
#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
	gdk_init(&argc, &argv);

	GdkWindow *root_win = gdk_get_default_root_window();
	gint width = gdk_window_get_width(root_win);
	gint height = gdk_window_get_height(root_win);

	cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);

	GdkPixbuf *pb = gdk_pixbuf_get_from_window(root_win, 0, 0, width, height);

	cairo_t *cr = cairo_create(surface);
	gdk_cairo_set_source_pixbuf(cr, pb, 0, 0);
	cairo_paint(cr);

	cairo_surface_write_to_png(surface, "scrnsht.png");

	cairo_destroy(cr);
	cairo_surface_destroy(surface);

	return 0;
}
