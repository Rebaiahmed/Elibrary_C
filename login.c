#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "user_structs.h"
#include "user_functions.h"
#include "user_interfaces.h"
#include "./functions/connect_database.h"


 GtkWidget *entylogin,*entrymdp;
 MYSQL *con ;



void login_user(GtkButton *button, gpointer user_data)
{
  gchar *log;
    gchar *pass;
   log = gtk_entry_get_text(GTK_ENTRY (entylogin));
    pass = gtk_entry_get_text(GTK_ENTRY (entrymdp));

    printf("the log is %s , %s \n", log, pass);
    int x = login(log,pass) ;
    //x = 1 ;

    printf("result of login is %d \n",x);
     GtkWidget *win = NULL;
    if(x==0)
    {
    //affciher message d'erreur
    //printf("error message \n");
    gtk_widget_hide(user_data);
   interface_utilisateur_globale(win);
   gtk_main ();
    }else if( x==1)
    {

     gtk_widget_hide(user_data);
 interface_admin_globale(win);
       gtk_main ();

    }else
    {

      printf("message d'erreur avec un dialog \n");
    }



//gtk_widget_hide(p);
}



void afficher_inscrire(GtkButton *button, gpointer user_data)
{
   gtk_widget_hide(user_data);
    GtkWidget *win = NULL;
    printf("hello we will show the interface signup \n");
    inscrire_interface(win);
}





void login_interface (GtkWidget *window)
{

//Déclaration des variables**********************
    GtkWidget *image;
    GtkWidget *labellogin,*labelmdp;

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


//****************la connexion aux interfaces(button se connecter , button inscrire) *************************//

g_signal_connect (button_submit_login, "clicked",login_user, window);
g_signal_connect (button_inscrit, "clicked",afficher_inscrire, window);



    gtk_container_add(GTK_CONTAINER(window),fixed);
    gtk_widget_show_all(window);
}
