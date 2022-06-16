#include <gtk/gtk.h>
#include "fornitore.h"

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

extern unsigned int fornitoreDAO(fornitore *f);

static void salva() {
    unsigned long lid=0L;
    unsigned int result;
    GtkWidget *d=NULL;
    char *strnome=NULL, *strindirizzo=NULL, *strcitta=NULL, *strprovincia=NULL, *stremail=NULL, *strsito=NULL, *strnote=NULL, *strtelefono=NULL, *strfax=NULL;
    fornitore *f=NULL;
    if (gtk_entry_get_text_length(GTK_ENTRY(nome))>0 && gtk_entry_get_text_length(GTK_ENTRY(indirizzo))>0 && gtk_entry_get_text_length(GTK_ENTRY(citta))>0 && gtk_entry_get_text_length(GTK_ENTRY(provincia))>0 && gtk_entry_get_text_length(GTK_ENTRY(telefono))>0)  {
        if (gtk_entry_get_text_length(GTK_ENTRY(id))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Fornitore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }

        strnome=gtk_entry_get_text(GTK_ENTRY(nome));
        strindirizzo=gtk_entry_get_text(GTK_ENTRY(indirizzo));
        strcitta=gtk_entry_get_text(GTK_ENTRY(citta));
        strprovincia=gtk_entry_get_text(GTK_ENTRY(provincia));
        stremail=gtk_entry_get_text(GTK_ENTRY(email));
        strsito=gtk_entry_get_text(GTK_ENTRY(sitoWeb));
        strnote=gtk_entry_get_text(GTK_ENTRY(note));
        strtelefono=gtk_entry_get_text(GTK_ENTRY(telefono));
        strfax=gtk_entry_get_text(GTK_ENTRY(fax));
        f=CreaFornitore(lid, strnome, strindirizzo, strcitta, strprovincia , strtelefono, strfax, stremail, strsito, strnote);
        result=fornitoreDAO(f);
        deallocaFornitore(f);
        f=NULL;
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query ha dato numero di uscita %u", result);
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
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo citta non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else if (gtk_entry_get_text_length(GTK_ENTRY(provincia))==0){
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo provincia non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    } else {
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo telefono non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    }
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

