#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_functions.h"




void statistiques(GtkWidget *window)
{

GtkWidget *image;
GtkWidget *text1,*label_nom,*label_prenom,*label_email,*label_motdepasse,*label_adresse,*label_num_tel;
GtkWidget *entry_CIN,*entry_nom,*entry_prenom,*entry_email,*entry_motdepasse,*entry_adresse,*entry_num_tel;
GtkWidget *button_submit;
GtkWidget *frame;
gchar* sUtf8;
gchar* livres;
gchar* emprunt_retard;
gchar* emprunt_totale;
gchar* empruntcours;
gchar* utilisateurs;
GtkWidget *text_livres , *text_utilisateurs , *text_emprunts_retards , *text_emprunts_encours , * text_emprunts_totale ;




//*************************Récuperer les données de la base de donénes***************//


int nb_livres = Nombre_Livres_Totale ();
int nb_emprtuns_retard = Nombre_Emprunts_En_Reatrd ();
int nb_emprunts_en_cours = Nombre_Emprunts_EnCours ();
int nb_emprunts_totale = Nombre_Emprunts_Totale ();
int nb_users_totale = Nombre_utilisateurs_Totale ();






//défénir notre fentre ***********************//

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"E-library");
gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

//défenir le frame *******************//
frame = gtk_frame_new("statistiques");
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
       /* *********************************** */

       /* definir fixed qui permet de gerer la position des composents */
       GtkWidget *fixed;
       fixed=gtk_fixed_new();
       gtk_fixed_put(GTK_FIXED(fixed),frame,150,155);
       gtk_widget_set_size_request(frame, 380, 300);
       /* *************************** */

       /* gestion de l'image du chart */
       image= gtk_image_new_from_file("images/barchart.png");
       gtk_fixed_put(GTK_FIXED(fixed),image,260,25);
       /* ************************************** */
       /* gestion des labels */


        text_livres=gtk_label_new(NULL);
        text_utilisateurs=gtk_label_new(NULL);
        text_emprunts_retards=gtk_label_new(NULL);
        text_emprunts_encours=gtk_label_new(NULL);
        text_emprunts_totale=gtk_label_new(NULL);


        //sprintf(livres,"%s%d","<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Vous avez" ,nb_livres,"</span>\n");
        //livres= g_locale_to_utf8(livres,-1, NULL, NULL, NULL);
        /*sprintf(emprunt_retard,"<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Vous avez %d emprunts en retard</span>\n",nb_emprtuns_retard);
          emprunt_retard = g_locale_to_utf8(emprunt_retard,
        -1, NULL, NULL, NULL);
        sprintf(emprunt_totale,"<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Vous avez %d emprunts au totale</span>\n",nb_emprunts_totale);
          emprunt_totale = g_locale_to_utf8(emprunt_totale,
        -1, NULL, NULL, NULL);
        sprintf(empruntcours,"<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Vous avez %d emprunts en cours</span>\n",nb_emprunts_en_cours);
          empruntcours = g_locale_to_utf8(empruntcours,
        -1, NULL, NULL, NULL);
        sprintf(utilisateurs,"<span font_desc=\"Times New Roman italic 12\" foreground=\"#0000FF\">Vous avez %d utilisateurs au totale</span>\n",nb_users_totale );

   utilisateurs = g_locale_to_utf8(utilisateurs,
        -1, NULL, NULL, NULL);*/




    /*gtk_label_set_markup(GTK_LABEL(text_livres),livres);
    gtk_label_set_markup(GTK_LABEL(text_utilisateurs),utilisateurs);
    gtk_label_set_markup(GTK_LABEL(text_emprunts_retards), emprunt_retard );
    gtk_label_set_markup(GTK_LABEL(text_emprunts_encours),empruntcours);
    gtk_label_set_markup(GTK_LABEL(text_emprunts_totale), emprunt_totale );*/
 //*******************************************************************************/
/*g_free(livres);
g_free(utilisateurs);
g_free(emprunt_retard );
g_free(empruntcours);
g_free(emprunt_totale);*/


//**************************************************//

gtk_fixed_put(GTK_FIXED(fixed),text_livres,170,170);
gtk_fixed_put(GTK_FIXED(fixed),text_utilisateurs,170,200);
gtk_fixed_put(GTK_FIXED(fixed),text_emprunts_retards,170,230);
gtk_fixed_put(GTK_FIXED(fixed),text_emprunts_encours,170,260);
gtk_fixed_put(GTK_FIXED(fixed),text_emprunts_totale,170,290);
//*******************************************************///



  //***********************************//
  gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}
