#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "user_interfaces.h"
#include "user_structus.h"


int main (int argc, char *argv[])
{

//************Déclaration des variables féntres globales *****************************//
    GtkWidget *win = NULL;
    gtk_init (&argc, &argv);

typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;



printf("hello bouhmid \n");
//SaveUser(10);
//int a = Getsession();



/*int x =  Nb_emprunts_En_Cours(1);
struct Emprunt liste_emprunts[x];
printf("le nombre d'emprutns en cours est %d \n",x);

 liste_Emprunts_Utilisateurs_En_Cours(1,liste_emprunts);

 printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);*/

//***********Tets sur la liste des Livres******************//
/*int x2 =  Nombre_Livres_Totale();
struct Livre liste_books[x2];
printf("le nombre de livres totale est %d \n",x2);



 liste_Livres(liste_books);*/
 //Livre *book  = (Livre *)malloc(sizeof(Livre));
 //GetLivre(1);
//printf("the book is %d \n",book->id_livre);

/*int x2 =  Nombre_utilisateurs_Totale ();
struct Utilisateur liste_users[x2];
 Liste_Utilisateurs(liste_users);*/



Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));


//user = getCurrentUser(1);
//printf("we are here \n");
//printf(" teh suer is %s \n ",user->email);

/*Livre *book  = (Livre *)malloc(sizeof(Livre));
book = Rechercher_livre_Titre("Book1");*/

//printf("we are here %s \n",book->Titre);




//details_livre(win);

 //interface_admin_gerer_livres(win);
 //admin_modifier_livre(win);

//printf("test svp e5dheem %s  \n",liste_books[0].Titre);

//dialog_erreur_login(win);

//Interface_utilisateur_liste_emprunts(win);
//interface_utilisateur_globale(win);
//interface_admin_globale(win);
login_interface(win);
//modifier_profile_utilisateur(win);
  //interface_utilisateur_globale(win);
    //interface_admin_globale(win);
     //statistiques(win);
     //inscrire_interface(win);
     //Modifier_Livre(win);
     //Ajout_livre(win);
     //modifier_profile_utilisateur (win);
     //Details_Livre(win);
     /* interface_admin_globale(win);
      interface_admin_gerer_emprunts(win);
      interface_utilisateur_globale(win) */
    gtk_main ();
    return 0;
}
