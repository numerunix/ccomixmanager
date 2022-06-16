#include <gtk/gtk.h>
#include "negozio.h"

GtkWindow *finestraNegozio=NULL;
GtkWidget *idNegozio=NULL;
GtkWidget *nomeNegozio=NULL;
GtkWidget *indirizzoNegozio=NULL;
GtkWidget *cittaNegozio=NULL;
GtkWidget *telefonoNegozio=NULL;

void salvaNegozio() {
    unsigned long lid=0L;
    unsigned int result;
    GtkWidget *d=NULL;
    char *strnome=NULL;
    char *strindirizzo=NULL;
    char *strcitta=NULL;
    char *strtelefono;
    negozio *n;
    if (gtk_entry_get_text_length(GTK_ENTRY(nomeNegozio))>0 && gtk_entry_get_text_length(GTK_ENTRY(cittaNegozio))>0 && gtk_entry_get_text_length(GTK_ENTRY(indirizzoNegozio))>0 && gtk_entry_get_text_length(GTK_ENTRY(telefonoNegozio))>0)  {
        if (gtk_entry_get_text_length(GTK_ENTRY(idNegozio))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idNegozio)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestraNegozio), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        strnome=gtk_entry_get_text(GTK_ENTRY(nomeNegozio));
        strindirizzo=gtk_entry_get_text(GTK_ENTRY(indirizzoNegozio));
        strcitta=gtk_entry_get_text(GTK_ENTRY(cittaNegozio));
        strtelefono=gtk_entry_get_text(GTK_ENTRY(telefonoNegozio));
        n=CreaNegozio(lid, strnome, strindirizzo, strcitta, strtelefono);
        result=negozioDAO(n);
        deallocaNegozio(n);
        d=gtk_message_dialog_new(GTK_WINDOW(finestraNegozio), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query ha dato numero di uscita %u", result);
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else if (gtk_entry_get_text_length(GTK_ENTRY(nomeNegozio))==0) {
        d=gtk_message_dialog_new(GTK_WINDOW(finestraNegozio), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo nome non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(cittaNegozio))==0) {
        d=gtk_message_dialog_new(GTK_WINDOW(finestraNegozio), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo città non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else if (gtk_entry_get_text_length(GTK_ENTRY(indirizzoNegozio))==0) {
        d=gtk_message_dialog_new(GTK_WINDOW(finestraNegozio), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo indirizzo non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(telefonoNegozio))==0) {
        d=gtk_message_dialog_new(GTK_WINDOW(finestraNegozio), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo telefono non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    }
}

void creaFrameNegozio() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestraNegozio=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestraNegozio), 8);
    gtk_window_set_title(GTK_WINDOW(finestraNegozio), "Inserimento Editore");
    gtk_window_set_position(GTK_WINDOW(finestraNegozio), GTK_WIN_POS_CENTER);
    gtk_widget_realize(finestraNegozio);
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestraNegozio), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Negozio: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Nome: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    nomeNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), nomeNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Indirizzo: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    indirizzoNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), indirizzoNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Città: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    cittaNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), cittaNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Telefono: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    telefonoNegozio=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), telefonoNegozio, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    bottone=gtk_button_new_with_label("Ok");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salvaNegozio), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestraNegozio, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestraNegozio));
}
