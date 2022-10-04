#include <gtk/gtk.h>
#include <mariadb/mysql.h>

static GtkWindow *finestra=NULL;
static GtkWidget *id=NULL;
static GtkWidget *nome=NULL;
static GtkWidget *indirizzo=NULL;
static GtkWidget *citta=NULL;
static GtkWidget *provincia=NULL;
static GtkWidget *email=NULL;
static GtkWidget *sitoWeb=NULL;
static GtkWidget *note=NULL;
static GtkWidget *telefono=NULL;
static GtkWidget *fax=NULL;
static GtkWidget *cognome=NULL;
static GtkWidget *datanascita=NULL;
static GtkWidget *cap=NULL;
static GtkWidget *sconto=NULL;
static char query[4096];
extern MYSQL *conn;
static int errore;
static GtkWidget *d=NULL;


static void modifica() {

	unsigned long lid, lsconto;
	sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid);
	sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto);

 sprintf(query, "UPDATE Clienti set nome='%s', cognome='%s', indirizzo='%s', datanascita='%s', cap='%s', citta='%s', provincia='%s', telefono='%s', fax='%s', email='%s', sitoweb='%s',note='%s',sconto=%lu WHERE idCliente=%lu;", gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(cognome)), gtk_entry_get_text(GTK_ENTRY(indirizzo)), gtk_entry_get_text(GTK_ENTRY(datanascita)), gtk_entry_get_text(GTK_ENTRY(cap)), gtk_entry_get_text(GTK_ENTRY(citta)), gtk_entry_get_text(GTK_ENTRY(provincia)), gtk_entry_get_text(GTK_ENTRY(telefono)), gtk_entry_get_text(GTK_ENTRY(fax)), gtk_entry_get_text(GTK_ENTRY(email)), gtk_entry_get_text(GTK_ENTRY(sitoWeb)), gtk_entry_get_text(GTK_ENTRY(note)), lsconto,lid);
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
	sprintf(query, "SELECT nome, cognome, indirizzo, datanascita, cap, citta, provincia, telefono, fax, email, sitoweb, note, sconto FROM Clienti where idCliente=%lu", lid);
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
       gtk_entry_set_text(GTK_ENTRY(indirizzo), row[2]);
       gtk_entry_set_text(GTK_ENTRY(datanascita), row[3]);
       gtk_entry_set_text(GTK_ENTRY(cap), row[4]);
       gtk_entry_set_text(GTK_ENTRY(citta), row[5]);
       gtk_entry_set_text(GTK_ENTRY(provincia), row[6]);
       gtk_entry_set_text(GTK_ENTRY(telefono), row[7]);
       gtk_entry_set_text(GTK_ENTRY(fax), row[8]);
       gtk_entry_set_text(GTK_ENTRY(email), row[9]);
       gtk_entry_set_text(GTK_ENTRY(sitoWeb), row[10]);
       gtk_entry_set_text(GTK_ENTRY(note), row[11]);
       gtk_entry_set_text(GTK_ENTRY(sconto), row[12]);
       mysql_free_result(res);
}



static void salva() {
    unsigned long lid=0L, lsconto=0L;
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Cliente non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
   }
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Sconto non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
  }

    sprintf(query, "INSERT INTO Clienti (idCliente, nome, cognome, indirizzo, datanascita, cap, citta, provincia, telefono, fax, email, sitoweb, note, sconto) VALUES(%lu, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', %lu);",lid, gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(cognome)), gtk_entry_get_text(GTK_ENTRY(indirizzo)), gtk_entry_get_text(GTK_ENTRY(datanascita)), gtk_entry_get_text(GTK_ENTRY(cap)), gtk_entry_get_text(GTK_ENTRY(citta)), gtk_entry_get_text(GTK_ENTRY(provincia)), gtk_entry_get_text(GTK_ENTRY(telefono)), gtk_entry_get_text(GTK_ENTRY(fax)), gtk_entry_get_text(GTK_ENTRY(email)), gtk_entry_get_text(GTK_ENTRY(sitoWeb)), gtk_entry_get_text(GTK_ENTRY(note)), lsconto);
    mysql_real_query(conn, query, strlen(query));
    errore=mysql_errno(conn);
    if (errore==0)
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Operazione effettuata");
    else
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Errore %d: %s", errore, mysql_error(conn));
    gtk_dialog_run(GTK_DIALOG(d));
    gtk_widget_destroy(d);
}


void creaFrameClienti() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento Cliente");
    gtk_window_set_position(GTK_WINDOW(finestra), GTK_WIN_POS_CENTER);
    gtk_widget_realize(GTK_WIDGET(finestra));
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestra), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Cliente: ");
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
    label=gtk_label_new("Indirizzo: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    indirizzo=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), indirizzo, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Data di Nascita (aaaa-mm-dd): ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    datanascita=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), datanascita, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("CAP: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    cap=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), cap, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Città: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    citta=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), citta, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Provincia: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    provincia=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), provincia, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("E-mail: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    email=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), email, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Sito Web: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    sitoWeb=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), sitoWeb, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Telefono: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    telefono=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), telefono, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Fax: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    fax=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), fax, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Note: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    note=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), note, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Sconto: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    sconto=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), sconto, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    bottone=gtk_button_new_with_label("Salva");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salva), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);

    bottone=gtk_button_new_with_label("Carica");
    g_signal_connect(bottone, "clicked", G_CALLBACK(carica), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);

    bottone=gtk_button_new_with_label("Modifica");
    g_signal_connect(bottone, "clicked", G_CALLBACK(modifica), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);

    
    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestra, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestra));
}

