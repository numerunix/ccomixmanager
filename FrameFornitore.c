#include <gtk/gtk.h>
#include <mariadb/mysql.h>
#include <libnotify/notify.h>

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
static char query[4096];
static int errore;
static NotifyNotification * d;
extern MYSQL *conn;

static void carica() {
	MYSQL_RES *res;
	MYSQL_ROW row;
	unsigned long lid;
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
               d = notify_notification_new ("Errore", "Il campo Id Fornitore non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
            return;
   }
	sprintf(query, "SELECT nome, indirizzo, citta, provincia, email, sitoweb, note, telefono, fax FROM Fornitori where idFornitore=%lu", lid);
	mysql_real_query(conn, query, strlen(query));
	res=mysql_store_result(conn);
	row=mysql_fetch_row(res);
	 if (row==NULL) {
            	d = notify_notification_new ("Errore", "L'articolo inserito non è stato trovato.", "dialog-error");
		notify_notification_show (d, NULL);
		g_object_unref(G_OBJECT(d));
                return;
       }
       gtk_entry_set_text(GTK_ENTRY(nome), row[0]);
       gtk_entry_set_text(GTK_ENTRY(indirizzo), row[1]);
       gtk_entry_set_text(GTK_ENTRY(citta), row[2]);
       gtk_entry_set_text(GTK_ENTRY(provincia), row[3]);
       gtk_entry_set_text(GTK_ENTRY(email), row[4]);
       gtk_entry_set_text(GTK_ENTRY(sitoWeb), row[5]);
       gtk_entry_set_text(GTK_ENTRY(note), row[6]);
       gtk_entry_set_text(GTK_ENTRY(telefono), row[7]);
       gtk_entry_set_text(GTK_ENTRY(fax), row[8]);
       mysql_free_result(res);
}


static void salva() {
    unsigned long lid=0L;
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
               d = notify_notification_new ("Errore", "Il campo Id Fornitore non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
            return;
   }
    sprintf(query, "INSERT INTO Fornitori (idFornitore, nome, indirizzo, citta, provincia, email, sitoweb, note, telefono, fax) VALUES(%lu, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s');",lid, gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(indirizzo)), gtk_entry_get_text(GTK_ENTRY(citta)), gtk_entry_get_text(GTK_ENTRY(provincia)), gtk_entry_get_text(GTK_ENTRY(email)), gtk_entry_get_text(GTK_ENTRY(sitoWeb)), gtk_entry_get_text(GTK_ENTRY(note)), gtk_entry_get_text(GTK_ENTRY(telefono)), gtk_entry_get_text(GTK_ENTRY(fax)));
    mysql_real_query(conn, query, strlen(query));
        errore=mysql_errno(conn);
        if (errore==0)
         d = notify_notification_new ("Informazione", "L'inserimento è riuscito.", "dialog-information");
	else
		d = notify_notification_new ("Errore", mysql_error(conn), "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));;
}

static void modifica() {
   unsigned long lid=0L;
   if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
               d = notify_notification_new ("Errore", "Il campo Id Fornitore non è intero.", "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));
            return;
   }
    sprintf(query, "UPDATE Fornitori SET nome='%s', indirizzo='%s', citta='%s', provincia='%s', email='%s', sitoweb='%s', note='%s', telefono='%s', fax='%s' WHERE idFornitore=%lu;", gtk_entry_get_text(GTK_ENTRY(nome)), gtk_entry_get_text(GTK_ENTRY(indirizzo)), gtk_entry_get_text(GTK_ENTRY(citta)), gtk_entry_get_text(GTK_ENTRY(provincia)), gtk_entry_get_text(GTK_ENTRY(email)), gtk_entry_get_text(GTK_ENTRY(sitoWeb)), gtk_entry_get_text(GTK_ENTRY(note)), gtk_entry_get_text(GTK_ENTRY(telefono)), gtk_entry_get_text(GTK_ENTRY(fax)),lid);
    mysql_real_query(conn, query, strlen(query));
        mysql_real_query(conn, query, strlen(query));
           errore=mysql_errno(conn);
        if (errore==0)
         d = notify_notification_new ("Informazione", "L'inserimento è riuscito.", "dialog-information");
	else
		d = notify_notification_new ("Errore", mysql_error(conn), "dialog-error");
	notify_notification_show (d, NULL);
	g_object_unref(G_OBJECT(d));;
}


void creaFrameFornitore() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento Fornitore");
    gtk_window_set_position(GTK_WINDOW(finestra), GTK_WIN_POS_CENTER);
    gtk_widget_realize(GTK_WIDGET(finestra));
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestra), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Fornitore: ");
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
    label=gtk_label_new("Indirizzo: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    indirizzo=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), indirizzo, TRUE, TRUE, 0);
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

