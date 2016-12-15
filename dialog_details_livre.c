#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structus.h"



typedef struct Livre Livre;


 void details_livre ( GtkWidget *win,int idLivre)
{
    GtkWidget* pBoite;
    GtkWidget *label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8;
    GtkWidget *label9,*label10,*label11,*label12,*label13,*label14,*label15,*label16;
    GtkWidget *table;




    //**************************Récupere le livre*******************//

     Livre *book  = (Livre *)malloc(sizeof(Livre));

     printf("the id off livre eest %d \n",idLivre);
book = GetLivre(idLivre);






   // pBoite = gtk_dialog_new_with_buttons("Details",GTK_WINDOW(win),GTK_DIALOG_MODAL,GTK_BUTTONS_CLOSE,NULL,NULL,NULL,NULL);
     pBoite = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_OTHER, GTK_BUTTONS_CLOSE, NULL);

  table = gtk_table_new(8,2, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  label1 = gtk_label_new(NULL);
  gchar *str1 = "<b>Titre : </b>";
  gtk_label_set_markup(GTK_LABEL(label1), str1);
  gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,1, 0, 1);

  label2 = gtk_label_new(NULL);
  gchar *str2 = "<b>Auteur : </b>";
  gtk_label_set_markup(GTK_LABEL(label2), str2);
  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0,1, 1, 2);

  label3 = gtk_label_new(NULL);
  gchar *str3 = "<b>ISBN : </b>";
  gtk_label_set_markup(GTK_LABEL(label3), str3);
  gtk_table_attach_defaults(GTK_TABLE(table), label3, 0,1, 2, 3);

  label4 = gtk_label_new(NULL);
  gchar *str4 = "<b>Categorie : </b>";
  gtk_label_set_markup(GTK_LABEL(label4), str4);
  gtk_table_attach_defaults(GTK_TABLE(table), label4, 0,1, 3, 4);

  label5 = gtk_label_new(NULL);
  gchar *str5 = "<b>maison d'edition : </b>";
  gtk_label_set_markup(GTK_LABEL(label5), str5);
  gtk_table_attach_defaults(GTK_TABLE(table), label5, 0,1, 4, 5);

  label6 = gtk_label_new(NULL);
  gchar *str6 = "<b>nombre d'emprunt : </b>";
  gtk_label_set_markup(GTK_LABEL(label6), str6);
  gtk_table_attach_defaults(GTK_TABLE(table), label6, 0,1, 5, 6);

  label7 = gtk_label_new(NULL);
  gchar *str7 = "<b>Nombre exemplaire : </b>";
  gtk_label_set_markup(GTK_LABEL(label7), str7);
  gtk_table_attach_defaults(GTK_TABLE(table), label7, 0,1, 6, 7);

  label8 = gtk_label_new(NULL);
  gchar *str8 = "<b>Prix : </b>";
  gtk_label_set_markup(GTK_LABEL(label8), str8);
  gtk_table_attach_defaults(GTK_TABLE(table), label8, 0,1, 7, 8);
  /*


  //book



  // aprit d'ici mettre nos données              ********************************************* */


  label9 = gtk_label_new(book->Titre);
  gtk_table_attach_defaults(GTK_TABLE(table), label9, 1,2, 0, 1);

  label10 = gtk_label_new(book->Auteur);
  gtk_table_attach_defaults(GTK_TABLE(table), label10, 1,2, 1, 2);

  label11 = gtk_label_new(book->ISBN_livre);
  gtk_table_attach_defaults(GTK_TABLE(table), label11, 1,2, 2, 3);

  label12 = gtk_label_new(book->categorie);
  gtk_table_attach_defaults(GTK_TABLE(table), label12, 1,2, 3, 4);

  label13 = gtk_label_new(book->maison_edition);
  gtk_table_attach_defaults(GTK_TABLE(table), label13, 1,2, 4, 5);
  char s1[50];
  sprintf(s1,"%d",book->nb_emprunts);
  label14 = gtk_label_new(s1);
  gtk_table_attach_defaults(GTK_TABLE(table), label14, 1,2, 5, 6);

  char s2[50];

  sprintf(s2,"%d",book->nb_examplaires_disponibles);
  label15 = gtk_label_new(s2);
  gtk_table_attach_defaults(GTK_TABLE(table), label15, 1,2, 6, 7);

  char s3[50];
  sprintf(s3,"%f",book->prix);
  label16 = gtk_label_new(s3);
  gtk_table_attach_defaults(GTK_TABLE(table), label16, 1,2, 7, 8);





    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), table, TRUE, FALSE, 0);



    gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);


    gtk_dialog_run(GTK_DIALOG(pBoite));

    gtk_widget_destroy(pBoite);
}
