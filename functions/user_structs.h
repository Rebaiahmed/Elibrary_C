#ifndef USER_STRUCTUS_H_INCLUDED
#define USER_STRUCTUS_H_INCLUDED

struct Utilisateur
{

 int id_utilisateur;

 char  Nom[50];
  char  Prenom[50];
   char  email[50];
    char  mot_passe[50];
     char  adresse[50];
      char  nb_emprunts[50];
       char  num_tel[50];
        char  Num_Cin[50];



};



struct Emprunt
{

 int 	idEmprunt;

 char  date_emprunt[50];
  char  date_retour[50];
   char  	etat[50];


int Utilisateur_id_utilisateur ;
int 	Livre_id_livre ;

};



struct Livre
{

 int 		id_livre;

 char  	Auteur[50];
  char  maison_edition[50];
   char  	prix[50];
    char  	categorie[50];

    char  	ISBN_livre[50];
int 	nb_emprunts ;
int nb_examplaires_disponibles ;

};

#endif // USER_STRUCTUS_H_INCLUDED
