#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "user_structus.h"

GtkWidget *entry_CIN,*entry_nom,*entry_prenom,*entry_email,*entry_motdepasse,*entry_adresse,*entry_num_tel,*entry_login;

typedef struct Utilisateur Utilisateur;

void inscrire_user(GtkButton *button, gpointer user_data)
{
 gchar *numcin;
  gchar *nom;
  gchar *prenom;
  gchar *email;
  gchar *login;
  gchar *mot_passe;
  gchar *adresse;
  gchar *num_tel;


 //Récuperer les champs
   numcin = gtk_entry_get_text(GTK_ENTRY (entry_CIN));
   nom = gtk_entry_get_text(GTK_ENTRY (entry_nom));
   prenom= gtk_entry_get_text(GTK_ENTRY (entry_prenom));
   email = gtk_entry_get_text(GTK_ENTRY (entry_email));
   mot_passe = gtk_entry_get_text(GTK_ENTRY (entry_motdepasse));
   adresse = gtk_entry_get_text(GTK_ENTRY (entry_adresse));
   num_tel= gtk_entry_get_text(GTK_ENTRY (entry_num_tel));
   login = gtk_entry_get_text(GTK_ENTRY (entry_login));
//préparer le structure par ces valeurs

//printf("the data are %s %s %s %s %s %s %s %s \n ",numcin,nom,prenom,email,login,mot_passe,adresse,num_tel);

struct Utilisateur *uti = malloc(sizeof *uti);

strcpy( uti->Nom,nom);
strcpy( uti->Prenom,prenom);
strcpy( uti->Num_Cin,numcin);
strcpy( uti->adresse,adresse);
strcpy( uti->num_tel,num_tel);
strcpy( uti->mot_passe,mot_passe);
strcpy( uti->email,email);
strcpy( uti->login,login);
//enrgister l'utilisateur

//printf("the data are %s %s %s %s  \n ",uti->Nom,uti->Num_Cin,uti->Prenom);


int res = inscrire(uti);


printf("the res are %d \n", res);
GtkWidget *win = NULL;
if(res !=-1)
{
 gtk_widget_hide(user_data);
  interface_utilisateur_globale(win);
   gtk_main ();

}
else
{
//Dialog d'erreur du message !!!!!!!!
printf("login déja utilisée \n");

}

//si resulta de l'inscription 1 alors affciher interface_utilisateur_globale si non affciher erreur



//gtk_widget_hide(p);
}











void inscrire_interface(GtkWidget *window)
{


GtkWidget *image;
GtkWidget *label_CIN,*label_nom,*label_prenom,*label_email,*label_motdepasse,*label_adresse,*label_num_tel;

GtkWidget *button_submit;
GtkWidget *frame;

GtkWidget *label_login ;



//défénir notre fentre ***********************//

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"E-library");
gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

//défenir le frame *******************//
frame = gtk_frame_new("Utilisateur");
gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
       /* *********************************** */

       /* definir fixed qui permet de gerer la position des composents */
       GtkWidget *fixed;
       fixed=gtk_fixed_new();
       gtk_fixed_put(GTK_FIXED(fixed),frame,150,155);
       gtk_widget_set_size_request(frame, 380, 300);
       /* *************************** */

       /* gestion de l'image de login */
       image= gtk_image_new_from_file("images/student.png");
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

       label_login=gtk_label_new("login");
       gtk_fixed_put(GTK_FIXED(fixed),label_login,170,290);

       label_motdepasse=gtk_label_new("MOT DE PASSE");
       gtk_fixed_put(GTK_FIXED(fixed),label_motdepasse,170,320);


       label_adresse=gtk_label_new("ADRESSE");
       gtk_fixed_put(GTK_FIXED(fixed),label_adresse,170,350);


       label_num_tel=gtk_label_new("NUM-TELEPHONE");
       gtk_fixed_put(GTK_FIXED(fixed),label_num_tel,170,380);
       /*  ***************************** */

       /* gestion des zones des textes */


        /*label_nom=gtk_label_new("NOM");
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
       gtk_fixed_put(GTK_FIXED(fixed),label_num_tel,170,350);*/
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


        entry_login=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_login,280,290);
       gtk_widget_set_size_request( entry_login, 170, 25);

       entry_motdepasse=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_motdepasse,280,320);
       gtk_widget_set_size_request(entry_motdepasse, 170, 25);


       entry_adresse=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_adresse,280,350);
       gtk_widget_set_size_request(entry_adresse, 170, 25);


       entry_num_tel=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_num_tel,280,380);
       gtk_widget_set_size_request(entry_num_tel, 170, 25);
       /* ************************************** */

       /* gestion des buttons */
       button_submit=gtk_button_new_with_label("S'inscrire");
       gtk_fixed_put(GTK_FIXED(fixed),button_submit,280,410);
        gtk_widget_set_size_request(button_submit, 150, 30);

  //***********************************//
  gtk_container_add(GTK_CONTAINER(window),fixed);
  g_signal_connect (button_submit, "clicked",inscrire_user, window);
  gtk_widget_show_all(window);
}


