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
     int  nb_emprunts;
       char  num_tel[50];
        char  Num_Cin[50];
char  login[50];


};



struct Emprunt
{

 int idEmprunt;

 char  date_emprunt[50];
  char  date_retour[50];

    char  etat[50];
    int Utilisateur_id_utilisateur ;
    int Livre_id_livre ;



};

struct Livre
{

 int id_livre;

 char  Titre[50];
  char  Auteur[50];
   char  maison_edition[50];
   char categorie[50];
   char ISBN_livre[50];
   float prix ;
    int nb_emprunts ;
    int nb_examplaires_disponibles ;
    int Livre_id_livre ;



};

#endif // USER_STRUCTUS_H_INCLUDED
