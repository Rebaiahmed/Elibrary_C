#ifndef USER_INTRFACES_H_INCLUDED
#define USER_INTRFACES_H_INCLUDED

//login****************************//
//void interface_utilisateur_globale (GtkWidget *window);
void login_interface (GtkWidget *window)
void inscrire_interface (GtkWidget *window);
void modifier_profile_utilisateur (GtkWidget *window);
void Details_Livre (GtkWidget *window) ;
void interface_utilisateur_globale(GtkWidget *window);

//****** ADMIN INTERFACES *************//
void Modifier_Livre(GtkWidget *window);
void Ajout_livre(GtkWidget *window);
void statistiques(GtkWidget *window);
void interface_admin_globale (GtkWidget *window);
void interface_admin_gerer_emprunts (GtkWidget *window);

#endif // USER_INTRFACES_H_INCLUDED
