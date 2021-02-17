#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#define MAX_STR 100

GtkWidget *g_btn_reset, *g_btn_exit, *g_lbl_counter;
int counter = 0;
char str[MAX_STR];

int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	gtk_builder_connect_signals(builder, NULL);

	// g_btn_reset = GTK_WIDGET(gtk_builder_get_object(builder, "btn_reset"));
	// g_btn_exit = GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit"));
	g_lbl_counter = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_counter"));

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

void on_btn_reset_clicked()
{
	counter = 0;
	sprintf(str, "%d", counter);
	gtk_label_set_text(GTK_LABEL(g_lbl_counter), str);
}

void on_btn_minus_clicked()
{
	if(counter > 0) 
		counter--;
	sprintf(str, "%d", counter);
	gtk_label_set_text(GTK_LABEL(g_lbl_counter), str);
}

void on_btn_plus_clicked()
{
	counter++;
	sprintf(str, "%d", counter);
	gtk_label_set_text(GTK_LABEL(g_lbl_counter), str);
}