#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *txtvw_main, *dlg_file_choose, *dlg_about;
	GtkTextBuffer *textbuffer_main;
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

	widgets->txtvw_main = GTK_WIDGET(gtk_builder_get_object(builder, "txtvw_main"));
	widgets->dlg_file_choose = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_file_choose"));
	widgets->dlg_about = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_about"));
	widgets->textbuffer_main = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "textbuffer_main"));

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
	gchar *file_contents = NULL;
	gboolean file_success = FALSE;

	gtk_widget_show(wgts->dlg_file_choose);

	if(gtk_dialog_run(GTK_DIALOG(wgts->dlg_file_choose)) == GTK_RESPONSE_OK) {
		file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(wgts->dlg_file_choose));
		if(file_name != NULL) {
			file_success = g_file_get_contents(file_name, &file_contents, NULL, NULL);
			if(file_success) {
				gtk_text_buffer_set_text(wgts->textbuffer_main, file_contents, -1);
			}
			g_free(file_contents);
		}
		g_free(file_name);
	}
	gtk_widget_hide(wgts->dlg_file_choose);
}

void on_menuitem_close_activate(GtkMenuItem *menu_item, app_widgets *wgts)
{
	gtk_text_buffer_set_text(wgts->textbuffer_main, "", -1);
}

void on_menuitem_quit_activate(GtkMenuItem *menu_item, app_widgets *wgts)
{
	gtk_main_quit();
}

void on_menuitem_about_activate(GtkMenuItem *menu_item, app_widgets *wgts)
{
	gtk_widget_show(wgts->dlg_about);
}

void on_dlg_about_response(GtkDialog *dlg, gint response_id, app_widgets *wgts)
{
	gtk_widget_hide(wgts->dlg_about);
}

void on_win_destroy()
{
	gtk_main_quit();
}