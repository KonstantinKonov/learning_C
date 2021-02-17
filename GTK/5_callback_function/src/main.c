#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

int attempts = 0,
	number = 0,
	state = 0; // 0 - idle, 1 - in progress, 2 - finished; 

int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	gtk_builder_connect_signals(builder, NULL);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	return 0;
}

void on_win_destroy()
{
	gtk_main_quit();
}

void on_btn_exit_clicked()
{
	gtk_main_quit();
}

void on_btn_version_clicked(GtkButton *button, GtkLabel *text_label)
{
	char str_version[MAX_STR];
	sprintf(str_version, "%d.%d.%d", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);
	g_print("glib version: %s.\n", str_version);
	gtk_label_set_text(GTK_LABEL(text_label), str_version);	
}