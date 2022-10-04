#include <gtk/gtk.h>
#include <mariadb/mysql.h>

static GtkWindow *finestra=NULL;
static GtkWidget *id=NULL;
static GtkWidget *idDipendente=NULL;
static GtkWidget *idNegozio=NULL;
static GtkWidget *idArticolo=NULL;
static GtkWidget *quantita=NULL;
static GtkWidget *sconto=NULL;
static GtkWidget *minimo=NULL;
static GtkWidget *prezzo=NULL;
static GtkWidget *vendita=NULL;
static char query[4096];
 
extern MYSQL *conn;

static void salva() {
    unsigned long lid=0L, liddipendente=0L, lidnegozio=0L, lidarticolo=0L, lquantita=0L, lsconto=0L, lminimo=0L, lvendita=0L;
    GtkWidget *d=NULL;
    if (gtk_entry_get_text_length(GTK_ENTRY(prezzo))>0) {
        if (gtk_entry_get_text_length(GTK_ENTRY(id))>0) {
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Collana non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(idDipendente))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idDipendente)),"%lu", &liddipendente) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Dipendente non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(idNegozio))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idNegozio)),"%lu", &lidnegozio) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Negozio non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

        if (gtk_entry_get_text_length(GTK_ENTRY(idArticolo))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idArticolo)),"%lu", &lidarticolo) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

        if (gtk_entry_get_text_length(GTK_ENTRY(quantita))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(quantita)),"%lu", &lquantita) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Quantita non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(sconto))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo sconto non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(minimo))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(minimo)),"%lu", &lminimo) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo minimo non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(vendita))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(vendita)),"%lu", &lvendita) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo vendita non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

 	sprintf(query, "INSERT INTO Oggetti(idOggetto, quantita, prezzo, sconto, minimo, vendita, iddipendente, idnegozio, idarticolo) VALUES(%lu,%lu,\"%s\",%lu,%lu,%lu,%lu,%lu,%lu);",lid, lquantita,gtk_entry_get_text(GTK_ENTRY(prezzo)),lsconto,lminimo,lvendita,liddipendente, lidnegozio, lidarticolo);
        mysql_real_query(conn, query, strlen(query));
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query  ha dato numero di uscita %u", mysql_errno(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else {
    	d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo prezzo non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    }
}
}

void creaFrameOggetto() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento Oggetto");
    gtk_window_set_position(GTK_WINDOW(finestra), GTK_WIN_POS_CENTER);
    gtk_widget_realize(GTK_WIDGET(finestra));
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestra), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Oggetto: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    id=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), id, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Quantità: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    quantita=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), quantita, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Sconto: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    sconto=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), sconto, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Minimo vendibile: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    minimo=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), minimo, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Prezzo: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    prezzo=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), prezzo, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("In Vendita: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    vendita=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), vendita, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Dipedente: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idDipendente=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idDipendente, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Negozio: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Articolo: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idArticolo=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idArticolo, TRUE, TRUE, 0);
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