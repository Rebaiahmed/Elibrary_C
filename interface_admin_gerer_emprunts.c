#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"

void interface_admin_gerer_emprunts (GtkWidget *window)
{

GtkWidget *vbox,*hbox;

 GtkWidget *toolbar,*button,*label,*label1;
 GtkToolItem *newTb;
 GtkToolItem *openTb;
 GtkToolItem *saveTb;
 GtkToolItem *sep;
 GtkToolItem *exitTb;
 GtkWidget *table;
 GtkWidget *label_recherche_utli,*label_recherche_livre,*entry_utilisateur,*entry_livre,*button_recherche;




vbox = gtk_vbox_new(FALSE, 0);
 gtk_container_add(GTK_CONTAINER(window), vbox);
/* tolllllbarr ************************ */
 toolbar = gtk_toolbar_new();
 gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

 newTb = gtk_tool_button_new_from_stock(GTK_STOCK_HOME);
 gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

 openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
 gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

 saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_ADD);
 gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

 saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
 gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

 sep = gtk_separator_tool_item_new();
 gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1);

 exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
 gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);

 gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

 g_signal_connect(G_OBJECT(exitTb), "clicked",
       G_CALLBACK(gtk_main_quit), NULL);

 g_signal_connect(G_OBJECT(window), "destroy",
       G_CALLBACK(gtk_main_quit), NULL);
/* ******************************************************************* */
/*  ******************* recherche **************************** */
 label_recherche_utli=gtk_label_new("Utilisateur");
 label_recherche_livre=gtk_label_new("Livre");
 button_recherche=gtk_button_new_with_label("Rechercher");
 entry_utilisateur=gtk_entry_new();
 entry_livre=gtk_entry_new();
 hbox = gtk_hbox_new(FALSE, 0);
 gtk_box_pack_start(GTK_BOX(hbox), label_recherche_utli, FALSE, FALSE, 5);
 gtk_box_pack_start(GTK_BOX(hbox), entry_utilisateur, FALSE, FALSE, 5);
 gtk_box_pack_start(GTK_BOX(hbox), label_recherche_livre, FALSE, FALSE, 5);
 gtk_box_pack_start(GTK_BOX(hbox), entry_livre, FALSE, FALSE, 5);
 gtk_box_pack_start(GTK_BOX(hbox), button_recherche, FALSE, FALSE, 5);
 gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
/* ****************************************** */

/* ************** table ************************/
table = gtk_table_new(4, 4, TRUE);




//gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}
