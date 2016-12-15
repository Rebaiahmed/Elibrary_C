#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_functions.h"
#include "user_structus.h"

typedef struct Utilisateur Utilisateur;


void Interface_utilisateur_liste_emprunts(GtkWidget *window)
{


GtkWidget *vbox;

  GtkWidget *toolbar;
  GtkToolItem *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb,*exit;

  GtkWidget *table,*label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8,*label_date_emprunt;
  GtkToolItem *sep1,*sep2,*sep3;


  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
  gtk_window_set_title(GTK_WINDOW(window), "Utlistateur");

  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);
/* tolllllbarr ************************ */
  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);

  newTb = gtk_tool_button_new_from_stock(GTK_STOCK_HOME);
  gtk_tool_button_set_label(newTb,"Accueil");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), newTb, -1);

   sep1 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep1, -1);

  openTb = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_tool_button_set_label(openTb,"Emprunts effectue");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

  sep2 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep2, -1);

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
  gtk_tool_button_set_label(saveTb,"Modifier profile");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

  sep3 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep3, -1);

  exit = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
  gtk_tool_button_set_label(exit,"Exit");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exit, -1);
  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);




  //************************Récupere currentUser
      int idUser = Getsession();
//printf("teh currentUser is %d \n",idUser);
  Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));
  user = getUser(idUser);
   int nb_emprunts = Nb_emprunts_En_Cours(idUser);
struct Emprunt liste_emprunts[nb_emprunts];
liste_Emprunts_Utilisateurs_En_Cours(idUser,liste_emprunts);

printf("we are here in list emprunts  %d \n",nb_emprunts);






/* ******************************************************************* */

/* *********************** table ************************ */
table = gtk_table_new(nb_emprunts, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;
    label1=gtk_label_new("Titre");
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,1, 0, 1);
    label2=gtk_label_new("Date emprunt");
    gtk_table_attach_defaults(GTK_TABLE(table), label2, 1,2, 0, 1);
    label3=gtk_label_new("Date retour");
    gtk_table_attach_defaults(GTK_TABLE(table), label3, 2,3, 0, 1);
    label4=gtk_label_new("etat");
    gtk_table_attach_defaults(GTK_TABLE(table), label4, 3,4, 0, 1);

for (i=1; i <= nb_emprunts; i++) {

    gchar* datemperunt = g_locale_to_utf8(liste_emprunts[i].date_emprunt,-1,NULL,NULL,NULL);
    label5=gtk_label_new(datemperunt);

    gtk_table_attach_defaults(GTK_TABLE(table), label5, 0,1, i, i+1);

    label6=gtk_label_new(liste_emprunts[i].date_emprunt);
    gtk_table_attach_defaults(GTK_TABLE(table), label6, 1,2, i, i+1);

    label7=gtk_label_new(liste_emprunts[i].date_retour);
    gtk_table_attach_defaults(GTK_TABLE(table), label7, 2,3, i, i+1);

    label8=gtk_label_new(liste_emprunts[i].etat);
    gtk_table_attach_defaults(GTK_TABLE(table), label8, 3,4, i, i+1);

  }
gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);
/* *************************************************** */
  gtk_widget_show_all(window);

}
