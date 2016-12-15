#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structus.h"



typedef struct Utilisateur Utilisateur;



void envoyer_email(GtkButton *button, gpointer user_data)
{
printf("ok \n");



}


 void details_User ( GtkWidget *win,int idUser)
{
    GtkWidget* pBoite;
    GtkWidget *label1,*label2,*label3,*label4,*label5,*label6,*label7,*label8;
    GtkWidget *label9,*label10,*label11,*label12,*label13,*label14,*label15,*label16;
    GtkWidget *table,*btn;




    //**************************Récupere le livre*******************//

     Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));


user = getUser(idUser);

int nb_emprunts = Nb_emprunts_En_Cours(idUser);




   // pBoite = gtk_dialog_new_with_buttons("Details",GTK_WINDOW(win),GTK_DIALOG_MODAL,GTK_BUTTONS_CLOSE,NULL,NULL,NULL,NULL);
     pBoite = gtk_message_dialog_new (GTK_WINDOW (win), GTK_DIALOG_MODAL, GTK_MESSAGE_OTHER, GTK_BUTTONS_CLOSE, NULL);

  table = gtk_table_new(9,2, TRUE);
  gtk_table_set_row_spacings(GTK_TABLE(table), 2);
  gtk_table_set_col_spacings(GTK_TABLE(table), 2);

  label1 = gtk_label_new(NULL);
  gchar *str1 = "<b>Nom Complet : </b>";
  gtk_label_set_markup(GTK_LABEL(label1), str1);
  gtk_table_attach_defaults(GTK_TABLE(table), label1, 0,1, 0, 1);

  label2 = gtk_label_new(NULL);
  gchar *str2 = "<b>email: </b>";
  gtk_label_set_markup(GTK_LABEL(label2), str2);
  gtk_table_attach_defaults(GTK_TABLE(table), label2, 0,1, 1, 2);

  label3 = gtk_label_new(NULL);
  gchar *str3 = "<b>nb_emprunts </b>";
  gtk_label_set_markup(GTK_LABEL(label3), str3);
  gtk_table_attach_defaults(GTK_TABLE(table), label3, 0,1, 2, 3);

  label4 = gtk_label_new(NULL);
  gchar *str4 = "<b> Num_Cin </b>";
  gtk_label_set_markup(GTK_LABEL(label4), str4);
  gtk_table_attach_defaults(GTK_TABLE(table), label4, 0,1, 3, 4);

  label5 = gtk_label_new(NULL);
  gchar *str5 = "<b>num_tel</b>";
  gtk_label_set_markup(GTK_LABEL(label5), str5);
  gtk_table_attach_defaults(GTK_TABLE(table), label5, 0,1, 4, 5);


   label6 = gtk_label_new(NULL);
  gchar *str6 = "<b>Adresse</b>";
  gtk_label_set_markup(GTK_LABEL(label6), str6);
  gtk_table_attach_defaults(GTK_TABLE(table), label6, 0,1, 5, 6);



   btn=gtk_button_new_with_label("envoyer email");
   gtk_table_attach_defaults(GTK_TABLE(table), btn, 0,2, 7, 8);


    g_signal_connect (btn, "clicked",envoyer_email,idUser);
  /*


  //book



  // aprit d'ici mettre nos données              ********************************************* */


  label9 = gtk_label_new(user->Nom);
  gtk_table_attach_defaults(GTK_TABLE(table), label9, 1,2, 0, 1);

  label10 = gtk_label_new(user->email);
  gtk_table_attach_defaults(GTK_TABLE(table), label10, 1,2, 1, 2);


   char s2[50];

  sprintf(s2,"%d",nb_emprunts);

  label11 = gtk_label_new(s2);
  gtk_table_attach_defaults(GTK_TABLE(table), label11, 1,2, 2, 3);

  label12 = gtk_label_new(user->Num_Cin);
  gtk_table_attach_defaults(GTK_TABLE(table), label12, 1,2, 3, 4);

  label13 = gtk_label_new(user->num_tel);
  gtk_table_attach_defaults(GTK_TABLE(table), label13, 1,2, 4, 5);


 label14 = gtk_label_new(user->adresse);
  gtk_table_attach_defaults(GTK_TABLE(table), label14, 1,2, 5, 6);







    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pBoite)->vbox), table, TRUE, FALSE, 0);



    gtk_widget_show_all(GTK_DIALOG(pBoite)->vbox);


    gtk_dialog_run(GTK_DIALOG(pBoite));

    gtk_widget_destroy(pBoite);
}
