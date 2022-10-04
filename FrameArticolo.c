#include <gtk/gtk.h>
#include <mariadb/mysql.h>

static GtkWindow *finestra=NULL;
static GtkWidget *id=NULL;
static GtkWidget *descrizione=NULL;
static GtkWidget *codiceABarre=NULL;
static GtkWidget *iva=NULL;
static GtkWidget *note=NULL;
static GtkWidget *idEditore=NULL;
static GtkWidget *idCollana=NULL;
static GtkWidget *idCategoria=NULL;
static GtkWidget *idFornitore=NULL;
static GtkWidget *numero=NULL;
static GtkWidget *dataPubblicazione=NULL;
static char query[4096];
 
extern MYSQL *conn;

static void carica() {
	MYSQL_RES * res=NULL;
	MYSQL_ROW row=NULL;
	unsigned long lid=0L;
	GtkWidget *d=NULL;
        if (gtk_entry_get_text_length(GTK_ENTRY(id))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Collana non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
       sprintf(query, "SELECT descrizione, codiceabarre, iva, note, numero, datapubblicazione, idcollana, idcategoria, ideditore, idfornitore FROM Articoli WHERE idArticolo=\"%lu\";",lid);
       mysql_real_query(conn, query, strlen(query));
       res=mysql_store_result(conn);
       row=mysql_fetch_row(res);
       gtk_entry_set_text(GTK_ENTRY(descrizione), row[0]);
       gtk_entry_set_text(GTK_ENTRY(codiceABarre), row[1]);
       gtk_entry_set_text(GTK_ENTRY(iva), row[2]);
       gtk_entry_set_text(GTK_ENTRY(note), row[3]);
       gtk_entry_set_text(GTK_ENTRY(numero), row[4]);
       gtk_entry_set_text(GTK_ENTRY(dataPubblicazione), row[5]);
       gtk_entry_set_text(GTK_ENTRY(idCollana), row[6]);
       gtk_entry_set_text(GTK_ENTRY(idCategoria), row[7]);
       gtk_entry_set_text(GTK_ENTRY(idEditore), row[8]);
       gtk_entry_set_text(GTK_ENTRY(idFornitore), row[9]);
       mysql_free_result(res);
}

static void edita() {
GtkWidget *d=NULL;
unsigned long lid=0L, lidcollana=0L, lidcategoria=0L, lideditore=0L, lidfornitore=0L, liva=0L, lnumero=0L;
        sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid);
        sscanf(gtk_entry_get_text(GTK_ENTRY(idCollana)),"%lu", &lidcollana);
        sscanf(gtk_entry_get_text(GTK_ENTRY(idCategoria)),"%lu", &lidcategoria);
        sscanf(gtk_entry_get_text(GTK_ENTRY(idEditore)),"%lu", &lideditore);
        sscanf(gtk_entry_get_text(GTK_ENTRY(idFornitore)),"%lu", &lidfornitore);
        sscanf(gtk_entry_get_text(GTK_ENTRY(iva)),"%lu", &liva);
        sscanf(gtk_entry_get_text(GTK_ENTRY(numero)),"%lu", &lnumero);
        
 	sprintf(query, "UPDATE Articoli set descrizione=\"%s\", codiceabarre=\"%s\", iva=%lu, numero=%lu, datapubblicazione=\"%s\", note=\"%s\", idcollana=%lu, idcategoria=%lu, ideditore=%lu, idfornitore=%lu WHERE idArticolo=%lu;",gtk_entry_get_text(GTK_ENTRY(descrizione)),gtk_entry_get_text(GTK_ENTRY(codiceABarre)),
liva, lnumero, gtk_entry_get_text(GTK_ENTRY(dataPubblicazione)),gtk_entry_get_text(GTK_ENTRY(note)), lidcollana, lidcategoria, lideditore, lidfornitore, lid);
        mysql_real_query(conn, query, strlen(query));
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query %s ha dato numero di uscita %u", query, mysql_errno(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

}

static void salva() {
    unsigned long lid=0L, lidcollana=0L, lidcategoria=0L, lideditore=0L, lidfornitore=0L, liva=0L, lnumero=0L;
    GtkWidget *d=NULL;
    if (gtk_entry_get_text_length(GTK_ENTRY(descrizione))>0 &&
    gtk_entry_get_text_length(GTK_ENTRY(codiceABarre))>0 &&
    gtk_entry_get_text_length(GTK_ENTRY(dataPubblicazione))>0)  {
        if (gtk_entry_get_text_length(GTK_ENTRY(id))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Collana non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(idCollana))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idCollana)),"%lu", &lidcollana) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Collana non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(idCategoria))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idCategoria)),"%lu", &lidcategoria) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Categoria non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

        if (gtk_entry_get_text_length(GTK_ENTRY(idEditore))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idEditore)),"%lu", &lideditore) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

        if (gtk_entry_get_text_length(GTK_ENTRY(idFornitore))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idFornitore)),"%lu", &lidfornitore) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Fornitore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(iva))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(iva)),"%lu", &liva) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo iva non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        if (gtk_entry_get_text_length(GTK_ENTRY(numero))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(numero)),"%lu", &lnumero) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo numero non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
 	sprintf(query, "INSERT INTO Articoli(idArticolo, descrizione, codiceabarre, iva, numero, datapubblicazione, note, idcollana, idcategoria, ideditore, idfornitore) VALUES(%lu, \"%s\",\"%s\",\"%s\",\"%lu\",\"%s\", \"%s\", \"%lu\", \"%lu\", \"%lu\", \"%lu\");",lid, gtk_entry_get_text(GTK_ENTRY(descrizione)),gtk_entry_get_text(GTK_ENTRY(codiceABarre)),
gtk_entry_get_text(GTK_ENTRY(iva)), lnumero, gtk_entry_get_text(GTK_ENTRY(dataPubblicazione)),gtk_entry_get_text(GTK_ENTRY(note)), lidcollana, lidcategoria, lideditore, lidfornitore);
        mysql_real_query(conn, query, strlen(query));
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query ha dato numero di uscita %u", mysql_errno(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
   } else if (gtk_entry_get_text_length(GTK_ENTRY(descrizione))==0) {
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Descrizione non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else if (gtk_entry_get_text_length(GTK_ENTRY(codiceABarre))==0) {
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Codice A Barre non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else {
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo Data Pubblicazione non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    }
}

void creaFrameArticolo() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento Articolo");
    gtk_window_set_position(GTK_WINDOW(finestra), GTK_WIN_POS_CENTER);
    gtk_widget_realize(GTK_WIDGET(finestra));
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestra), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Articolo: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    id=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), id, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Descrizione: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    descrizione=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), descrizione, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Codice a Barre: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    codiceABarre=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), codiceABarre, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Iva: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    iva=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), iva, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Numero: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    numero=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), numero, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Data Pubblicazione (aaaa-mm-gg): ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    dataPubblicazione=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), dataPubblicazione, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Note: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    note=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), note, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Collana: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idCollana=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idCollana, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);


    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Categoria: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idCategoria=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idCategoria, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Editore: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idEditore=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idEditore, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    
    
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Fornitore: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idFornitore=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idFornitore, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    bottone=gtk_button_new_with_label("Ok");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salva), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    bottone=gtk_button_new_with_label("Carica dati");
    g_signal_connect(bottone, "clicked", G_CALLBACK(carica), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);    
    bottone=gtk_button_new_with_label("Modifica dati");
    g_signal_connect(bottone, "clicked", G_CALLBACK(edita), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);    
    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestra, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestra));
}
