#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_functions.h"




void admin_details_utilisateur(GtkWidget *window,int idUtilisateur)
{









GtkWidget *image;
GtkWidget *text1,*label_nom,*label_prenom,*label_email,*label_motdepasse,*label_adresse,*label_num_tel;
GtkWidget *entry_CIN,*entry_nom,*entry_prenom,*entry_email,*entry_motdepasse,*entry_adresse,*entry_num_tel;
GtkWidget *button_submit;
GtkWidget *frame;
gchar* sUtf8;
gchar* Titre;
gchar* Auteur;
gchar* livres;
gchar* Description_Livre;
//Maison_Edition
//disponibilite
//prix_livre
gchar* prix_livre;
gchar* disponibilite;
gchar* Maison_Edition;
gchar* emprunt_retard;
gchar* emprunt_totale;
gchar* empruntcours;
gchar* utilisateurs;
GtkWidget *text_livres , *text_utilisateurs , *text_emprunts_retards , *text_emprunts_encours , * text_emprunts_totale ;


//défénir notre fentre ***********************//

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"E-library");
gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

//défenir le frame *******************//
frame = gtk_frame_new("Details utilisateur");
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
       /* *********************************** */

       /* definir fixed qui permet de gerer la position des composents */
       GtkWidget *fixed;
       fixed=gtk_fixed_new();
       gtk_fixed_put(GTK_FIXED(fixed),frame,150,155);
       gtk_widget_set_size_request(frame, 380, 300);
       /* *************************** */

       /* gestion de l'image du chart */
       image= gtk_image_new_from_file("images/books.png");
       gtk_fixed_put(GTK_FIXED(fixed),image,260,25);
       /* ************************************** */
       /* gestion des labels */


        text_livres=gtk_label_new(NULL);
        text_utilisateurs=gtk_label_new(NULL);
        text_emprunts_retards=gtk_label_new(NULL);
        text_emprunts_encours=gtk_label_new(NULL);
        text_emprunts_totale=gtk_label_new(NULL);

     Titre= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Titre Livre</span>\n",
        -1, NULL, NULL, NULL);
          Auteur = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Auteur Ernest Hemigway est un auteur jdjjd</span>\n",
        -1, NULL, NULL, NULL);
          Description_Livre= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Ce Livre présente un des jjjjjjjjjjj</span>\n",
        -1, NULL, NULL, NULL);


   Maison_Edition = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Maison d'edition est Darna :D</span>\n",
        -1, NULL, NULL, NULL);
        prix_livre = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Prix : 15Dt</span>\n",
        -1, NULL, NULL, NULL);

           disponibilite= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Disponible OU Non</span>\n",
        -1, NULL, NULL, NULL);




    gtk_label_set_markup(GTK_LABEL(text_livres),Titre);
    gtk_label_set_markup(GTK_LABEL(text_utilisateurs),Description_Livre);
    gtk_label_set_markup(GTK_LABEL(text_emprunts_retards),Auteur);
    gtk_label_set_markup(GTK_LABEL(text_emprunts_encours),Maison_Edition );
    gtk_label_set_markup(GTK_LABEL(text_emprunts_totale), prix_livre  );
     gtk_label_set_markup(GTK_LABEL(text_emprunts_totale),disponibilite  );
 //*******************************************************************************//
g_free(livres);
g_free(utilisateurs);
g_free(emprunt_retard );
g_free(empruntcours);
g_free(emprunt_totale);


//**************************************************//

gtk_fixed_put(GTK_FIXED(fixed),text_livres,170,170);
gtk_fixed_put(GTK_FIXED(fixed),text_utilisateurs,170,200);
gtk_fixed_put(GTK_FIXED(fixed),text_emprunts_retards,170,230);
gtk_fixed_put(GTK_FIXED(fixed),text_emprunts_encours,170,260);
gtk_fixed_put(GTK_FIXED(fixed),text_emprunts_totale,170,290);
//*******************************************************//



  //***********************************//
  gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}




