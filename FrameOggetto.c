#include <gtk/gtk.h>
#include <mariadb/mysql.h>
#include <libnotify/notify.h>

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
static int errore;
static NotifyNotification * d;
static char query[4096];
 
extern MYSQL *conn;

static void carica() {
	MYSQL_RES *res;
	MYSQL_ROW row;
	unsigned long lid;
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Oggetto non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
    }
	sprintf(query, "SELECT quantita, prezzo, sconto, minimo, vendita, iddipendente, idnegozio, idarticolo FROM Oggetti where idOggetto=%lu", lid);
	mysql_real_query(conn, query, strlen(query));
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	 if (row==NULL) {
               	d = notify_notification_new ("Errore", "L'articolo inserito non è stato trovato.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
       }
       gtk_entry_set_text(GTK_ENTRY(quantita), row[0]);
       gtk_entry_set_text(GTK_ENTRY(prezzo), row[1]);
       gtk_entry_set_text(GTK_ENTRY(sconto), row[2]);
       gtk_entry_set_text(GTK_ENTRY(minimo), row[3]);
       gtk_entry_set_text(GTK_ENTRY(vendita), row[4]);
       gtk_entry_set_text(GTK_ENTRY(idDipendente), row[5]);
       gtk_entry_set_text(GTK_ENTRY(idNegozio), row[6]);
       gtk_entry_set_text(GTK_ENTRY(idArticolo), row[7]);
       mysql_free_result(res);
}

static void aggiorna() {
    unsigned long lid=0L, liddipendente=0L, lidnegozio=0L, lidarticolo=0L, lquantita=0L, lsconto=0L, lminimo=0L, lvendita=0L;
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Oggetto non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
    }
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(idDipendente)),"%lu", &liddipendente) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Dipendente non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
   }
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(idNegozio)),"%lu", &lidnegozio) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Negozio non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
  }
  if (sscanf(gtk_entry_get_text(GTK_ENTRY(idArticolo)),"%lu", &lidarticolo) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Articolo non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(quantita)),"%lu", &lquantita) != 1) {
	d = notify_notification_new ("Errore", "Il campo quantità non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto) != 1) {
	d = notify_notification_new ("Errore", "Il campo sconto non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(minimo)),"%lu", &lminimo) != 1) {
	d = notify_notification_new ("Errore", "Il campo minimo vendibile non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(vendita)),"%lu", &lvendita) != 1) {
	d = notify_notification_new ("Errore", "Il campo in vendita non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }

 sprintf(query, "UPDATE Oggetti set quantita=%lu, prezzo='%s', sconto=%lu, minimo=%lu, vendita=%lu, iddipendente=%lu, idnegozio=%lu, idarticolo=%lu WHERE idOggetto=%lu;", lquantita,gtk_entry_get_text(GTK_ENTRY(prezzo)),lsconto,lminimo,lvendita,liddipendente, lidnegozio, lidarticolo, lid);
        mysql_real_query(conn, query, strlen(query));
           errore=mysql_errno(conn);
        if (errore==0)
               	d = notify_notification_new ("Esito positivo", "Operazione effettuata.", "dialog-information");
	else
               	d = notify_notification_new ("Esito negativo", mysql_error(conn), "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
}

static void salva() {
    unsigned long lid=0L, liddipendente=0L, lidnegozio=0L, lidarticolo=0L, lquantita=0L, lsconto=0L, lminimo=0L, lvendita=0L;
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Oggetto non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
    }
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(idDipendente)),"%lu", &liddipendente) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Dipendente non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
   }
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(idNegozio)),"%lu", &lidnegozio) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Negozio non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
  }
  if (sscanf(gtk_entry_get_text(GTK_ENTRY(idArticolo)),"%lu", &lidarticolo) != 1) {
	d = notify_notification_new ("Errore", "Il campo Id Articolo non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(quantita)),"%lu", &lquantita) != 1) {
	d = notify_notification_new ("Errore", "Il campo quantità non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto) != 1) {
	d = notify_notification_new ("Errore", "Il campo sconto non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(minimo)),"%lu", &lminimo) != 1) {
	d = notify_notification_new ("Errore", "Il campo minimo vendibile non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }
 if (sscanf(gtk_entry_get_text(GTK_ENTRY(vendita)),"%lu", &lvendita) != 1) {
	d = notify_notification_new ("Errore", "Il campo in vendita non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
                return;
 }

 sprintf(query, "INSERT INTO Oggetti(idOggetto, quantita, prezzo, sconto, minimo, vendita, iddipendente, idnegozio, idarticolo) VALUES(%lu,%lu,'%s',%lu,%lu,%lu,%lu,%lu,%lu);",lid, lquantita,gtk_entry_get_text(GTK_ENTRY(prezzo)),lsconto,lminimo,lvendita,liddipendente, lidnegozio, lidarticolo);
        mysql_real_query(conn, query, strlen(query));
           errore=mysql_errno(conn);
        if (errore==0)
		d = notify_notification_new ("Informazione", "L'inserimento è riuscito.", "dialog-information");
	else
		d = notify_notification_new ("Errore", mysql_error(conn), "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
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
    label=gtk_label_new("ID Dipendente: ");
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
    bottone=gtk_button_new_with_label("Salva");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salva), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);

    bottone=gtk_button_new_with_label("Carica");
    g_signal_connect(bottone, "clicked", G_CALLBACK(carica), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);


    bottone=gtk_button_new_with_label("Modifica");
    g_signal_connect(bottone, "clicked", G_CALLBACK(aggiorna), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    
    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);


    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestra, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestra));
}
