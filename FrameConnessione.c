#include <gtk/gtk.h>

void connetti() {
    GtkDialog *d=gtk_message_dialog_new(NULL, GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Ciao mondo");
    gtk_dialog_run(d);
    gtk_widget_destroy(d);
}


void creaFrameConnessione() {
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  GtkWidget *textbox=NULL;
  GtkEntry *password=NULL;
  GtkWidget *vbox = NULL;
  GtkWidget *hbox= NULL;
  GtkWidget *label=NULL;
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "Frame Connessione");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", gtk_main_quit, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_vbox_new (TRUE, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  hbox=gtk_hbox_new(TRUE, 6);
  label=gtk_label_new("User name :");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  textbox=gtk_text_view_new();
  gtk_box_pack_start(GTK_BOX(hbox), textbox, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);
  hbox=gtk_hbox_new(TRUE, 6);
  label=gtk_label_new("Password :");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  password=gtk_entry_new();
  gtk_entry_set_visibility(password, FALSE);
  gtk_box_pack_start(GTK_BOX(hbox), password, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

  button=gtk_button_new();
  gtk_button_set_label(button, "Ok");
  g_signal_connect (button, "clicked", connetti, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button=gtk_button_new();
  gtk_button_set_label(button, "Annulla");
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  gtk_window_set_modal(win, TRUE);
  gtk_widget_show_all(win);
  }


