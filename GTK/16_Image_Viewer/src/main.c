#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *img_main;
	GtkWidget *dlg_file_choose;
} app_widgets;


int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	app_widgets *widgets = g_slice_new(app_widgets);

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));

	widgets->img_main = GTK_WIDGET(gtk_builder_get_object(builder, "img_main"));
	widgets->dlg_file_choose = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_file_choose"));

	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_menuitem_open_activate(GtkMenuItem *menuitem, app_widgets *wgts)
{
	gchar *file_name = NULL;

	gtk_widget_show(GTK_WIDGET(wgts->dlg_file_choose));

	if(gtk_dialog_run(GTK_DIALOG(wgts->dlg_file_choose)) == GTK_RESPONSE_OK) {
		file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(wgts->dlg_file_choose));
		if(file_name != NULL) {
			gtk_image_set_from_file(GTK_IMAGE(wgts->img_main), file_name);
		}
		g_free(file_name);
	}

	gtk_widget_hide(wgts->dlg_file_choose);
}

void on_menuitem_close_activate(GtkMenuItem *menu_item, app_widgets *wgts)
{
	gtk_image_set_from_file(GTK_IMAGE(wgts->img_main), NULL);	
}

void on_menuitem_quit_activate(GtkMenuItem *menu_item, app_widgets *wgts)
{
	gtk_main_quit();
}

void on_win_destroy()
{
	gtk_main_quit();
}