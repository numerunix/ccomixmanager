#include <gtk/gtk.h>
#include <mariadb/mysql.h>

static GtkWindow *finestra=NULL;
static GtkWidget *id=NULL;
static GtkWidget *nome=NULL;
static GtkWidget *cognome=NULL;
static GtkWidget *cellulare=NULL;
static GtkWidget *idNegozio=NULL;
static char query[4096];
static int errore;
static GtkWidget *d=NULL;
 
extern MYSQL *conn;

static void modifica() {

	unsigned long lid, lidnegozio;
	sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid);
	sscanf(gtk_entry_get_text(GTK_ENTRY(idNegozio)),"%lu", &lidnegozio);

 sprintf(query, "UPDATE Dipendenti SET nome='%s', cognome='%s', cellulare='%s', idnegozio=%lu WHERE idDipendente=%lu;", gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(cognome)), gtk_entry_get_text(GTK_ENTRY(cellulare)), lidnegozio,lid);
        mysql_real_query(conn, query, strlen(query));
           errore=mysql_errno(conn);
        if (errore==0)
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Operazione effettuata");
	else
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Errore %d: %s", errore, mysql_error(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
}


static void carica() {
	MYSQL_RES *res;
	MYSQL_ROW row;
	unsigned long lid;
	sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid);
	sprintf(query, "SELECT nome, cognome, cellulare, idNegozio FROM Dipendenti where idDipendente=%lu", lid);
	mysql_real_query(conn, query, strlen(query));
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	 if (row==NULL) {
               d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "IL cliente inserito non è stato trovato.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
       }
       gtk_entry_set_text(GTK_ENTRY(nome), row[0]);
       gtk_entry_set_text(GTK_ENTRY(cognome), row[1]);
       gtk_entry_set_text(GTK_ENTRY(cellulare), row[2]);
       gtk_entry_set_text(GTK_ENTRY(idNegozio), row[3]);
       mysql_free_result(res);
}


static void salva() {
    unsigned long lid=0L, lidnegozio=0L;
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Dipendente non è intero.");
           gtk_dialog_run(GTK_DIALOG(d));
           gtk_widget_destroy(d);
           return;
   }
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lidnegozio) != 1) {
	  d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Negozio non è intero.");
          gtk_dialog_run(GTK_DIALOG(d));
          gtk_widget_destroy(d);
          return;
  }

 	sprintf(query, "INSERT INTO Dipendenti(idDipendente, nome, cognome, cellulare, idNegozio) VALUES(%lu, '%s', '%s','%s', %lu);",lid, gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(cognome)), gtk_entry_get_text(GTK_ENTRY(cellulare)), lidnegozio);
        mysql_real_query(conn, query, strlen(query));
        errore=mysql_errno(conn);
        if (errore==0)
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Operazione effettuata");
	else
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Errore %d: %s", errore, mysql_error(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
}

void creaFrameDipendente() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento Dipendente");
    gtk_window_set_position(GTK_WINDOW(finestra), GTK_WIN_POS_CENTER);
    gtk_widget_realize(GTK_WIDGET(finestra));
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestra), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Dipendente: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    id=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), id, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Nome: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    nome=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), nome, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Cognome: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    cognome=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), cognome, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Cellulare: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    cellulare=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), cellulare, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Negozio: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    bottone=gtk_button_new_with_label("Salva");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salva), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);

    bottone=gtk_button_new_with_label("Carica");
    g_signal_connect(bottone, "clicked", G_CALLBACK(carica), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);

    bottone=gtk_button_new_with_label("Modifca");
    g_signal_connect(bottone, "clicked", G_CALLBACK(modifica), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);



    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestra, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestra));
}
