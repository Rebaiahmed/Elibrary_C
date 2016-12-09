#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_functions.h"





//************************la fonction reéie au button modifier profile***********//

void Profile_Modifier(GtkButton *button, gpointer user_data)
{
   gchar *titre;
  gchar *auteur;
  gchar *maison;
  gchar *prix;
  gchar *nb_exemplaires;
  gchar *categorie;
  gchar *ISBN;


  /* titre = gtk_entry_get_text(GTK_ENTRY (entry_titre));
    auteur = gtk_entry_get_text(GTK_ENTRY (entry_auteur));
      maison = gtk_entry_get_text(GTK_ENTRY (entry_maison_edition));
    categorie = gtk_entry_get_text(GTK_ENTRY (entry_categorie));
   ISBN = gtk_entry_get_text(GTK_ENTRY (entry_isbn));
    nb_exemplaires= gtk_entry_get_text(GTK_ENTRY (entry_nb_exemplaires));
 prix= gtk_entry_get_text(GTK_ENTRY (entry_prix));

Livre *book  = (Livre *)malloc(sizeof(Livre));

strcpy( book->Titre,titre);
strcpy( book->Auteur,auteur);
strcpy( book->maison_edition,maison);
strcpy( book->categorie,categorie);
strcpy( book->ISBN_livre,ISBN);
 book->nb_examplaires_disponibles=nb_exemplaires;
 float fprix = atof(prix);
 book->prix=fprix;


 int res = Modifier_livre(book);
 //affciher un message de success
 //retour au fenetre principale
//gtk_widget_hide(user_data);*/

}









void modifier_profile_utilisateur (GtkWidget *window)
{

GtkWidget *image;
GtkWidget *label_CIN,*label_nom,*label_prenom,*label_email,*label_motdepasse,*label_adresse,*label_num_tel;
GtkWidget *entry_CIN,*entry_nom,*entry_prenom,*entry_email,*entry_motdepasse,*entry_adresse,*entry_num_tel;
GtkWidget *button_submit;
GtkWidget *frame;



//défénir notre fentre ***********************//

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"E-library");
gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

//défenir le frame *******************//
frame = gtk_frame_new("Modifier Votre profile");
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
       /* *********************************** */

       /* definir fixed qui permet de gerer la position des composents */
       GtkWidget *fixed;
       fixed=gtk_fixed_new();
       gtk_fixed_put(GTK_FIXED(fixed),frame,150,155);
       gtk_widget_set_size_request(frame, 380, 300);
       /* *************************** */

       /* gestion de l'image de login */
       image= gtk_image_new_from_file("images/user.png");
       gtk_fixed_put(GTK_FIXED(fixed),image,260,25);
       /* ************************************** */

       /* gestion des labels */
       label_CIN=gtk_label_new("CIN :");
       gtk_fixed_put(GTK_FIXED(fixed),label_CIN,170,170);
       label_nom=gtk_label_new("NOM");
       gtk_fixed_put(GTK_FIXED(fixed),label_nom,170,200);
       label_prenom=gtk_label_new("PRENOM");
       gtk_fixed_put(GTK_FIXED(fixed),label_prenom,170,230);
       label_email=gtk_label_new("E-MAIL");
       gtk_fixed_put(GTK_FIXED(fixed),label_email,170,260);
       label_motdepasse=gtk_label_new("MOT DE PASSE");
       gtk_fixed_put(GTK_FIXED(fixed),label_motdepasse,170,290);
       label_adresse=gtk_label_new("ADRESSE");
       gtk_fixed_put(GTK_FIXED(fixed),label_adresse,170,320);
       label_num_tel=gtk_label_new("NUM-TELEPHONE");
       gtk_fixed_put(GTK_FIXED(fixed),label_num_tel,170,350);
       /*  ***************************** */

       /* gestion des zones des textes */
       entry_CIN=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_CIN,280,170);
       gtk_widget_set_size_request(entry_CIN, 170, 25);

     label_nom=gtk_label_new("NOM");
       gtk_fixed_put(GTK_FIXED(fixed),label_nom,170,200);
       label_prenom=gtk_label_new("PRENOM");
       gtk_fixed_put(GTK_FIXED(fixed),label_prenom,170,230);
       label_email=gtk_label_new("E-MAIL");
       gtk_fixed_put(GTK_FIXED(fixed),label_email,170,260);
       label_motdepasse=gtk_label_new("MOT DE PASSE");
       gtk_fixed_put(GTK_FIXED(fixed),label_motdepasse,170,290);
       label_adresse=gtk_label_new("ADRESSE");
       gtk_fixed_put(GTK_FIXED(fixed),label_adresse,170,320);
       label_num_tel=gtk_label_new("NUM-TELEPHONE");
       gtk_fixed_put(GTK_FIXED(fixed),label_num_tel,170,350);
       /*  ***************************** */

       /* gestion des zones des textes */
       entry_CIN=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_CIN,280,170);
       gtk_widget_set_size_request(entry_CIN, 170, 25);


entry_nom=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_nom,280,200);
       gtk_widget_set_size_request(entry_nom, 170, 25);
       entry_prenom=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_prenom,280,230);
       gtk_widget_set_size_request(entry_prenom, 170, 25);
       entry_email=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_email,280,260);
       gtk_widget_set_size_request(entry_email, 170, 25);
       entry_motdepasse=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_motdepasse,280,290);
       gtk_widget_set_size_request(entry_motdepasse, 170, 25);
       entry_adresse=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_adresse,280,320);
       gtk_widget_set_size_request(entry_adresse, 170, 25);
       entry_num_tel=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_num_tel,280,350);
       gtk_widget_set_size_request(entry_num_tel, 170, 25);
       /* ************************************** */

       /* gestion des buttons */
       button_submit=gtk_button_new_with_label("Modifier");
       gtk_fixed_put(GTK_FIXED(fixed),button_submit,280,380);
        gtk_widget_set_size_request(button_submit, 150, 30);

 //**********************conecter le button au signal********************//
g_signal_connect ( button_submit, "clicked",Profile_Modifier, window);
  //***********************************//
  gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}
