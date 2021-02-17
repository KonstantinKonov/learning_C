#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *txt_vw;
	GtkTextBuffer *txt_buff;
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
	widgets->txt_vw = GTK_WIDGET(gtk_builder_get_object(builder, "txt_vw"));
	widgets->txt_buff = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txt_buff"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_btn_exec_clicked(GtkButton *btn, app_widgets *wgts)
{
	gboolean result;
	gchar *std_out;
	gchar *std_err;
	gint exit_state;
	GError *err;

	result = g_spawn_command_line_sync(
		"free -h",
		&std_out,
		&std_err,
		&exit_state,
		&err
	);

	if(result == FALSE) {
		g_print("An error occured\n");
	}
	else {
		gtk_text_buffer_set_text(wgts->txt_buff, std_out, -1);
	}
}

void on_btn_exit_clicked(GtkButton *btn, app_widgets *wgts)
{
	gtk_main_quit();
}

void on_win_destroy()
{
	gtk_main_quit();
}