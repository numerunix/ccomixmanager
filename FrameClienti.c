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


static void salva() {
    unsigned long lid=0L, lsconto=0L;
    GtkWidget *d=NULL;
    if (gtk_entry_get_text_length(GTK_ENTRY(nome))>0 && gtk_entry_get_text_length(GTK_ENTRY(indirizzo))>0 && gtk_entry_get_text_length(GTK_ENTRY(citta))>0 && gtk_entry_get_text_length(GTK_ENTRY(provincia))>0 && gtk_entry_get_text_length(GTK_ENTRY(telefono))>0 &&
    gtk_entry_get_text_length(GTK_ENTRY(cognome))>0 &&
    gtk_entry_get_text_length(GTK_ENTRY(datanascita))>0 &&
    gtk_entry_get_text_length(GTK_ENTRY(cap))>0 )  {
        if (gtk_entry_get_text_length(GTK_ENTRY(id))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Cliente non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
         if (gtk_entry_get_text_length(GTK_ENTRY(sconto))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Sconto non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

    sprintf(query, "INSERT INTO Clienti (idCliente, nome, cognome, indirizzo, datanascita, cap, citta, provincia, telefono, fax, email, sitoweb, note, sconto) VALUES(%lu, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", %lu);",lid, gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(cognome)), gtk_entry_get_text(GTK_ENTRY(indirizzo)), gtk_entry_get_text(GTK_ENTRY(datanascita)), gtk_entry_get_text(GTK_ENTRY(cap)), gtk_entry_get_text(GTK_ENTRY(citta)), gtk_entry_get_text(GTK_ENTRY(provincia)), gtk_entry_get_text(GTK_ENTRY(telefono)), gtk_entry_get_text(GTK_ENTRY(fax)), gtk_entry_get_text(GTK_ENTRY(email)), gtk_entry_get_text(GTK_ENTRY(sitoWeb)), gtk_entry_get_text(GTK_ENTRY(note)), lsconto);
    mysql_real_query(conn, query, strlen(query));
    d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query ha dato numero di uscita %u", mysql_errno(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else if (gtk_entry_get_text_length(GTK_ENTRY(nome))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo nome non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(indirizzo))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo indirizzo non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(citta))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Città non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(provincia))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo provincia non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

   } else if (gtk_entry_get_text_length(GTK_ENTRY(telefono))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo telefono non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(cognome))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo cognome non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

} else if (gtk_entry_get_text_length(GTK_ENTRY(datanascita))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Data di Nascita non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else {
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo CAP non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    }
}

void creaFrameClienti() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento CLiente");
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
    bottone=gtk_button_new_with_label("Ok");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salva), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestra, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestra));
}
