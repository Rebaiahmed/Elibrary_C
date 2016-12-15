#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_structus.h"



typedef struct Emprunt Emprunt;



void emprunts_changer( GtkComboBox *combo,
            gpointer     data )
{

    gchar *string = gtk_combo_box_get_active_text( combo );
    g_print( "%s \n", ( string ? string : "NULL" ) );


}



void click_refuser_emprunt(GtkButton *button, gpointer* user_data)
{

printf("user data est %d \n", user_data);
/*int *idEmprunt = user_data;
printf("id emprunte est sd \n", &idEmprunt);*/

int result = refuser_emprunt(user_data);

GtkWidget *win = NULL;
if(result==1)
{

printf("succes de suppression \n");
dialog_succes_suppression(win);
}
else{

printf("error \n");
dialog_erreur(win);
}

}


void click_valider_emprunt(GtkButton *button, gpointer user_data)
{



Emprunt *emp  = (Emprunt *)malloc(sizeof(Emprunt));
emp = GetEmprunt(user_data);

int bah = confirmer_emprunt(emp);
GtkWidget *win = NULL;
printf("the bah est %d \n", bah);
dialog_succes_valider_emprunt(win);

}







void interface_admin_gerer_emprunts (GtkWidget *window)
{

GtkWidget *vbox,*hbox;

 GtkWidget *toolbar,*button,*label,*label1,*label2,*label3,*label4;
 GtkToolItem *newTb;
 GtkToolItem *openTb;
 GtkToolItem *saveTb;
 GtkToolItem *sep;
 GtkToolItem *exitTb;
 GtkWidget *table;
 GtkWidget *label_recherche_utli,*label_recherche_livre,*entry_utilisateur,*entry_livre,*button_recherche;
  GtkWidget *combo;


   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
  gtk_window_set_title(GTK_WINDOW(window), "ADMIN");



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



       hbox = gtk_hbox_new(FALSE, 0);
combo = gtk_combo_box_new_text();
    gtk_container_add( GTK_CONTAINER( hbox ), combo );
    gtk_combo_box_append_text( GTK_COMBO_BOX( combo ), "emprunts en cours" );
    gtk_combo_box_prepend_text( GTK_COMBO_BOX( combo ), "emprunts en retard" );
    gtk_combo_box_insert_text( GTK_COMBO_BOX( combo ), 1, "emprunts en attente" );
 g_signal_connect( G_OBJECT( combo ), "changed",
                      G_CALLBACK( emprunts_changer ), NULL );


/* ******************************************************************* */
/*  ******************* recherche **************************** */


 gtk_box_pack_start(GTK_BOX(vbox), hbox, FALSE, FALSE, 5);
/* ****************************************** */



//************************Récuper les données*********************//

int x =  Nombre_Emprunts_attente ();
struct Emprunt liste_emprunts[x];
//printf("le nombre d'emprutns en cours est %d \n",x);

 //liste_Emprunts_Utilisateurs_En_Cours(1,liste_emprunts);

  liste_Emprunts_en_attente(liste_emprunts);












/* ************** table ************************/

table = gtk_table_new(x+1, 4, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);
  int i,j;

   gchar *str = "<b>Utilisateur</b>";
  label2=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label2), str);

  gchar *str1 = "<b>Livre</b>";
  label3=gtk_label_new(NULL);
  gtk_label_set_markup(GTK_LABEL(label3), str1);


  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0,1, 0, 1);
  gtk_table_attach_defaults(GTK_TABLE(table), label3, 1,2, 0, 1);
  int etat=1;
for (i=1; i < x+1; i++) {


//liste_emprunts

    label=gtk_label_new("122");
    gtk_table_attach_defaults(GTK_TABLE(table), label, 0,1, i, i+1);


    label1=gtk_label_new("122333");
    gtk_table_attach_defaults(GTK_TABLE(table), label1, 1,2, i, i+1);


int id ;
    for (j=2; j < 4; j++) {


      if(j==2)
      {
       button = gtk_tool_button_new_from_stock(GTK_STOCK_REDO);

            printf("il fault  %d \n",liste_emprunts[0].idEmprunt);
      g_signal_connect (button, "clicked",click_valider_emprunt,liste_emprunts[i-1].idEmprunt);

      }
      if(j==3)
      {button = gtk_tool_button_new_from_stock(GTK_STOCK_STOP);
        //printf("il fault  %d \n",liste_emprunts[0].idEmprunt);
      g_signal_connect (button, "clicked",click_refuser_emprunt,liste_emprunts[i-1].idEmprunt);
      }
      gtk_table_attach_defaults(GTK_TABLE(table), button, j, j+1, i, i+1);

            }




  }
gtk_box_pack_start(GTK_BOX(vbox), table, FALSE, FALSE, 5);








//gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}
