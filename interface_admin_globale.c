#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_structus.h"

//préparer les callbacks********************//

typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;


//défenir les callbacks*************



void open_fenetre_liste_emprunts(GtkButton *button, gpointer user_data)
{
   gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
    printf("ouvrir interface liste des emprunts \n");
    interface_admin_gerer_emprunts(win);

}





void open_fenetre_statistique(GtkButton *button, gpointer user_data)
{
   gtk_widget_hide(user_data);
    GtkWidget *win = NULL;

    statistiques(user_data);

}


void open_fenetre_Ajouter_livre(GtkButton *button, gpointer user_data)
{
   gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
    printf("ouvrir interface liste des emprunts \n");
    Ajout_livre(user_data);

}



void open_fenetre_gerer_users(GtkButton *button, gpointer user_data)
{
   gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
    printf("ouvrir interface liste des utilisateurs \n");
    interface_admin_gerer_Utilisateurs(user_data);

}



void Livre_Details(GtkButton *button, gpointer user_data)
{
int idLivre = atoi(user_data);
  GtkWidget *win = NULL;
details_livre(win,idLivre);

}

//*******************************************//
void Editer_Livre(GtkButton *button, gpointer user_data)
{
int idLivre = atoi(user_data);
  GtkWidget *win = NULL;
admin_modifier_livre(win,idLivre);

}
//*************************************//


void Supprimer_Livre(GtkButton *button, gpointer user_data)
{

int idLivre = atoi(user_data);
printf("id livre a suuprimer est %d \n", idLivre);

//déclecher le dialog de supprimer le livre
 GtkWidget *win = NULL;
 interface_supprimer_livre(win,idLivre);

}

//**************************************//

void deconnecter_admin(GtkButton *button, gpointer user_data)
{
printf("deconetder utilisateur \n");
gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
 login_interface(win);
 gtk_main();

}


void interface_admin_globale (GtkWidget *window)
{




  //GtkWidget *window,*windows2;
  GtkWidget *vbox,*hbox;

  GtkWidget *toolbar,*button,*label1,*label2;
  GtkWidget *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb,*liste_users,*statistisue;
  GtkToolItem *sep1,*sep2,*sep3,*sep4,*sep5;
  GtkToolItem *exitTb;
  GtkWidget *table;
GtkWidget *label_recherche_livre,*entry_livre,*button_recherche;

  //gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
  gtk_window_set_title(GTK_WINDOW(window), "ADMIN");

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
  gtk_tool_button_set_label(openTb,"Demande d'emprunte");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), openTb, -1);

  sep2 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep2, -1);

  saveTb = gtk_tool_button_new_from_stock(GTK_STOCK_ADD);
  gtk_tool_button_set_label(saveTb,"Ajouter livre");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), saveTb, -1);

  //asscoier conecter pour ajouter livre
   g_signal_connect(G_OBJECT(saveTb), "clicked",
         open_fenetre_Ajouter_livre, NULL);

//*************************************************//
  sep3 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep3, -1);

  liste_users = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_tool_button_set_label(liste_users,"Liste utilisateur");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar),liste_users, -1);

  sep4 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep4, -1);

  statistisue = gtk_tool_button_new_from_stock(GTK_STOCK_PREFERENCES);
  gtk_tool_button_set_label(statistisue,"Statistique");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), statistisue, -1);


  sep5 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep5, -1);

  exitTb = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exitTb, -1);


  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  g_signal_connect(G_OBJECT(exitTb), "clicked",
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
/* ******************************************************************* */
/*  ******************* recherche **************************** */

  label_recherche_livre=gtk_label_new("Livre");
  button_recherche=gtk_button_new_with_label("Rechercher");

  entry_livre=gtk_entry_new();
  hbox = gtk_hbox_new(FALSE, 0);


  gtk_box_pack_start(GTK_BOX(hbox), label_recherche_livre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), entry_livre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), button_recherche, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);

/* ********************************************** */
/* *********************** table ************************ */


int x = Nombre_Livres_Totale();


struct Livre liste_books[x];
liste_Livres(liste_books);






table = gtk_table_new(x, 5, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;









for (i=0; i < x; i++) {
    label1=gtk_label_new(NULL);
    gtk_label_set_text(label1,liste_books[i].Titre);
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,1, i, i+1);
    label2=gtk_label_new(NULL);
    gtk_label_set_text(label2,liste_books[i].ISBN_livre);
    gtk_table_attach_defaults(GTK_TABLE(table), label2, 1,2, i, i+1);
    for (j=2; j < 5; j++) {


     // if(j==1) button = gtk_button_new_from_stock("Details");
      if(j==2)
      {
      button = gtk_tool_button_new_from_stock(GTK_STOCK_DIALOG_INFO);
      g_signal_connect (button, "clicked",G_CALLBACK (Livre_Details),liste_books[i].id_livre);
      }
       //g_signal_connect (G_OBJECT (button), "clicked", G_CALLBACK (helloWorld), (gpointer) window);

      if(j==3) {
      button = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
      g_signal_connect (button, "clicked",Editer_Livre,liste_books[i].id_livre);
      }
      if(j==4)
      {
      button =  gtk_tool_button_new_from_stock(GTK_STOCK_DELETE);
      g_signal_connect (button, "clicked",Supprimer_Livre,liste_books[i].id_livre);
      }
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);

    }
  }


//**************************************************************//
//*************Associer les callbacks********************//
g_signal_connect (statistisue, "clicked",open_fenetre_statistique,NULL);
//**************************************************************//
//g_signal_connect (saveTb, "clicked",open_fenetre_modifier_profile,NULL);

g_signal_connect (liste_users, "clicked",open_fenetre_gerer_users,NULL);
g_signal_connect (openTb, "clicked",open_fenetre_liste_emprunts,NULL);
//*************************************************************//
      if(j==2) button = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
//g_signal_connect (Modifytab, "clicked",deconnecter_admin,NULL);







gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);
/* *************************************************** */
  gtk_widget_show_all(window);



}
