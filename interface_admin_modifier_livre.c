#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "user_structs.h"
#include "user_interfaces.h"

#include "user_structus.h"

//préparer les callbacks********************//

typedef struct Livre Livre;



void admin_modifier_livre(GtkWidget *window,int idLivre)
{


//***********************Récuperer les livres*************************//

printf("id est %d \n",idLivre);
 Livre *book  = (Livre *)malloc(sizeof(Livre));
book = GetLivre(idLivre);

printf("donnes boooks est %d  \n", book->id_livre);

//************************************************//

GtkWidget *image;

GtkWidget *label_titre,*label_isbn,*label_auteur,*label_maison_edition,*label_prix,*label_nb_exemplaire,*label_categorie;
GtkWidget *entry_titre,*entry_isbn,*entry_auteur,*entry_maison_edition,*entry_prix,*entry_nb_exemplaire,*entry_categorie;
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
        image= gtk_image_new_from_file("livre.png");
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
        //printf("donnes boooks est %d  \n", book->id_livre);
        //gtk_entry_set_text(entry_titre,book->Titre);

        //***************************************//
        entry_isbn=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_isbn,300,200);
        gtk_widget_set_size_request(entry_isbn, 170, 25);

        //*******************************************//
        entry_auteur=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_auteur,300,230);
        gtk_widget_set_size_request(entry_auteur, 170, 25);

        //****************************************************//
        entry_maison_edition=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_maison_edition,300,260);
        gtk_widget_set_size_request(entry_maison_edition, 170, 25);


        //********************************************//
        entry_prix=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_prix,300,290);
        gtk_widget_set_size_request(entry_prix, 170, 25);


        //*********************************************//
        entry_nb_exemplaire=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_nb_exemplaire,300,320);
        gtk_widget_set_size_request(entry_nb_exemplaire, 170, 25);
        entry_categorie=gtk_entry_new();
        gtk_fixed_put(GTK_FIXED(fixed),entry_categorie,300,340);
        gtk_widget_set_size_request(entry_categorie, 170, 25);

        /* ************************************** */

        /* gestion des buttons */
        button_submit=gtk_button_new_with_label("Enregistrer");
        gtk_fixed_put(GTK_FIXED(fixed),button_submit,300,380);
        gtk_widget_set_size_request(button_submit, 150, 30);

        /* ******************************************* */









        gtk_container_add(GTK_CONTAINER(window),fixed);
        gtk_widget_show_all(window);
}
