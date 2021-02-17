#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>
#include "game_logic.h"

#define MAX_STR 1000

typedef struct {
	GtkWidget *img[9], *lbl_status;
	gboolean turn;
	gchar game_board[9];
	game_state gm_state;
} app_widgets;


int main(int argc, char **argv) 
{
	GtkBuilder	*builder;
	GtkWidget	*window;

	app_widgets *widgets = g_slice_new(app_widgets);
	gchar str_img[] = "img_0";

	widgets->turn = TRUE;
	widgets->gm_state = GM_BUSY;

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));

	//get a pointer to each image
	for(gint i = 0; i < 9; i++) {
		str_img[4] = i + '0';
		widgets->img[i] = GTK_WIDGET(gtk_builder_get_object(builder, str_img));
		widgets->game_board[i] = 0;
	}

	widgets->lbl_status = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_status"));

	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_btn_clicked(GtkButton *btn, app_widgets *wgts)
{
	gint btn_num;
	gint winning_blocks[3] = {0};

	if(wgts->gm_state != GM_BUSY) {
		return;
	}

	btn_num = gtk_widget_get_name(GTK_WIDGET(btn))[0] - '0';
	if(wgts->game_board[btn_num] == 0) {
		gtk_image_set_from_file(GTK_IMAGE(wgts->img[btn_num]), wgts->turn ? "pics/O.png" : "pics/X.png");
		wgts->game_board[btn_num] = wgts->turn ? 'o' : 'x';
		wgts->gm_state = get_game_state(wgts->game_board, winning_blocks);

		if(wgts->gm_state == GM_O_WON) {
			for(int i = 0; i < 3; i++) {
				gtk_image_set_from_file(GTK_IMAGE(wgts->img[winning_blocks[i]]), "pics/O_win.png");
			}
			gtk_label_set_text(GTK_LABEL(wgts->lbl_status), "Нолики выиграли!");
		}

		else if(wgts->gm_state == GM_X_WON) {
			for(int i = 0; i < 3; i++) {
				gtk_image_set_from_file(GTK_IMAGE(wgts->img[winning_blocks[i]]), "pics/X_win.png");
			}
			gtk_label_set_text(GTK_LABEL(wgts->lbl_status), "Крестики выиграли!");
		}

		else if(wgts->gm_state == GM_TIE) {
			gtk_label_set_text(GTK_LABEL(wgts->lbl_status), "Ничья");
		}

		wgts->turn = !wgts->turn;
	}
}

void on_btn_new_game_clicked(GtkButton *btn, app_widgets *wgts)
{
	for(int i= 0; i < 9; i++) {
		wgts->game_board[i] = 0;
		gtk_image_set_from_file(GTK_IMAGE(wgts->img[i]), "pics/blank.png");
	}

	gtk_label_set_text(GTK_LABEL(wgts->lbl_status), "Кликните на блок, чтобы сделать ход");

	wgts->gm_state = GM_BUSY;
}

void on_win_destroy()
{
	gtk_main_quit();
}