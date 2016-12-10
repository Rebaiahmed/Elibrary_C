#ifndef USER_INTRFACES_H_INCLUDED
#define USER_INTRFACES_H_INCLUDED




//login****************************//
void interface_utilisateur_globale (GtkWidget *window);
void login_interface (GtkWidget *window);
void inscrire_interface (GtkWidget *window);
void modifier_profile_utilisateur (GtkWidget *window);
void Details_Livre (GtkWidget *window) ;

void Interface_utilisateur_liste_emprunts(GtkWidget *window);
//void interface_utilisateur_globale(GtkWidget *window);




//***********************************************//
void dialog_erreur_login( gpointer window);
void dialog_erreur_inscrire_donnees( gpointer window);
void dialog_erreur_inscrire_login( gpointer window);
 void dialog_succees(GtkWidget *widget, gpointer window);
 void dialog_erreur_login_vides( gpointer window);
void dialog_succes_modification( gpointer window);
void dialog_succes_ajout( gpointer window);
void dialog_erreur( gpointer window);



//****** ADMIN INTERFACES *************//
void Modifier_Livre(GtkWidget *window);
void Ajout_livre(GtkWidget *window);
void statistiques(GtkWidget *window);
void interface_admin_globale (GtkWidget *window);
void interface_admin_gerer_emprunts (GtkWidget *window);
//void interface_admin_gerer_livres( GtkWidget *window);
 void details_livre (GtkWidget *win,int idLivre);
 void admin_modifier_livre(GtkWidget *window,int idLivre);
 void interface_admin_gerer_Utilisateurs( GtkWidget *window);

#endif // USER_INTRFACES_H_INCLUDED
