#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mathfn.h"

gchar* display = "";

void clearScreen(GtkEntry *screen) {
	display = "";
	addToResult((float)atof(display));
}

void onWindowDestroy(GtkObject *object, gpointer userData) {
	gtk_main_quit();
}

void addNumber(GtkButton *button, gpointer userData) {
	display = g_strdup_printf("%s%s", display, gtk_button_get_label(button));

	gtk_entry_set_text(GTK_ENTRY(userData), display);
}

void performAddition(GtkButton *button, gpointer userData) {
	currOperation = "+";

	addToResult((float)atof(display));
	clearScreen(GTK_ENTRY(userData));

	printf("REG A == %f\n", currValue);

	gtk_entry_set_text(GTK_ENTRY(userData), g_strdup_printf("%f", currValue));
}

void calculateFinal(GtkButton *button, gpointer userData) {
	switch(*currOperation) {
		case '+' :
			addToResult((float)atof(display));
			gtk_entry_set_text(GTK_ENTRY(userData), g_strdup_printf("%f", currValue));

			break;
	}
}

int main(int argc, char *argv[]) {
	GtkBuilder *builder;
	GtkWidget *window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "calc.glade", NULL);
	window = GTK_WIDGET(gtk_builder_get_object(builder, "frmMain"));
	gtk_builder_connect_signals(builder, gtk_builder_get_object(builder, "entry1"));
	
	g_object_unref(G_OBJECT(builder));

	gtk_widget_show(window);
	gtk_main();

	return 0;
}
