#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include "user_interfaces.h"
#include "user_functions.h"
#include "user_structus.h"

typedef struct Livre Livre;

GtkWidget *entry_titre= NULL ;
GtkWidget *entry_isbn= NULL ;
GtkWidget *entry_auteur= NULL ;
GtkWidget *entry_maison_edition= NULL ;
GtkWidget *entry_prix= NULL ;
GtkWidget *entry_nb_exemplaires= NULL ;
//entry_categorie
GtkWidget *entry_categorie= NULL ;







void livre_Ajouter(GtkButton *button, gpointer user_data)
{
   gchar *titre;
  gchar *auteur;
  gchar *maison;
  gchar *prix;
  gchar *nb_exemplaires;
  gchar *categorie;
  gchar *ISBN;

GtkWidget *win = NULL;

titre = gtk_entry_get_text(GTK_ENTRY (entry_titre));
    auteur = gtk_entry_get_text(GTK_ENTRY (entry_auteur));
      maison = gtk_entry_get_text(GTK_ENTRY (entry_maison_edition));
    categorie = gtk_entry_get_text(GTK_ENTRY (entry_categorie));
   ISBN = gtk_entry_get_text(GTK_ENTRY (entry_isbn));
    nb_exemplaires= gtk_entry_get_text(GTK_ENTRY (entry_nb_exemplaires));
 prix= gtk_entry_get_text(GTK_ENTRY (entry_prix));

//***************************Valider les champs*****************

if(strlen(titre)==0 || strlen(auteur)==0 || strlen(maison)==0 || strlen(categorie)==0 || strlen(ISBN)==0 || strlen(nb_exemplaires)==0
|| strlen(prix)==0)
{

printf("erreur dans l'ajout valider les donnes \n");

}

else
{



    Livre *book  = (Livre *)malloc(sizeof(Livre));

strcpy( book->Titre,titre);
strcpy( book->Auteur,auteur);
strcpy( book->maison_edition,maison);
strcpy( book->categorie,categorie);
strcpy( book->ISBN_livre,ISBN);
 book->nb_examplaires_disponibles=nb_exemplaires;
 float fprix = atof(prix);
 book->prix=fprix;

printf("we are here add Book %s  \n",book->Titre);
 int res = Ajouter_livre(book);

 printf("the res is %d \n",res);

 if(res !=-1)
 {

    //afficher message succes d'ajout
    printf("succées d'ajout \n");
    dialog_succes_ajout(win);
 }else{

 printf("erreur dans l'ajout \n");
 dialog_erreur(win);
 }

}




 //affciher un message de success
 //retour au fenetre principale
//gtk_widget_hide(p);
}













void Ajout_livre(GtkWidget *window)
{

GtkWidget *frame = NULL ;
GtkWidget *image = NULL ;
GtkWidget *label_titre = NULL ;
GtkWidget *label_isbn = NULL ;
GtkWidget *label_auteur = NULL ;

GtkWidget *label_maison_edition = NULL ;
GtkWidget *label_prix= NULL ;
GtkWidget *label_nb_exemplaire= NULL ;
GtkWidget *button_add= NULL ;
/* definir window */
       window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
       gtk_window_set_title(GTK_WINDOW(window),"E-library");
       gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
       frame = gtk_frame_new("Livre");
       gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

       /* *********************************** */

       /* definir fixed qui permet de gerer la position des composents */
       GtkWidget *fixed;
       fixed=gtk_fixed_new();
       gtk_fixed_put(GTK_FIXED(fixed),frame,150,145);
       gtk_widget_set_size_request(frame, 380, 300);
       /* *************************** */

       /* gestion de l'image de login */
       image= gtk_image_new_from_file("images/book.png");
       gtk_fixed_put(GTK_FIXED(fixed),image,250,70);
       gtk_widget_set_size_request(image, 150, 70);

       /* ************************************** */

       /* gestion des labels */
       label_titre=gtk_label_new("TITRE :");
       gtk_fixed_put(GTK_FIXED(fixed),label_titre,170,170);

       label_isbn=gtk_label_new("ISBN");
       gtk_fixed_put(GTK_FIXED(fixed),label_isbn,170,200);
       label_auteur=gtk_label_new("AUTEUR");
       gtk_fixed_put(GTK_FIXED(fixed),label_auteur,170,230);
       label_maison_edition=gtk_label_new("MAISON-EDITION");
       gtk_fixed_put(GTK_FIXED(fixed),label_maison_edition,170,260);
       label_prix=gtk_label_new("PRIX");
       gtk_fixed_put(GTK_FIXED(fixed),label_prix,170,290);
       label_nb_exemplaire=gtk_label_new("NOMBRE EXEMPLAIRE");
       gtk_fixed_put(GTK_FIXED(fixed),label_nb_exemplaire,170,320);
       label_nb_exemplaire=gtk_label_new("Categorie");
       gtk_fixed_put(GTK_FIXED(fixed),label_nb_exemplaire,170,350);

       /*  ***************************** */

       /* gestion des zones des textes */
       entry_titre=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_titre,300,170);
       gtk_widget_set_size_request(entry_titre, 170, 25);
       entry_isbn=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_isbn,300,200);
       gtk_widget_set_size_request(entry_isbn, 170, 25);
       entry_auteur=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_auteur,300,230);
       gtk_widget_set_size_request(entry_auteur, 170, 25);

       entry_maison_edition=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_maison_edition,300,260);
       gtk_widget_set_size_request(entry_maison_edition, 170, 25);

       entry_prix=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_prix,300,290);
       gtk_widget_set_size_request(entry_prix, 170, 25);

        entry_nb_exemplaires=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_nb_exemplaires,300,320);
       gtk_widget_set_size_request(entry_nb_exemplaires, 170, 25);


        entry_categorie=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_categorie,300,350);
       gtk_widget_set_size_request(entry_prix, 170, 25);


 /* gestion des buttons */
       button_add=gtk_button_new_with_label("Ajouter");
       gtk_fixed_put(GTK_FIXED(fixed),button_add,280,380);
        gtk_widget_set_size_request(button_add, 150, 30);



g_signal_connect (button_add, "clicked",livre_Ajouter, window);


  gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}
