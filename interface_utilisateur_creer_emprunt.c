#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_interfaces.h"



void interface_creer_emprunts(GtkWidget *window)
{

//Déclaration des variables**********************
GtkWidget *image;
GtkWidget *labellogin,*labelmdp;
GtkWidget *entylogin,*entrymdp;
GtkWidget *button_inscrit,*button_submit_login;
//prépare la féntre**********************

window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window),"E-library");
gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);

//utiliser l'objct fixed pour l'emplacement**************//
GtkWidget *fixed;
fixed=gtk_fixed_new();

//les images************************
  image= gtk_image_new_from_file("images/login_image.png");
  gtk_fixed_put(GTK_FIXED(fixed),image,250,70);
//*********************************************//

  /*  gestion des labels */
labellogin=gtk_label_new("Votre Login :");
gtk_fixed_put(GTK_FIXED(fixed),labellogin,170,170);
labelmdp=gtk_label_new("Mot de passe");
gtk_fixed_put(GTK_FIXED(fixed),labelmdp,170,230);


/*gestion des entrées input ********/
  entylogin=gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),entylogin,260,170);
  entrymdp=gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),entrymdp,260,230);


 /* gestion des buttons *********************/
button_submit_login=gtk_button_new_with_label("Connecter");
gtk_fixed_put(GTK_FIXED(fixed),button_submit_login,260,270);
button_inscrit=gtk_button_new_with_label("Vous n'avez pas déja un compte ?");
gtk_fixed_put(GTK_FIXED(fixed),button_inscrit,240,320);
/* ************************************************* */









  gtk_container_add(GTK_CONTAINER(window),fixed);
  gtk_widget_show_all(window);
}
