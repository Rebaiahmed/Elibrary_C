#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structus.h"

//préparer les callbacks********************//

typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;



void Details_Utilisateurs(GtkButton *button, gpointer user_data)
{

int idUser = atoi(user_data);
Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));

printf("ici afficher details utilisateur  %d \n",idUser);
GtkWidget *win = NULL;
admin_details_utilisateur(win,idUser);
}

//*******************************************//
void Editer_Utilisateur(GtkButton *button, gpointer user_data)
{
int idUser = atoi(user_data);
Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));
printf("ici afficher details utilisateur  %d \n",idUser);
printf("ici editer User \n");
GtkWidget *win = NULL;
admin_modifier_utilisateur(win,idUser);
}

//**********************************************//

void on_response (GtkDialog *dialog,gint response_id, gpointer   user_data)
{
  /*For demonstration purposes, this will show the int value
  of the response type*/
  g_print ("response is %d\n", response_id);

  /*This will cause the dialog to be destroyed*/
  gtk_widget_destroy (GTK_WIDGET (dialog));
}



//*****************************************************************//



void Supprimer_User(GtkButton *button, gpointer user_data)
{

int idUser = atoi(user_data);

printf("ici afficher details utilisateur  %d \n",idUser);
printf("ici supprimer livre \n");

int user_id = supprimer_utilisateur(idUser);
GtkWidget *win = NULL;
if(user_id==-1)
{
dialog_erreur_suppression_user(win);

}else
{

dialog_succes_suppression(win);

}
gtk_widget_hide(win);
interface_admin_globale(win);


}


//***************************************//

void interface_admin_gerer_Utilisateurs( GtkWidget *window)
{



  GtkWidget *vbox,*hbox;

  GtkWidget *toolbar,*button,*label1,*label2;
  GtkWidget *newTb;
  GtkToolItem *openTb;
  GtkToolItem *saveTb,*Modifytab,*statistisue;
  GtkToolItem *sep1,*sep2,*sep3,*sep4,*sep5;
  GtkToolItem *exitTb;
  GtkWidget *table;
GtkWidget *label_recherche_livre,*entry_livre,*button_recherche;



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

  sep3 = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep3, -1);

  Modifytab = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_tool_button_set_label(Modifytab,"Liste utilisateur");
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), Modifytab, -1);

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

  //************Récuperer la liste des Livres **************//
  //****************Récupere le nombre de livres********************//



int x2 =  Nombre_utilisateurs_Totale ();
struct Utilisateur liste_users[x2];
 Liste_Utilisateurs(liste_users);

//printf("test svp e5dheem %s  \n",liste_books[0].Titre);

   table = gtk_table_new(x2, 5, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;
  int pos=0;








for (i=0; i < x2; i++) {
    label1=gtk_label_new(NULL);
    gtk_label_set_text(label1,liste_users[i].Nom);
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,1, i, i+1);
    label2=gtk_label_new(NULL);
    gtk_label_set_text(label2,liste_users[i].Prenom);
    gtk_table_attach_defaults(GTK_TABLE(table), label2, 1,2, i, i+1);
    for (j=2; j < 5; j++) {


     // if(j==1) button = gtk_button_new_from_stock("Details");
      if(j==2)
      {
      button = gtk_tool_button_new_from_stock(GTK_STOCK_DIALOG_INFO);
      g_signal_connect (button, "clicked",Details_Utilisateurs,liste_users[i].id_utilisateur);
      }
       //g_signal_connect (G_OBJECT (button), "clicked",Editer_Utilisateur,liste_users[i].id_utilisateur);

      if(j==3) {
      button = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
      g_signal_connect (button, "clicked",Editer_Utilisateur,liste_users[i].id_utilisateur);
      }
      if(j==4)
      {
      button =  gtk_tool_button_new_from_stock(GTK_STOCK_DELETE);
      g_signal_connect (button, "clicked",Supprimer_User,liste_users[i].id_utilisateur);
      }
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);
      pos++;
    }
  }
gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);
/* *************************************************** */

//***************Lec callback
  gtk_widget_show_all(window);







}
