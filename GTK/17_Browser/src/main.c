#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>
#include <webkit2/webkit2.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *webkit_view;
} app_widgets;


int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	app_widgets *widgets = g_slice_new(app_widgets);

	gtk_init(&argc, &argv);

	webkit_web_view_get_type();
	webkit_settings_get_type();

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));

	widgets->webkit_view = GTK_WIDGET(gtk_builder_get_object(builder, "webkit_view"));

	gtk_builder_connect_signals(builder, widgets);

	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(widgets->webkit_view), "www.google.com");

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_entry_url_activate(GtkEntry *entry, app_widgets *wgts)
{
	const gchar *url_entered;

	url_entered = gtk_entry_get_text(entry);

	webkit_web_view_load_uri(WEBKIT_WEB_VIEW(wgts->webkit_view), url_entered);
}

void on_win_destroy()
{
	gtk_main_quit();
}