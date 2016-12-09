#ifndef USER_FUNCTIONS_H_INCLUDED
#define USER_FUNCTIONS_H_INCLUDED
#include "user_structus.h"
//connect to dataabse ***********





int login(char * email , char * pwd);
int Nombre_utilisateurs_Totale ();
int  supprimer_utilisateur(int id_utli);
//int inscrire( Utilisateur* utili )
int Nb_emprunts_En_Cours(int iduser) ;
void liste_Emprunts_Utilisateurs_En_Cours(int idUser);


//struct  Livre *Rechercher_livre_ISBN(char * ISBN)

#endif // USER_FUNCTIONS_H_INCLUDED
