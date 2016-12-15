#ifndef USER_FUNCTIONS_H_INCLUDED
#define USER_FUNCTIONS_H_INCLUDED
#include "user_structus.h"
//connect to dataabse ***********


typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;




int login(char * email , char * pwd);
int Nombre_utilisateurs_Totale ();
int  supprimer_utilisateur(int id_utli);
//int inscrire( Utilisateur* utili )
int Nb_emprunts_En_Cours(int iduser) ;
liste_Emprunts_Utilisateurs_En_Cours(int idUser,struct Emprunt liste_emprunts[]);
struct Livre *GetLivre(int idLivre);
int Getsession();

void Creer_Emprunt(Emprunt* emp);
//struct  Livre *Rechercher_livre_ISBN(char * ISBN)

#endif // USER_FUNCTIONS_H_INCLUDED
