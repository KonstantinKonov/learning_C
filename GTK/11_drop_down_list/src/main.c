#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <gtk/gtk.h>
#include <glib.h>

#define MAX_STR 1000

typedef struct {
	GtkWidget *btn_show_option, *cmbx_options, *lbl_sel_num, *lbl_sel_text;
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
	widgets->btn_show_option = GTK_WIDGET(gtk_builder_get_object(builder, "btn_show_option"));
	widgets->cmbx_options = GTK_WIDGET(gtk_builder_get_object(builder, "cmbx_options"));
	widgets->lbl_sel_num = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_sel_num"));
	widgets->lbl_sel_text = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_sel_text"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);

	gtk_widget_show(window);
	gtk_main();

	g_slice_free(app_widgets, widgets);

	return 0;
}

void on_btn_show_option_clicked(GtkButton *btn, app_widgets* wgts)
{
	gint item_num = 0;
	gchar *item_text = malloc(MAX_STR); // should I allocate memory here?
	//GString *gstr_sel_text = g_string_new("");

	item_num = gtk_combo_box_get_active(GTK_COMBO_BOX(wgts->cmbx_options));

	//g_string_printf(gstr_sel_text,  "Item: %d", item_num);
	//gtk_label_set_text(GTK_LABEL(wgts->lbl_sel_num), gstr_sel_text->str);

	g_snprintf(item_text, 256, "%d", item_num);
	gtk_label_set_text(GTK_LABEL(wgts->lbl_sel_num), item_text);
	
	item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(wgts->cmbx_options));
	if(item_text == NULL)
	{
		return;
	}
	gtk_label_set_text(GTK_LABEL(wgts->lbl_sel_text), item_text);
	g_free(item_text);
}

void on_win_destroy()
{
	gtk_main_quit();
}