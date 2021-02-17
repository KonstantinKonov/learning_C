/*
 * Copyright (C) 2016  Elvis Teixeira
 *
 * This source code is free software: you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General
 * Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any
 * later version.
 *
 * This source code is distributed in the hope that it will be
 * useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU Lesser General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Lesser General
 * Public License along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>
#include <math.h>
#include <slope/slope.h>

/* globals. yes, good or not, it is a demo */
const long n = 100;
double *   x, *y;
GtkWidget *view;

SlopeFigure *figure;
SlopeScale * scale;
SlopeItem *  series;

gboolean update_plot(GtkWidget *button, gpointer data)
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

int main(int argc, char *argv[])
{
  GtkBuilder    *builder;
  GtkWidget *  win;
  GtkWidget *  box;
  GtkWidget *  btn;

  

  gtk_init(&argc, &argv);

  builder = gtk_builder_new();
  gtk_builder_add_from_file (builder, "glade/test.glade", NULL);

  win = GTK_WIDGET(gtk_builder_get_object(builder, "win"));
  box = GTK_WIDGET(gtk_builder_get_object(builder, "box"));
  btn = GTK_WIDGET(gtk_builder_get_object(builder, "btn"));

  gtk_builder_connect_signals(builder, NULL);

  g_object_unref(builder);

  view   = slope_view_new();
  figure = slope_figure_new();

  g_signal_connect(G_OBJECT(btn), "clicked", G_CALLBACK(update_plot), NULL);

  gtk_box_pack_end(GTK_BOX(box), view, FALSE, FALSE, 0);

  slope_view_set_figure(SLOPE_VIEW(view), figure);

  x = g_malloc(n * sizeof(double));
  y = g_malloc(n * sizeof(double));
  


  scale = slope_xyscale_new();
  slope_figure_add_scale(SLOPE_FIGURE(figure), scale);

  series = slope_xyseries_new_filled("", x, y, 10, "kor");
  slope_scale_add_item(scale, series);

  slope_xyscale_set_x_range(SLOPE_XYSCALE(scale), 0, 1);
  slope_xyscale_set_y_range(SLOPE_XYSCALE(scale), 0, 1);
    
  update_plot(btn, NULL);

  gtk_widget_show_all(win);
  gtk_main();

  g_free(x);
  g_free(y);

  return 0;
}

void on_win_destroy()
{
    gtk_main_quit();
}