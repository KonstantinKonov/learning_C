#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

char filename[] = "text.txt";
FILE *fp;

GtkWidget *lbl_version, *edit_bet, *lbl_status;

int attempts = 0,
	number = 0,
	state = 0; // 0 - idle, 1 - in progress, 2 - finished; 

int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	gtk_builder_connect_signals(builder, NULL);

	lbl_version = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_version"));
	lbl_status = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_status"));
	edit_bet = GTK_WIDGET(gtk_builder_get_object(builder, "edit_bet"));

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	return 0;
}

void get_version()
{
	char str_version[MAX_STR];
	sprintf(str_version, "%d.%d.%d", GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);
	g_print("glib version: %s.\n", str_version);
	gtk_label_set_text(GTK_LABEL(lbl_version), str_version);	
}

void start_new_game()
{
	attempts = 0;
	number = g_random_int_range(0, 101);
	state = 1; // the game is in progress

	char str_status[MAX_STR];
	sprintf(str_status, "attempts: %d\nguess the number from 0 to 100", attempts);
	gtk_label_set_text(GTK_LABEL(lbl_status), str_status);
}

void make_guess()
{
	if(state != 1) return;
	
	attempts++;

	const char *str_guess = gtk_entry_get_text(GTK_ENTRY(edit_bet));
	int guess = atoi(str_guess);

	if(guess == number)
	{
		state = 2;
		char str_status[MAX_STR];
		sprintf(str_status, "attempts: %d\nnumber guessed: %d\npress the 'new game' button", attempts, number);
		gtk_label_set_text(GTK_LABEL(lbl_status), str_status);
	} 
	else if(guess > number)
	{
		char str_status[MAX_STR];
		sprintf(str_status, "attempts: %d\nguess %d is MORE than number", attempts, guess);
		gtk_label_set_text(GTK_LABEL(lbl_status), str_status);
	}
	else if(guess < number)
	{
		char str_status[MAX_STR];
		sprintf(str_status, "attempts: %d\nguess %d is LESS than number", attempts, guess);
		gtk_label_set_text(GTK_LABEL(lbl_status), str_status);
	}

}

void on_win_destroy()
{
	gtk_main_quit();
}

void on_btn_exit_clicked()
{
	gtk_main_quit();
}

void on_btn_version_clicked()
{
	get_version();
}

void on_btn_newgame_clicked() 
{
	start_new_game();
}

void on_btn_bet_clicked()
{
	make_guess();
}