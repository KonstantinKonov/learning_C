#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *rb_none, *rb_tails, *rb_heads, *lbl_bet, *lbl_result, *lbl_win_lose, *btn_toss_coin, *btn_restart;
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
	widgets->rb_none = GTK_WIDGET(gtk_builder_get_object(builder, "rb_none"));
	widgets->rb_tails = GTK_WIDGET(gtk_builder_get_object(builder, "rb_tails"));
	widgets->rb_heads = GTK_WIDGET(gtk_builder_get_object(builder, "rb_heads"));
	widgets->lbl_bet = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_bet"));
	widgets->lbl_result = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_result"));
	widgets->lbl_win_lose = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_win_lose"));
	widgets->btn_toss_coin = GTK_WIDGET(gtk_builder_get_object(builder, "btn_toss"));
	widgets->btn_restart = GTK_WIDGET(gtk_builder_get_object(builder, "btn_restart"));
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

void on_rb_toggled(GtkToggleButton *tbtn, app_widgets *app_wdgt)
{
	if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_none)))
		gtk_widget_set_sensitive(app_wdgt->btn_toss_coin, FALSE);
	else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_tails)))
	{
		gtk_widget_set_sensitive(app_wdgt->btn_toss_coin, TRUE);
		gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_bet), "TAILS");
	}
	else if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_heads)))
	{
		gtk_widget_set_sensitive(app_wdgt->btn_toss_coin, TRUE);
		gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_bet), "HEADS");
	}	
}

void on_btn_toss_clicked(GtkButton *btn, app_widgets *app_wdgt)
{
	gboolean result = g_random_boolean();
	gchar str_win[] = "<span foreground='green' weight='bold' font='14'>Win</span>";
	gchar str_lose[] = "<span foreground='red' weight='bold' font='14'>Lose</span>";

	if(result == TRUE && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_heads))) {
		gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_result), "HEADS");
		gtk_label_set_markup(GTK_LABEL(app_wdgt->lbl_win_lose), str_win);
	}

	else if(result == FALSE && gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_tails))) {
		gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_result), "TAILS");
		gtk_label_set_markup(GTK_LABEL(app_wdgt->lbl_win_lose), str_win);
	}
	else {
		if(result == TRUE) {
			gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_result), "HEADS");
		}
		else {
			gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_result), "TAILS");
		}
		gtk_label_set_markup(GTK_LABEL(app_wdgt->lbl_win_lose), str_lose);
	}

	gtk_widget_set_sensitive(app_wdgt->btn_toss_coin, FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_none), TRUE);
}

void on_btn_restart_clicked(GtkButton *btn, app_widgets *app_wdgt)
{
	gtk_widget_set_sensitive(app_wdgt->btn_toss_coin, FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(app_wdgt->rb_none), TRUE);
	gtk_label_set_markup(GTK_LABEL(app_wdgt->lbl_win_lose), "");
	gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_bet), "");
	gtk_label_set_text(GTK_LABEL(app_wdgt->lbl_result), "");
}