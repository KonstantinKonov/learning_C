#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *spbtn_value, *lbl_value, *btn_update;
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
	widgets->spbtn_value = GTK_WIDGET(gtk_builder_get_object(builder, "spbtn_value"));
	widgets->lbl_value = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_value"));
	widgets->btn_update = GTK_WIDGET(gtk_builder_get_object(builder, "btn_update"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_btn_update_clicked(GtkButton *btn, app_widgets *wgts)
{
	guint32 value = 0;
	gchar out_str[100] = "0";

	value = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(wgts->spbtn_value));
	g_snprintf(out_str, sizeof(out_str), "%d", value);
	gtk_label_set_text(GTK_LABEL(wgts->lbl_value), out_str);
}

void on_win_destroy()
{
	gtk_main_quit();
}