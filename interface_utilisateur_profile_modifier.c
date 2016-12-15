#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"
#include "user_functions.h"
#include "user_structus.h"

typedef struct Utilisateur Utilisateur;

GtkWidget *entry_CIN,*entry_nom,*entry_prenom,*entry_email,*entry_motdepasse,*entry_adresse,*entry_num_tel;


//************************la fonction reéie au button modifier profile***********//

void Profile_Modifier(GtkButton *button, gpointer user_data)
{

printf("we will modify our profile \n");
 gchar *numcin;
  gchar *nom;
  gchar *prenom;
  gchar *email;
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
//préparer le structure par ces valeurs
//*******************Valider la formulaire
GtkWidget *win = NULL;

if(strlen(numcin)==0 || strlen(nom)==0 || strlen(prenom)==0 || strlen(email)==0 || strlen(mot_passe)==0 || strlen(adresse)==0
|| strlen(num_tel)==0)
{
printf("vous devez remplir tous les champ \n");

dialog_erreur_inscrire_donnees(win);




}

else

{

struct Utilisateur *uti = malloc(sizeof *uti);

strcpy( uti->Nom,nom);
strcpy( uti->Prenom,prenom);
strcpy( uti->Num_Cin,numcin);
strcpy( uti->adresse,adresse);
strcpy( uti->num_tel,num_tel);
strcpy( uti->mot_passe,mot_passe);
strcpy( uti->email,email);

//enrgister l'utilisateur

int res = Modifier_Profile(uti);
printf("we will modify our profile \n");

if(res!=-1)
{
printf("succes de modification \n");
dialog_succes_modification(win);
}


}





}









void modifier_profile_utilisateur (GtkWidget *window)
{

GtkWidget *image;
GtkWidget *label_CIN,*label_nom,*label_prenom,*label_email,*label_motdepasse,*label_adresse,*label_num_tel;

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

    //*******************Récuper l'utilisateur courant***********************//





//************************Récupere l'utilisateur************************//

int idUser = Getsession();
printf("teh currentUser is %d \n",idUser);
Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));
user = getUser(idUser);
printf("ou data from user are %d , %s  \n",user->id_utilisateur,user->login);



       /* gestion des zones des textes */
       entry_CIN=gtk_entry_new();

       /*gtk_entry_append_text (entry_CIN,"04848993");
       gtk_fixed_put(GTK_FIXED(fixed),entry_CIN,280,170);
       gtk_widget_set_size_request(entry_CIN, 170, 25);
       gtk_entry_set_text(entry_CIN,user->Num_Cin);*/

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
        gtk_entry_set_text(entry_CIN,user->Num_Cin);



        entry_nom=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_nom,280,200);
       gtk_widget_set_size_request(entry_nom, 170, 25);
       gtk_entry_set_text(entry_nom,user->Nom);


       entry_prenom=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_prenom,280,230);
       gtk_widget_set_size_request(entry_prenom, 170, 25);
         gtk_entry_set_text(entry_prenom,user->Prenom);


       entry_email=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_email,280,260);
       gtk_widget_set_size_request(entry_email, 170, 25);
    gtk_entry_set_text(entry_email,user->email);


       entry_motdepasse=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_motdepasse,280,290);
       gtk_widget_set_size_request(entry_motdepasse, 170, 25);
  gtk_entry_set_text(entry_motdepasse,user->mot_passe);


       entry_adresse=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_adresse,280,320);
       gtk_widget_set_size_request(entry_adresse, 170, 25);
           gtk_entry_set_text(entry_adresse,user->adresse);


       entry_num_tel=gtk_entry_new();
       gtk_fixed_put(GTK_FIXED(fixed),entry_num_tel,280,350);
       gtk_widget_set_size_request(entry_num_tel, 170, 25);
        gtk_entry_set_text(entry_num_tel,user->num_tel);
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
