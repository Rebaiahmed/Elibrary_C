#ifndef USER_INTRFACES_H_INCLUDED
#define USER_INTRFACES_H_INCLUDED
#include "user_structus.h"


typedef struct Livre Livre;
//login****************************//

void interface_utilisateur_globale(GtkWidget *window,struct Livre liste_Livres[]);
void login_interface (GtkWidget *window);
void inscrire_interface (GtkWidget *window);
void modifier_profile_utilisateur (GtkWidget *window);
void Interface_utilisateur_liste_emprunts(GtkWidget *window);
void interface_utilisateur_emprunter_livre(GtkWidget *window,int idLivre);
//void interface_utilisateur_globale(GtkWidget *window);
void Details_Livre(GtkWidget *window,int idLivre);



//***********************************************//
void dialog_erreur_login( gpointer window);
void dialog_erreur_inscrire_donnees( gpointer window);
void dialog_erreur_inscrire_login( gpointer window);
 void dialog_succees(GtkWidget *widget, gpointer window);
 void dialog_erreur_login_vides( gpointer window);
void dialog_succes_modification( gpointer window);
void dialog_succes_ajout( gpointer window);
void dialog_erreur( gpointer window);
void dialog_erreur_donnees_livre( gpointer window);
void dialog_erreur_suppression( gpointer window);
void dialog_succes_suppression( gpointer window);
void dialog_erreur_suppression_user( gpointer window);
void dialog_succes_valider_emprunt( gpointer window);
void dialog_succes_emprunter( gpointer window);

//****** ADMIN INTERFACES *************//
void Modifier_Livre(GtkWidget *window);
void Ajout_livre(GtkWidget *window);
void statistiques(GtkWidget *window);
void interface_admin_globale (GtkWidget *window);
void interface_admin_gerer_emprunts (GtkWidget *window);
//void interface_admin_gerer_livres( GtkWidget *window);
 void details_livre (GtkWidget *win,int idLivre);
 void admin_modifier_livre(GtkWidget *window,int idLivre);
 void admin_modifier_utilisateur(GtkWidget *window,int idUser);
void interface_supprimer_livre(  GtkWidget *window,int idlivre);

void interface_admin_emprunt_retard (GtkWidget *window);

void interface_admin_emprunt_cours (GtkWidget *window);

//*****************************************************//
void admin_details_utilisateur(GtkWidget *window,int idUtilisateur);
void interface_admin_gerer_Utilisateurs( GtkWidget *window);
void details_User ( GtkWidget *win,int idUser);


#endif // USER_INTRFACES_H_INCLUDED
