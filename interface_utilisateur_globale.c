#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structus.h"
#include<string.h>


GtkWidget *entry_livre ;

typedef struct Livre Livre;
//fonction pour ouvirir interface modifier profile ********************//




void click_trier(GtkComboBox *combo,gpointer data)
{
gchar *string=gtk_combo_box_get_active_text(combo);
printf("hdhdhdhd %s  \n", string);

int x2 = Nombre_Livres_Totale ();
struct Livre books[x2];
 GtkWidget *win = NULL;
if(string=="Auteur")
{
Trier_Livres_Auteur(books);
  interface_utilisateur_globale(win,books);

}else
{

printf("we are here titre \n");
Trier_Livres_Titre(books);
  interface_utilisateur_globale(win,books);

}









}





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
 GtkWidget *win = NULL;
 int idLivre = atoi(user_data);
 printf("id livre est %d \n", idLivre);
interface_utilisateur_emprunter_livre(win,idLivre);
}


void deconnecter_utilisateur(GtkButton *button,gpointer p)
{
printf("deconetder utilisateur \n");
gtk_widget_hide(p);
    GtkWidget *win = NULL;
 login_interface(win);
 gtk_main();

}
char *str;

void toggled_func(GtkWidget* widget,gpointer data)
{

printf("teh data is %s \n", data);
str = data ;
printf("str %s \n", str);


}




void onclick_rechercher(GtkWidget* widget,gpointer data)
{

  gchar *text;
  printf("the data i %s \n",data);
   text= gtk_entry_get_text(GTK_ENTRY (data));
printf(" rechercher %s  , %s %d \n",str,text,(str=="1"));

if(str=="1")
{
printf("recherche par Titre \n");
Livre *book  = (Livre *)malloc(sizeof(Livre));
book = Rechercher_livre_Titre(text);
printf("the book is %s ,%s \n", book->Titre,book->Auteur);

}else if(str=="2")
{
printf("recherche par Auteur \n");
Livre *book  = (Livre *)malloc(sizeof(Livre));
book = Rechercher_livre_Auteur(text);
printf("the book is %s ,%s \n", book->Titre,book->Auteur);

}else{

printf("recherche par ISBN \n");

Livre *book  = (Livre *)malloc(sizeof(Livre));
//book = Rechercher_livre_ISBN(text);
printf("the book is %s ,%s \n", book->Titre,book->Auteur);
}


}


//***************ouvrir interface details livre utisateur*****//





void ouvrir_interface_details_livre(GtkWidget* widget,gpointer data)

{

printf("details livre \n");

}



void ouvrir_interface_emprunter_livre(GtkWidget* widget,gpointer data)

{
printf("id livre est %s \n", data);

int idLivre = atoi(data);
GtkWidget *win = NULL;
printf("ientfdfdfd\n");
interface_utilisateur_emprunter_livre(win,idLivre);
}





void interface_utilisateur_globale(GtkWidget *window,struct Livre books[])
{
 str="1";

  GtkWidget *vbox,*hbox;
GtkWidget *list_group,*radio_button_titre,*radio_button_auteur,*radio_button_isbn,*combo,*label_sep;
  GtkWidget *toolbar,*button,*label1,*label2;
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
  button_recherche=gtk_tool_button_new_from_stock(GTK_STOCK_FIND);

 //Associer callback***************************************





  entry_livre=gtk_entry_new();
  hbox = gtk_hbox_new(FALSE, 0);

  g_signal_connect(button_recherche,"clicked",G_CALLBACK(onclick_rechercher),entry_livre);

  radio_button_titre=gtk_radio_button_new_with_label (NULL,"Titre");
  g_signal_connect(radio_button_titre,"toggled",G_CALLBACK(toggled_func),(gpointer)"1");

  radio_button_auteur=gtk_radio_button_new_with_label (gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button_titre)),"Auteur");
  g_signal_connect(radio_button_auteur,"toggled",G_CALLBACK(toggled_func),(gpointer)"2");

  radio_button_isbn=gtk_radio_button_new_with_label (gtk_radio_button_get_group(GTK_RADIO_BUTTON(radio_button_titre)),"ISBN");
   g_signal_connect(radio_button_isbn,"toggled",G_CALLBACK(toggled_func),(gpointer)"3");

   gchar *str = "<i><b><big>||</big></b></i> ";
  label_sep=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label_sep), str);
  combo = gtk_combo_box_new_text();


  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Auteur");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "Titre");
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo), "ISBN");
g_signal_connect(G_OBJECT(combo),"changed",G_CALLBACK(click_trier),NULL);

  gtk_box_pack_start(GTK_BOX(hbox), label_recherche_livre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), entry_livre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), radio_button_titre, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), radio_button_auteur, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), radio_button_isbn, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), button_recherche, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), label_sep, FALSE, FALSE, 5);
  gtk_box_pack_start(GTK_BOX(hbox), combo, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);


/* ********************************************** */
/* *********************** table ************************ */


//récuper la liste des livres***************//



    int x2 =  Nombre_Livres_Totale();


table = gtk_table_new(x2, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;

for (i=0; i < x2 ; i++) {
    label1=gtk_label_new(books[i].Titre);
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,1, i, i+1);

    label1=gtk_label_new(books[i].ISBN_livre);
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 1,2, i, i+1);
    for (j=2; j < 4; j++) {
      if(j==2)
      {
      button = gtk_tool_button_new_from_stock(GTK_STOCK_OK);
     g_signal_connect (button, "clicked",ouvrir_interface_emprunter_livre,books[i].id_livre);
      }
      if(j==3) {
      button = gtk_tool_button_new_from_stock(GTK_STOCK_INDEX);
     g_signal_connect (button, "clicked",ouvrir_interface_details_livre,books[i].id_livre);
      }

      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);

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

