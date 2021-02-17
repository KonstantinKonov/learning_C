#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *lbl_caption, *lbl_time;
} app_widgets;

gboolean timer_handler(app_widgets *wgts);

int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	app_widgets *widgets = g_slice_new(app_widgets);

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	widgets->lbl_caption = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_caption"));
	widgets->lbl_time = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_time"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	// start 1 second timer
	timer_handler(widgets);
	g_timeout_add_seconds(1, (GSourceFunc)timer_handler, widgets);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_win_destroy()
{
	gtk_main_quit();
}

gboolean timer_handler(app_widgets *wgts)
{
	GDateTime *date_time;
	gchar *dt_format;

	date_time = g_date_time_new_now_local();
	dt_format = g_date_time_format(date_time, "%b %e %Y %H:%M:%S");
	gtk_label_set_text(GTK_LABEL(wgts->lbl_time), dt_format);
	g_free(dt_format);

	return TRUE;
}