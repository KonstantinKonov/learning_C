#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#define MAX_STR 1000

char filename[] = "text.txt";
FILE *fp;

GtkWidget *lbl_state, *txt_main;

int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	gtk_builder_connect_signals(builder, NULL);


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

void on_btn_read_clicked()
{
	fp = fopen(filename, "r");
	char *str = malloc(MAX_STR * sizeof(char));
	fread(str, 1, MAX_STR, fp);
	fclose(fp);
	printf("%s\n", str);
	
	GtkTextBuffer *buff = malloc(MAX_STR * sizeof(char));
	gtk_text_buffer_set_text(buff, str, strlen(str));
	gtk_text_view_set_buffer(GTK_TEXT_VIEW(txt_main), buff);

}

void on_btn_write_clicked()
{

}