#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *tgbtn_1, *tgbtn_2, *tgbtn_3, *lbl_state;
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
	widgets->tgbtn_1 = GTK_WIDGET(gtk_builder_get_object(builder, "tgbtn_1"));
	widgets->tgbtn_2 = GTK_WIDGET(gtk_builder_get_object(builder, "tgbtn_2"));
	widgets->tgbtn_3 = GTK_WIDGET(gtk_builder_get_object(builder, "tgbtn_3"));
	widgets->lbl_state = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_state"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_tgbtn_1_toggled(GtkToggleButton *tgbtn, app_widgets *wgts)
{
	gboolean tgbtn_state;
	tgbtn_state = gtk_toggle_button_get_active(tgbtn);

	if(tgbtn_state) {
		gtk_label_set_text(GTK_LABEL(wgts->lbl_state), "btn1 toggled on");
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wgts->tgbtn_2), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wgts->tgbtn_3), FALSE);
	}
	else gtk_label_set_text(GTK_LABEL(wgts->lbl_state), "btn1 toggled off");
}


void on_tgbtn_2_toggled(GtkToggleButton *tgbtn, app_widgets *wgts)
{
	gboolean tgbtn_state = gtk_toggle_button_get_active(tgbtn);

	if(tgbtn_state == TRUE) {
		gtk_label_set_text(GTK_LABEL(wgts->lbl_state), "btn2 toggled on");
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wgts->tgbtn_1), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wgts->tgbtn_3), FALSE);
	}
	else gtk_label_set_text(GTK_LABEL(wgts->lbl_state), "btn2 toggled off");
}

void on_tgbtn_3_toggled(GtkToggleButton *tgbtn, app_widgets *wgts)
{
	gboolean tgbtn_state = gtk_toggle_button_get_active(tgbtn);

	if(tgbtn_state == TRUE) {
		gtk_label_set_text(GTK_LABEL(wgts->lbl_state), "btn3 toggled on");
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wgts->tgbtn_1), FALSE);
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(wgts->tgbtn_2), FALSE);
	}
	else gtk_label_set_text(GTK_LABEL(wgts->lbl_state), "btn3 toggled off");
}

void on_win_destroy()
{
	gtk_main_quit();
}