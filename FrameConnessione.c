#include <gtk/gtk.h>
#include <mariadb/mysql.h>

GtkWidget *win = NULL;
GtkWidget *textbox=NULL;
GtkEntry *password=NULL;


void connetti() {
    gchar *user=gtk_entry_get_text(textbox), *passwd=gtk_entry_get_text(password);
    MYSQL *conn=NULL;
    if (strlen(user)>0 && strlen(passwd)>0) {
        conn=mysql_init(NULL);
        if (conn==NULL) {
            GtkDialog *d=gtk_message_dialog_new(win, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Impossibile effettuare l'init del database");
            gtk_dialog_run(d);
            gtk_widget_destroy(d);
        }
        else {
            if ( (mysql_real_connect(conn,"127.0.0.1",user,passwd,"",0,NULL,0))== NULL) {
                GtkDialog *d=gtk_message_dialog_new(win, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Impossibile effettuare la connnessione");
                gtk_dialog_run(d);
                gtk_widget_destroy(d);
            }
            else {
                GtkDialog *d=gtk_message_dialog_new(win, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Connessione effettuata");
                gtk_dialog_run(d);
                gtk_widget_destroy(d);
                    gtk_window_close(win);
            }
        }

    } else {
        if (strlen(user)==0) {
            GtkDialog *d=gtk_message_dialog_new(win, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo user name non può essere NULL");
            gtk_dialog_run(d);
            gtk_widget_destroy(d);
        } else {
            GtkDialog *d=gtk_message_dialog_new(win, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo password non può essere NULL");
            gtk_dialog_run(d);
            gtk_widget_destroy(d);
        }
    }

 /*   if (g_list_length(l)==0) {
        GtkDialog *d=gtk_message_dialog_new(win, GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo password non può essere null");
        gtk_dialog_run(d);
        gtk_widget_destroy(d);
        return;
    } else {
        b==gtk_text_view_get_buffer(textbox);
        gtk_text_buffer_get_bounds(b, inizio, fine);
        pwd=gtk_text_buffer_get_text(b, inizio, fine, TRUE);
    }*/
}


void creaFrameConnessione() {
  GtkWidget *button = NULL;
  GtkWidget *vbox = NULL;
  GtkWidget *hbox= NULL;
  GtkWidget *label=NULL;
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "Frame Connessione");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  vbox = gtk_vbox_new (TRUE, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  hbox=gtk_hbox_new(TRUE, 6);
  label=gtk_label_new("User name :");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  textbox=gtk_entry_new();
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


