#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "user_structus.h"



typedef struct Livre Livre;
//fonction pour ouvirir interface modifier profile ********************//

void open_fenetre_modifier_profile(GtkButton *button, gpointer user_data)
{
      gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
    printf("ouvrir interface modifier livre \n");
    modifier_profile_utilisateur(user_data);

}


//*************ouvrir fenetre la liste des emprunts ****************//

void open_fenetre_emprunts(GtkButton *button, gpointer user_data)
{

   gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
    printf("ouvrir interface liste des emprunts \n");
    //modifier_profile_utilisateur(user_data);
    Interface_utilisateur_liste_emprunts(user_data);

}



//fonction pour *****************************************//

void open_fenetre_creer_emprunt(GtkButton *button, gpointer user_data)
{

printf("on va ouvir interface crrer emprunt \n");

}


void deconnecter_utilisateur(GtkButton *button,gpointer p)
{
printf("deconetder utilisateur \n");
gtk_widget_hide(p);
    GtkWidget *win = NULL;
 login_interface(win);
 gtk_main();

}













void interface_utilisateur_globale(GtkWidget *window)
{


  GtkWidget *vbox,*hbox;

  GtkWidget *toolbar,*button,*label;
  GtkToolItem *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb,*Modifytab;
  GtkToolItem *exitTb;
  GtkWidget *table;
  GtkToolItem *sep1,*sep2,*sep3;
GtkWidget *label_recherche_livre,*entry_livre,*button_recherche;



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

  Modifytab = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
  gtk_tool_button_set_label(Modifytab,"Exit");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), Modifytab, -1);
  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);



/* ******************************************************************* */
/*  ******************* recherche **************************** */

  label_recherche_livre=gtk_label_new("Livre");
  button_recherche=gtk_tool_button_new_from_stock(GTK_STOCK_FIND);;

  entry_livre=gtk_entry_new();
  hbox = gtk_hbox_new(FALSE, 0);


  gtk_box_pack_start(GTK_BOX(hbox), label_recherche_livre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), entry_livre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), button_recherche, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);

/* ********************************************** */
/* *********************** table ************************ */


//récuper la liste des livres***************//
int x2 =  Nombre_Livres_Totale();
struct Livre liste_books[x2];
printf("le nombre de livres totale est %d \n",x2);

 liste_Livres(liste_books);




table = gtk_table_new(4, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;
  int pos=0;
for (i=0; i < x2 ; i++) {
    label=gtk_label_new("122");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0,1, i, i+1);
    for (j=1; j < 3; j++) {
      if(j==1) button = gtk_tool_button_new_from_stock(GTK_STOCK_INDEX);;
      if(j==2) button = gtk_tool_button_new_from_stock(GTK_STOCK_OK);

      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
      pos++;
    }
  }
gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);
/* *************************************************** */


//*************Associer les callbacks********************//
g_signal_connect (openTb, "clicked",open_fenetre_emprunts,NULL);
//**************************************************************//
g_signal_connect (saveTb, "clicked",open_fenetre_modifier_profile,NULL);
//*************************************************************//
g_signal_connect (Modifytab, "clicked",deconnecter_utilisateur,NULL);


int idUser = Getsession();
printf("teh currentUser is %d \n",idUser);




  gtk_widget_show_all(window);

  gtk_main();
}

