#include <stdlib.h>
#include <gtk/gtk.h>
#include "user_structus.h"
#include <mysql/mysql.h>


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

//interface_admin_gerer_emprunts(win);

//printf("le nombre d'emprutns en cours est %d \n",x);

 //liste_Emprunts_Utilisateurs_En_Cours(1,liste_emprunts);

  //liste_Emprunts_en_attente(liste_emprunts);

//interface_admin_emprunt_retard(win);


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





/*int bah =confirmer_emprunt(emp);

printf("bah est %d \n", bah);*/

//interface_admin_gerer_emprunts(win);




Emprunt *emp  = (Emprunt *)malloc(sizeof(Emprunt));
emp->Livre_id_livre=2;
emp->Utilisateur_id_utilisateur=28;
//int resss = Creer_Emprunt(emp);




//statistiques(win);
//printf("teh result of emprutnest %d \n",bah);

//user = getCurrentUser(1);
//printf("we are here \n");
//printf(" teh suer is %s \n ",user->email);

/*Livre *book  = (Livre *)malloc(sizeof(Livre));
strcpy( book->Titre,"Book Test");
strcpy( book->Auteur,"Auteur Test");
strcpy( book->maison_edition,"Darna");
strcpy( book->categorie,"test");
strcpy( book->ISBN_livre,"04299933");
 book->nb_examplaires_disponibles=3;
// float fprix = atof(prix);
 book->prix=1500.0;

 int res = Ajouter_livre(book);
//printf("the res est %d \n", res);

//int result = Modifier_livre(book);*/

//printf("resulr o modiying est %d \n",result);
//printf("we are here %s \n",book->Titre);




//details_livre(win);

 //interface_admin_gerer_livres(win);
 //admin_modifier_livre(win);

//printf("test svp e5dheem %s  \n",liste_books[0].Titre);

//dialog_erreur_login(win);

//Interface_utilisateur_liste_emprunts(win);
//interface_utilisateur_globale(win);
//interface_admin_globale(win);



//interface_utilisateur_emprunter_livre(win,2);
//interface_admin_gerer_emprunts(win);
login_interface(win);
 //interface_admin_gerer_emprunts(win);
//admin_modifier_livre(win,2);
//GetLivre(2);

//details_User(win,21);
//interface_supprimer_livre(win,2);






//interface_supprimer_livre(win);
 //Details_Livre(win,1);


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
