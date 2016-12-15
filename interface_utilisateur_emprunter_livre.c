#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structus.h"
#include<string.h>




 GtkWidget *enty_date_emprunt,*entry_date_retour;


typedef struct Emprunt Emprunt;
typedef struct Livre Livre;





void interface_utilisateur_emprunter_livre(GtkWidget *win,int idLivre)

{


//****récuper livre************************//


Livre *book  = (Livre *)malloc(sizeof(Livre));
book = GetLivre(idLivre);

GtkWidget* pBoite;
    GtkWidget *label1,*label2,*label3,*label4,*label5,*label6,*label7;
    GtkWidget *table;


if(book->nb_examplaires_disponibles>0){

pBoite = gtk_dialog_new_with_buttons("CONFIRMATION EMPRUNT",
GTK_WINDOW(win),
GTK_DIALOG_MODAL,
GTK_STOCK_OK,GTK_RESPONSE_OK,
GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,
NULL);

  table = gtk_table_new(6,6, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  label1 = gtk_label_new(NULL);
  gchar *str1 = "<b>Titre :</b>";
  gtk_label_set_markup(GTK_LABEL(label1), str1);
  gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,3, 0, 1);


   label2 = gtk_label_new(NULL);
  gchar *str2 = "<b>STATUS de disponibilite :</b>";
  gtk_label_set_markup(GTK_LABEL(label2), str2);
  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0,3, 1, 2);




  label5 = gtk_label_new(NULL);
  gchar *str5 = book->Titre;
  gtk_label_set_markup(GTK_LABEL(label5), str5);
  gtk_table_attach_defaults(GTK_TABLE(table), label5, 3,5, 0, 1);

  label6 = gtk_label_new(NULL);
  gchar *str6;
   str6 = "disponible";
   int ss ;
switch (gtk_dialog_run(GTK_DIALOG(pBoite)))
{
/* L utilisateur valide */
case GTK_RESPONSE_OK:



//ici enregister l'emprunt//


{


Emprunt *prnt  = (Emprunt *)malloc(sizeof(Emprunt));

int idUser = Getsession();


prnt->Utilisateur_id_utilisateur=idUser;
prnt->Livre_id_livre=idLivre;
 ss  = Creer_Emprunt(prnt);

if(ss!=-1)
{
//dialog_succes_emprunter(win);

}

}

break;
/* L utilisateur annule */
case GTK_RESPONSE_CANCEL:

case GTK_RESPONSE_NONE:

default:
printf("nottttt okk");

break;
}
  gtk_label_set_markup(GTK_LABEL(label6), str6);
  gtk_table_attach_defaults(GTK_TABLE(table), label6, 3,5, 1, 2);



    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), table, TRUE, FALSE, 0);

    gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);

    gtk_dialog_run(GTK_DIALOG(pBoite));

    gtk_widget_destroy(pBoite);


}
else{


  pBoite = gtk_message_dialog_new(GTK_WINDOW(win),
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_INFO,
            GTK_BUTTONS_OK,
            "Demande d'emprunt");




  table = gtk_table_new(6,6, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  label1 = gtk_label_new(NULL);
  gchar *str1 = "<b>Titre :</b>";
  gtk_label_set_markup(GTK_LABEL(label1), str1);
  gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,3, 0, 1);


   label2 = gtk_label_new(NULL);
  gchar *str2 = "<b>STATUS de disponibilite :</b>";
  gtk_label_set_markup(GTK_LABEL(label2), str2);
  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0,3, 1, 2);




  label5 = gtk_label_new(NULL);
  gchar *str5 = book->Titre;
  gtk_label_set_markup(GTK_LABEL(label5), str5);
  gtk_table_attach_defaults(GTK_TABLE(table), label5, 3,5, 0, 1);

  label6 = gtk_label_new(NULL);
  gchar *str6;

  str6 = "non disponible";
  label3 = gtk_label_new(NULL);
  gchar *str3 = "<b>DATE DE DISPONIBILITe D'UN EXEMPLAIRE :</b>";
  gtk_label_set_markup(GTK_LABEL(label3), str3);
  gtk_table_attach_defaults(GTK_TABLE(table), label3, 0,3, 2, 3);


  label7 = gtk_label_new(NULL);
  gchar *str7 = "21/2/2016";
  gtk_label_set_markup(GTK_LABEL(label7), str7);
  gtk_table_attach_defaults(GTK_TABLE(table), label7, 3,5, 2, 3);


  gtk_label_set_markup(GTK_LABEL(label6), str6);
  gtk_table_attach_defaults(GTK_TABLE(table), label6, 3,5, 1, 2);



    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), table, TRUE, FALSE, 0);

    gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);

    gtk_dialog_run(GTK_DIALOG(pBoite));

    gtk_widget_destroy(pBoite);

}


}
