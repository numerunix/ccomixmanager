#include <gtk/gtk.h>
#include <mariadb/mysql.h>

GtkWidget *win = NULL;
GtkWidget *textbox=NULL;
GtkWidget *password=NULL;
GtkWidget *ip=NULL;

extern MYSQL *conn;

void connetti() {
    GtkWidget *d;
    if (gtk_entry_get_text_length(GTK_ENTRY(textbox))>0 && gtk_entry_get_text_length(GTK_ENTRY(password))>0 && gtk_entry_get_text_length(GTK_ENTRY(ip))>0) {
        conn=mysql_init(NULL);
        if (conn==NULL) {
            d=gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Impossibile effettuare l'init del database");
            gtk_dialog_run(GTK_DIALOG(d));
            gtk_widget_destroy(d);
        }
        else {
            if ( (mysql_real_connect(conn,gtk_entry_get_text(GTK_ENTRY(ip)),gtk_entry_get_text(GTK_ENTRY(textbox)),gtk_entry_get_text(GTK_ENTRY(password)),"",0,NULL,0))== NULL) {
                d=gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Impossibile effettuare la connnessione");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
            }
            else {
                mysql_select_db(conn, "ComixManager");
                d=gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Connessione effettuata");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                gtk_window_close(GTK_WINDOW(win));
            }
        }

    } else {
        if (gtk_entry_get_text_length(GTK_ENTRY(textbox))==0) {
            d=gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo user name non può essere NULL");
            gtk_dialog_run(GTK_DIALOG(d));
            gtk_widget_destroy(d);
        } else if (gtk_entry_get_text_length(GTK_ENTRY(ip))==0){
            d=gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo IP del server non può essere NULL");
            gtk_dialog_run(GTK_DIALOG(d));
            gtk_widget_destroy(d);
        } else {
            d=gtk_message_dialog_new(GTK_WINDOW(win), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo password non può essere NULL");
            gtk_dialog_run(GTK_DIALOG(d));
            gtk_widget_destroy(d);
        }
    }
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
  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  label=gtk_label_new("IP del server: ");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0)  ;
  ip=gtk_entry_new();
  gtk_entry_set_text(ip, "127.0.0.1");
  gtk_box_pack_start(GTK_BOX(hbox), ip, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);
  hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  label=gtk_label_new("User name :");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  textbox=gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox), textbox, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);
  hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  label=gtk_label_new("Password :");
  gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, TRUE, 0);
  password=gtk_entry_new();
  gtk_entry_set_visibility(GTK_ENTRY(password), FALSE);
  gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(password), TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vbox), hbox, TRUE, TRUE, 0);

  button=gtk_button_new_with_label("Ok");
  g_signal_connect (button, "clicked", connetti, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button=gtk_button_new_with_label("Annulla");
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  gtk_window_set_modal(GTK_WINDOW(win), TRUE);
  gtk_widget_show_all(win);
  }


