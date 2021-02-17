#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *rb_1, *rb_2, *rb_3, *lbl_picked;
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
	widgets->rb_1 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_1"));
	widgets->rb_2 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_2"));
	widgets->rb_3 = GTK_WIDGET(gtk_builder_get_object(builder, "rb_3"));
	widgets->lbl_picked = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_picked"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_win_destroy()
{
	gtk_main_quit();
}

void on_rb_1_toggled(GtkToggleButton *tbtn, app_widgets *app_wdgt)
{
	gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_picked), "1%");
}

void on_rb_2_toggled(GtkToggleButton *tbtn, app_widgets *app_wdgt)
{
	gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_picked), "2%");
}

void on_rb_3_toggled(GtkToggleButton *tbtn, app_widgets *app_wdgt)
{
	gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_picked), "3%");
}