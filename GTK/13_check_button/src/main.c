#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *chkbtn_1, *chkbtn_2, *chkbtn_3, *lbl_option;
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
	widgets->chkbtn_1 = GTK_WIDGET(gtk_builder_get_object(builder, "chkbtn_1"));
	widgets->chkbtn_2 = GTK_WIDGET(gtk_builder_get_object(builder, "chkbtn_2"));
	widgets->chkbtn_3 = GTK_WIDGET(gtk_builder_get_object(builder, "chkbtn_3"));
	widgets->lbl_option = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_option"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_chkbtn_toggled(GtkToggleButton *chkbtn, app_widgets *wgts)
{
	gchar *chkbtn_name = g_malloc(MAX_STR);
	gchar *chkbtn_name_checked = g_malloc(MAX_STR);
	gchar *chkbtn_name_unchecked = g_malloc(MAX_STR);

	g_snprintf(chkbtn_name, MAX_STR, "%s", gtk_widget_get_name(GTK_WIDGET(chkbtn)));
	g_snprintf(chkbtn_name_checked, MAX_STR, "%s%s", chkbtn_name, " checked");
	g_snprintf(chkbtn_name_unchecked, MAX_STR, "%s%s", chkbtn_name, " unchecked");
	
	if(gtk_toggle_button_get_active(chkbtn)) 
		gtk_label_set_text(GTK_LABEL(wgts->lbl_option), chkbtn_name_checked);
	else
		gtk_label_set_text(GTK_LABEL(wgts->lbl_option), chkbtn_name_unchecked);
}

void on_win_destroy()
{
	gtk_main_quit();
}