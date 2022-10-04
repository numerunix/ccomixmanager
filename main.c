#include <stdlib.h>
#include <gtk/gtk.h>
#include <mariadb/mysql.h>
#include "logo.xpm"

extern void creaFrameConnessione();
extern void creaFrameEditore();
MYSQL *conn=NULL;


extern void creaFrameFornitore();
extern void creaFrameNegozio();
extern void creaFrameCollana();
extern void creaFrameClienti();
extern void creaFrameCategoria();
extern void creaFrameDipendente();
extern void creaFrameArticolo();
extern void creaFrameOggetto();

static void esci() {
	if (conn!=NULL)
		mysql_close(conn);
	gtk_main_quit();
}

static void helloWorld (GtkWidget *wid, GtkWidget *win)
{
  const gchar **lista_autori=calloc(1, sizeof(gchar*));
  lista_autori[0]="Giulio Sorrentino";
  GtkWidget *dialog = gtk_about_dialog_new();
  gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(dialog), lista_autori);
  gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(dialog), "© Giulio Sorrentino 2022");
  gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(dialog), "http://github.com/numerunix/ccomixmanager");
  gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(dialog), GTK_LICENSE_GPL_3_0);
  gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(dialog), "0.3");
  gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(dialog),gdk_pixbuf_new_from_xpm_data(logo_xpm));
  gtk_dialog_run (GTK_DIALOG (dialog));
  gtk_widget_destroy (dialog);
}

int main (int argc, char *argv[])
{
  GtkWidget *button = NULL;
  GtkWidget *win = NULL;
  GtkWidget *vbox = NULL;

  /* Initialize GTK+ */
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, (GLogFunc) gtk_false, NULL);
  gtk_init (&argc, &argv);
  g_log_set_handler ("Gtk", G_LOG_LEVEL_WARNING, g_log_default_handler, NULL);

  /* Create the main window */
  win = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width (GTK_CONTAINER (win), 8);
  gtk_window_set_title (GTK_WINDOW (win), "Hello World");
  gtk_window_set_position (GTK_WINDOW (win), GTK_WIN_POS_CENTER);
  gtk_widget_realize (win);
  g_signal_connect (win, "destroy", esci, NULL);

  /* Create a vertical box with buttons */
  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 6);
  gtk_container_add (GTK_CONTAINER (win), vbox);

  button = gtk_button_new_with_label("Inserisci Fornitore");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameFornitore), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Editore");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameEditore), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

    button = gtk_button_new_with_label("Inserisci Negozio");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameNegozio), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Collana");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameCollana), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Cliente");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameClienti), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Categoria");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameCategoria), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Dipendente");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameDipendente), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Articolo");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameArticolo), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Inserisci Oggetto");

  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (creaFrameOggetto), NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Informazioni");


  g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (helloWorld), (gpointer) win);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);
  button = gtk_button_new_with_label("Chiudi");
  
  g_signal_connect (button, "clicked", gtk_main_quit, NULL);
  gtk_box_pack_start (GTK_BOX (vbox), button, TRUE, TRUE, 0);

  /* Enter the main loop */
  gtk_widget_show_all (win);
  creaFrameConnessione();
  gtk_main ();
  return 0;
}
