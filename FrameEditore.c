#include <gtk/gtk.h>
#include "editore.h"

GtkWindow *finestra=NULL;
GtkWidget *id=NULL;
GtkWidget *nome=NULL;
GtkWidget *sconto=NULL;
GtkWidget *note=NULL;

extern editore *CreaEditore(unsigned long id, char *nome, unsigned long sconto, char *note);
extern char *getNomeEditore(editore *e);
void salva() {
    unsigned long lid=0L, lsconto=0L;
    unsigned int result;
    GtkWidget *d=NULL;
    char *strnome=NULL;
    char *strnote=NULL;
    editore *e;
    if (gtk_entry_get_text_length(GTK_ENTRY(nome))>0)  {
        if (gtk_entry_get_text_length(GTK_ENTRY(id))>0)
            if (sscanf(gtk_entry_get_text(GTK_ENTRY(id)),"%lu", &lid) != 1) {
                d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_ERROR, GTK_BUTTONS_CLOSE, "Il campo ID Editore non è intero.");
                gtk_dialog_run(GTK_DIALOG(d));
                gtk_widget_destroy(d);
                return;
            }
        sscanf(gtk_entry_get_text(GTK_ENTRY(sconto)),"%lu", &lsconto);
        strnome=gtk_entry_get_text(GTK_ENTRY(nome));
        strnote=gtk_entry_get_text(GTK_ENTRY(note));
        e=CreaEditore(lid, strnome, lsconto, strnote);
        result=editoreDAO(e);
        free(e);
        d=gtk_message_dialog_new(GTK_WINDOW(finestra), GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_CLOSE, "La query ha dato numero di uscita %u", result);
        gtk_dialog_run(GTK_DIALOG(d));
        gtk_widget_destroy(d);
    }
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
    gtk_widget_realize(finestra);
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