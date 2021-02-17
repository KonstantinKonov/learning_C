// Comment section
/*
Serial Port POSIX Systems
*/

// Headers
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <errno.h>
#include <fcntl.h>
#include "../lib/Serial.h"
#include <gtk/gtk.h>
#include <glib.h>
#include <math.h>
#include <slope/slope.h>

// Defines

#define MAX_STR 1000

// User defined types

typedef struct {
	GtkWidget *btn_show_option, *btn_connect, *cmbx_options, *lbl_sel_num, *lbl_sel_text, *txtview, *box_main;
	GtkTextBuffer *txt_buff;
} app_widgets;

// User defined variables
GtkWidget *view;
SlopeScale *scale;
SlopeFigure *figure;
SlopeItem *series;
double *x, *y;
const long n = 100;


//User defined function
gboolean timer_handler(app_widgets *wgts);
gboolean update_plot(gpointer data)
{
  long k;
  for (k = 0; k < n; ++k)
  {
    x[k] = g_random_double();
    y[k] = g_random_double();
  }
    
  slope_view_redraw(SLOPE_VIEW(view));

  return TRUE;
}


//Main 
int main(int argc, char **argv)
{   
    GtkBuilder	*builder;
	GtkWidget	*window;
	//GtkWidget *  box;
    //GtkWidget *  btn;

	app_widgets *widgets = g_slice_new(app_widgets);

	gtk_init(&argc, &argv);

	builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "glade/win.glade", NULL);

	window = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
	widgets->btn_show_option = GTK_WIDGET(gtk_builder_get_object(builder, "btn_show_option"));
	widgets->box_main = GTK_WIDGET(gtk_builder_get_object(builder, "box_main"));
	widgets->btn_connect = GTK_WIDGET(gtk_builder_get_object(builder, "btn_connect"));
	widgets->cmbx_options = GTK_WIDGET(gtk_builder_get_object(builder, "cmbx_options"));
	widgets->txtview = GTK_WIDGET(gtk_builder_get_object(builder, "txtview"));
	widgets->txt_buff = GTK_TEXT_BUFFER(gtk_builder_get_object(builder, "txt_buff"));
	widgets->lbl_sel_num = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_sel_num"));
	widgets->lbl_sel_text = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_sel_text"));
	//box = GTK_WIDGET(gtk_builder_get_object(builder, "box_graph"));
	//btn = GTK_WIDGET(gtk_builder_get_object(builder, "btn"));
	gtk_builder_connect_signals(builder, widgets);

	g_object_unref(builder);



	view   = slope_view_new();
  figure = slope_figure_new();

  //g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(update_plot), NULL);

  gtk_box_pack_start(GTK_BOX(widgets->box_main), view, FALSE, FALSE, 0);

  slope_view_set_figure(SLOPE_VIEW(view), figure);

  x = g_malloc(n * sizeof(double));
  y = g_malloc(n * sizeof(double));
  
  scale = slope_xyscale_new();
  slope_figure_add_scale(SLOPE_FIGURE(figure), scale);

  series = slope_xyseries_new_filled("", x, y, 10, "kor");
  slope_scale_add_item(scale, series);

  slope_xyscale_set_x_range(SLOPE_XYSCALE(scale), 0, 1);
  slope_xyscale_set_y_range(SLOPE_XYSCALE(scale), 0, 1);
    
  update_plot(NULL);


	g_slice_free(app_widgets, widgets);
  gtk_widget_show_all(window);
  gtk_main();

  g_free(x);
  g_free(y);

/*
    SerialInit();
    // simple noncanonical input
    
    char *buf = (char *)malloc(80 * sizeof(char));
    do{
        SerialRead(&buf);
                
    } while(1);
*/
    return 0;
}

gboolean timer_handler(app_widgets *wgts)
{
    gchar *buf = (gchar *)malloc(MAX_STR * sizeof(gchar));
	int received = 0;
    received = SerialRead(&buf);
	if(received > 0) {
		GtkTextIter iter;
		gtk_text_buffer_get_end_iter(wgts->txt_buff, &iter);
		gtk_text_buffer_insert(wgts->txt_buff, &iter, buf, received);
	}
	g_free(buf);

	return TRUE;
}

void on_btn_show_option_clicked(GtkButton *btn, app_widgets* wgts)
{
    
    char **serial_list;
    int number_of_ports = 0;
    number_of_ports = SerialGetList(&serial_list);
	SerialPrintList(number_of_ports, &serial_list, stdout);

	if(!number_of_ports)
		return;

	gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(wgts->cmbx_options));
    for(int i = 0; i < number_of_ports; i++) {
        printf("serial ports: %s\n", serial_list[i]);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(wgts->cmbx_options), NULL, serial_list[i]);
    }

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

void on_btn_connect_clicked(GtkButton *btn, app_widgets* wgts)
{
	char portname[PORTNAME_MAX_LENGTH];
    char **serial_list;
    int access_points_num = 0;

	gchar *item_text = malloc(MAX_STR); // should I allocate memory here?
	item_text = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(wgts->cmbx_options));
	if(item_text == NULL)
	{
		return;
	}

    access_points_num = SerialGetList(&serial_list);
    //SerialPrintList(access_points_num, &serial_list, stdout);
    //SerialChoose(access_points_num, &serial_list, portname);
    int fd = SerialOpen(item_text);
    SerialSetAttribs(fd, B19200);
    SerialSetMinCount(fd, 80);
	
	g_timeout_add(100, (GSourceFunc)timer_handler, wgts);
    // simple noncanonical input
    

	g_free(item_text);
}

void on_win_destroy()
{
	SerialClose();
	gtk_main_quit();
}