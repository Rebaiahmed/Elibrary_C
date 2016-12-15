#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "user_structs.h"
#include "user_interfaces.h"

//préparer les callbacks********************//

typedef struct Livre Livre;


GtkWidget *entry_titre,*entry_isbn,*entry_auteur,*entry_maison_edition,*entry_prix,*entry_nb_exemplaire,*entry_categorie;


void Livre_Modifier(GtkButton *button, gpointer user_data)
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
    nb_exemplaires= gtk_entry_get_text(GTK_ENTRY (entry_nb_exemplaire));
 prix= gtk_entry_get_text(GTK_ENTRY (entry_prix));



 if(strlen(titre)==0 || strlen(auteur)==0 || strlen(maison)==0 || strlen(categorie)==0 || strlen(categorie)==0
 || strlen(ISBN)==0 || strlen(nb_exemplaires)==0 || strlen(prix)==0)
 {

 dialog_erreur_donnees_livre(win);

 }else{

printf("moifier le livre \n");

    Livre *book  = (Livre *)malloc(sizeof(Livre));

//strcpy(book->Titre,titre);
strcpy( book->Auteur,auteur);
strcpy( book->maison_edition,maison);
strcpy( book->categorie,categorie);
strcpy( book->ISBN_livre,ISBN);
 book->nb_examplaires_disponibles=nb_exemplaires;
 float fprix = atof(prix);
 //book->prix=fprix;

 int res = Modifier_livre(book);

 printf("the res is %d \n",res);
 }




}

//****************************************//



void admin_modifier_livre(GtkWidget *window,int idLivre)
{


//***********************Récuperer les livres*************************//


     Livre *book  = (Livre *)malloc(sizeof(Livre));


book = GetLivre(idLivre);
//printf("ou data ar %s , %s , %s \n", book->Titre,book->maison_edition,book->prix);


//************************************************//

GtkWidget *image;

GtkWidget *label_titre,*label_isbn,*label_auteur,*label_maison_edition,*label_prix,*label_nb_exemplaire,*label_categorie;

GtkWidget *button_submit;
GtkWidget *frame;

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title(GTK_WINDOW(window),"bibliothque");
        gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
        frame = gtk_frame_new("Modidfier Livre");
        gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);

        /* *********************************** */

        /* definir fixed qui permet de gerer la position des composents */
        GtkWidget *fixed;
        fixed=gtk_fixed_new();
        gtk_fixed_put(GTK_FIXED(fixed),frame,150,145);
        gtk_widget_set_size_request(frame, 380, 300);
        /* *************************** */

        /* gestion de l'image de login */
        image= gtk_image_new_from_file("images/livre.png");
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


        label_nb_exemplaire=gtk_label_new("NOMBRE EXEMPLAIRE AJOUTE");
        gtk_fixed_put(GTK_FIXED(fixed),label_nb_exemplaire,170,320);


        label_categorie=gtk_label_new("CATEGORIE");
        gtk_fixed_put(GTK_FIXED(fixed),label_categorie,170,370);

        /*  ***************************** */

        /* gestion des zones des textes */
        entry_titre=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_titre,300,170);
        gtk_widget_set_size_request(entry_titre, 170, 25);
         //gtk_entry_set_text(entry_titre,book->Titre);
        //printf("donnes boooks est %d  \n", book->id_livre);
        //gtk_entry_set_text(entry_titre,book->Titre);

        //***************************************//
        entry_isbn=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_isbn,300,200);
        gtk_widget_set_size_request(entry_isbn, 170, 25);
         gtk_entry_set_text(entry_isbn,book->ISBN_livre);

        //*******************************************//
        entry_auteur=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_auteur,300,230);
        gtk_widget_set_size_request(entry_auteur, 170, 25);
       gtk_entry_set_text(entry_auteur,book->Auteur);
        //****************************************************//
        entry_maison_edition=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_maison_edition,300,260);
        gtk_widget_set_size_request(entry_maison_edition, 170, 25);
        gtk_entry_set_text(entry_maison_edition,book->maison_edition);

        //********************************************//
        entry_prix=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_prix,300,290);
        gtk_widget_set_size_request(entry_prix, 170, 25);
  gtk_entry_set_text(entry_prix,book->prix);

        //*********************************************//
        entry_nb_exemplaire=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_nb_exemplaire,300,320);
        gtk_widget_set_size_request(entry_nb_exemplaire, 170, 25);
          gtk_entry_set_text(entry_nb_exemplaire,book->nb_examplaires_disponibles);



        entry_categorie=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_categorie,300,340);
        gtk_widget_set_size_request(entry_categorie, 170, 25);
  gtk_entry_set_text(entry_categorie,book->categorie);
        /* ************************************** */

        /* gestion des buttons */
        button_submit=gtk_button_new_with_label("Enregistrer");
        gtk_fixed_put(GTK_FIXED(fixed),button_submit,300,380);
        gtk_widget_set_size_request(button_submit, 150, 30);

        /* ******************************************* */

//associer callback au fonction modifier********************
g_signal_connect ( button_submit, "clicked",Livre_Modifier, window);







        gtk_container_add(GTK_CONTAINER(window),fixed);
        gtk_widget_show_all(window);
}
