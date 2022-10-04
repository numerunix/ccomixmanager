#include <gtk/gtk.h>
#include <mariadb/mysql.h>

static GtkWindow *finestra=NULL;
static GtkWidget *id=NULL;
static GtkWidget *nome=NULL;
static GtkWidget *sconto=NULL;
static GtkWidget *note=NULL;
static char query[4096];
static int errore;
static GtkWidget *d=NULL;
extern MYSQL *conn;

static void carica() {
	MYSQL_RES * res=NULL;
	MYSQL_ROW row=NULL;
	unsigned long lid=0L;
        sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid);
         sprintf(query, "SELECT nome, sconto, note FROM Editori WHERE idEditore='%lu';",lid);
       mysql_real_query(conn, query, strlen(query));
       res=mysql_store_result(conn);
       row=mysql_fetch_row(res);
       if (row==NULL) {
               d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "La categoria inserito non è stato trovato.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
       }
       
       gtk_entry_set_text(GTK_ENTRY(nome), row[0]);
       gtk_entry_set_text(GTK_ENTRY(sconto), row[1]);
       gtk_entry_set_text(GTK_ENTRY(note), row[2]);
       mysql_free_result(res);
}

static void modifica() {
unsigned long lid=0L, lsconto=0L;
        sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid);
        sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto);

 	sprintf(query, "UPDATE Editori SET nome='%s', sconto=%lu, note='%s' WHERE idEditore=%lu;",gtk_entry_get_text(GTK_ENTRY(nome)),lsconto, gtk_entry_get_text(GTK_ENTRY(note)), lid);
        mysql_real_query(conn, query, strlen(query));
        errore=mysql_errno(conn);
        if (errore != 0)
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Errore %d: %s", errore, mysql_error(conn));
	else
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Operazione effettuata");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
 
}

static void salva() {
    unsigned long lid=0L, lsconto=0L;
    GtkWidget *d=NULL;
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
           gtk_dialog_run(GTK_DIALOG(d));
           gtk_widget_destroy(d);
           return;
    }
    if (sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto) != 1) {
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
           gtk_dialog_run(GTK_DIALOG(d));
           gtk_widget_destroy(d);
           return;
    }
    	sprintf(query, "INSERT INTO Editori(idEditore, nome, sconto, note) VALUES(%lu, '%s', %lu, '%s');", lid, gtk_entry_get_text(GTK_ENTRY(nome)), lsconto, gtk_entry_get_text(GTK_ENTRY(note)));
    	mysql_real_query(conn, query, strlen(query));
        errore=mysql_errno(conn);
        if (errore==0)
         d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Operazione effettuata");
	else
	   d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "Errore %d: %s", errore, mysql_error(conn));
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
}

void creaFrameEditore() {
    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestra=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestra), 8);
    gtk_window_set_title(GTK_WINDOW(finestra), "Inserimento Editore");
    gtk_window_set_position(GTK_WINDOW(finestra), GTK_WIN_POS_CENTER);
    gtk_widget_realize(GTK_WIDGET(finestra));
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestra), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Editore: ");
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
    label=gtk_label_new("Sconto: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    sconto=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), sconto, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Note");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    note=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), note, TRUE, TRUE, 0);
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
