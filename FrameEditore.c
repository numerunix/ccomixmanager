#include <gtk/gtk.h>
#include "editore.h"

GtkWindow *finestraEditore=NULL;
GtkWidget *idEditore=NULL;
GtkWidget *nomeEditore=NULL;
GtkWidget *scontoEditore=NULL;
GtkWidget *noteEditore=NULL;

void salvaEditore() {
    unsigned long lid=0L, lsconto=0L;
    unsigned int result;
    GtkWidget *d=NULL;
    char *strnome=NULL;
    char *strnote=NULL;
    editore *e;
    if (gtk_entry_get_text_length(GTK_ENTRY(nomeEditore))>0)  {
        if (gtk_entry_get_text_length(GTK_ENTRY(idEditore))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(idEditore)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestraEditore), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        sscanf(gtk_entry_get_text(GTK_ENTRY(scontoEditore)),"%lu", &lsconto);
        strnome=gtk_entry_get_text(GTK_ENTRY(nomeEditore));
        strnote=gtk_entry_get_text(GTK_ENTRY(noteEditore));
        e=CreaEditore(lid, strnome, lsconto, strnote);
        result=editoreDAO(e);
        deallocaEditore(e);
        e=NULL;
        d=gtk_message_dialog_new(GTK_WINDOW(finestraEditore), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query ha dato numero di uscita %u", result);
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    } else {
        d=gtk_message_dialog_new(GTK_WINDOW(finestraEditore), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo nome non può essere NULL");
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);

    }
}

void creaFrameEditore() {

    GtkWidget *vbox=NULL;
    GtkWidget *hbox=NULL;
    GtkWidget *label=NULL;
    GtkWidget *bottone=NULL;
    finestraEditore=GTK_WINDOW(gtk_window_new(GTK_WINDOW_TOPLEVEL));
    gtk_container_set_border_width(GTK_CONTAINER(finestraEditore), 8);
    gtk_window_set_title(GTK_WINDOW(finestraEditore), "Inserimento Editore");
    gtk_window_set_position(GTK_WINDOW(finestraEditore), GTK_WIN_POS_CENTER);
    gtk_widget_realize(finestraEditore);
    vbox=gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_container_add(GTK_CONTAINER(finestraEditore), vbox);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("ID Editore: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    idEditore=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), idEditore, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Nome: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    nomeEditore=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), nomeEditore, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Sconto: ");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    scontoEditore=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), scontoEditore, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    label=gtk_label_new("Note");
    gtk_box_pack_start(GTK_BOX(hbox), label, TRUE,TRUE, 0);
    noteEditore=gtk_entry_new();
    gtk_box_pack_start(GTK_BOX(hbox), noteEditore, TRUE, TRUE, 0);
    hbox=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
    bottone=gtk_button_new_with_label("Ok");
    g_signal_connect(bottone, "clicked", G_CALLBACK(salvaEditore), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    bottone=gtk_button_new_with_label("Annulla");
    g_signal_connect(bottone, "clicked", G_CALLBACK(gtk_window_close), NULL);
    gtk_box_pack_start(GTK_BOX(hbox), bottone, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);
    gtk_window_set_modal(finestraEditore, TRUE);
    gtk_widget_show_all(GTK_WIDGET(finestraEditore));
}
