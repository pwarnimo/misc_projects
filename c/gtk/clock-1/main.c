#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include <time.h>

struct tm *tmstruct;

static void do_drawing(cairo_t *, GtkWidget *);

static double convertToRAD(double angle) {
	return (M_PI / 180) * angle;
}

static gboolean on_draw_event(GtkWidget *widget, cairo_t *cr, gpointer user_event) {
	do_drawing(cr, widget);

	return FALSE;
}

static void do_drawing(cairo_t *cr, GtkWidget *widget) {
	GtkWidget *win = gtk_widget_get_toplevel(widget);

	int width, height;
	gtk_window_get_size(GTK_WINDOW(win), &width, &height);

	cairo_set_line_width(cr, 2);
	cairo_set_source_rgb(cr, 1.0, 0, 0);

	//cairo_translate(cr, width / 2, height / 2);
	cairo_arc(cr, width / 2, height / 2, 150, 0, 2 * M_PI);
	cairo_stroke(cr);

	cairo_arc(cr, width / 2, height / 2, 5, 0 ,2 * M_PI);
	cairo_stroke(cr);

	//cairo_translate(cr, 0, 0);

	int i;
	int pl_x1;
	int pl_y1;
	int pl_x2;
	int pl_y2;

	for (i = 1; i <= 12; i++) {
		pl_x1 = 150 * cos(convertToRAD((360 / 12) * i)) + (width / 2);
		pl_y1 = 150 * sin(convertToRAD((360 / 12) * i)) + (height / 2); 
		pl_x2 = 145 * cos(convertToRAD((360 / 12) * i)) + (width / 2);
		pl_y2 = 145 * sin(convertToRAD((360 / 12) * i)) + (height / 2); 

		printf("%d, PL (%d,%d,%d,%d)\n", i, pl_x1, pl_y1, pl_x2, pl_y2);

		cairo_move_to(cr, pl_x1, pl_y1);
		cairo_line_to(cr, pl_x2, pl_y2);

		cairo_stroke(cr);
	}

	time_t epoch_time;

	epoch_time = time(NULL);

	tmstruct = localtime(&epoch_time);

	//printf("H=%d\n", tmstruct->tm_hour);
	cairo_move_to(cr, 130 * cos(convertToRAD(((360 / 12) * tmstruct->tm_hour) -90)) + (width / 2), 130 * sin(convertToRAD(((360 / 12) * tmstruct->tm_hour) -90)) + (height / 2));
	cairo_line_to(cr, width / 2, height / 2);
	cairo_stroke(cr);

	cairo_move_to(cr, 150 * cos(convertToRAD(((360 / 60) * tmstruct->tm_min) -90)) + (width / 2), 150 * sin(convertToRAD(((360 / 60) * tmstruct->tm_min) -90)) + (height / 2));
	cairo_line_to(cr, width / 2, height / 2);
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
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	gtk_window_set_title(GTK_WINDOW(window), "Clock");

	gtk_widget_show_all(window);

	gtk_main();

	return 0;
}
