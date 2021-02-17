#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

GtkWidget *g_btn_1, *g_btn_exit;

int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	gtk_builder_connect_signals(builder, NULL);

	g_btn_1 = GTK_WIDGET(gtk_builder_get_object(builder, "btn_1"));
	g_btn_exit = GTK_WIDGET(gtk_builder_get_object(builder, "btn_exit"));

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

void on_btn_1_clicked()
{
	on_btn_exit_clicked();
}