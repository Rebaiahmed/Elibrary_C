#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include <regex.h>
#include "connect_database.h"
#include "../user_structus.h"


//**************************Défenir nos fonctions ici *************************//

typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;


void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void Connectdb(MYSQL *con){

printf("connectDb \n");
    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "root",
          "ELIBRARY", 0, NULL, 0) == NULL)
    {
    printf("hehhehhehehhehe");
      finish_with_error(con);
    }
}


//*************************************//

void rooting_interface(int x)
{
 GtkWidget *win = NULL;

 printf("we are here in rooting interface \n");
if(x==0)
{
interface_admin_globale(win);
}else{
interface_utilisateur_globale(win);
}

}

//********************************************//




int inscrire( Utilisateur* utili )
{

int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
  char query1[350];
//Nous devons vérifier pour le login



 sprintf(query1,"select * from Utilisateur where login='%s'",utili->login);
mysql_query(con,query1);
MYSQL_RES *result = mysql_use_result(con);
MYSQL_ROW row=mysql_fetch_row(result);
printf("the row mthode is %d \n",row==NULL);



if(row==NULL)

{

printf("we are here \n");
  sprintf(querry,"insert into Utilisateur Values('%d','%s','%s','%s','%s','%s','%d','%s','%s','%s','%d');",
    NULL,utili->Nom,utili->Prenom,utili->login,utili->email,utili->mot_passe,utili->adresse,0,utili->num_tel,utili->Num_Cin,0);

res = mysql_query(con, querry);
printf("the result %d \n", res);

int id = mysql_insert_id(con);

printf("The last inserted row id is: %d\n", id);

SaveUser(id);




}else
{
printf("login déja utilisée \n");
res = -1 ;
}





    mysql_close(con);
return res ;

}


//******************************************//


int login(char * log , char * pass)
{
  MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    int res = 0;
    unsigned int i = 0;
    unsigned int num_champs = 0;


char query[300];

sprintf(query,"select * from Utilisateur where login='%s' and mot_passe ='%s'",log,pass);
mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);
MYSQL_ROW row=mysql_fetch_row(result);
printf("we are here 3 %s \n",row);
if(row==NULL)
{

printf("Result NULL \n");
res = -1 ;
}else{
printf("row are %s %s %s %s %s %s %s %s %s %s %s %s \n",row[0],row[1],row[2],row[3],row[4],row[5],row[6],row[7],row[8],row[9],row[10],row[11],row[12]);
num_champs = mysql_num_fields(result);

printf("row 12 est %s \n",row[0]);
//sauvegarder l'utilisateur
SaveUser(atoi(row[0]));
int a = Getsession();

printf("the id User i %d \n",a);
res = atoi(row[10]) ;

//on va retourner structure User
//****SaveUser()
printf("res  %d ",res);

}



    mysql_free_result(result);
    mysql_close(con);

return res;
}



//*********************************************//
void Creer_Emprunt(Emprunt* emp)
{
int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"insert into Emprunt Values(NULL,'%s','%s','%s','%d','%d');",
    emp->date_emprunt, emp->date_retour,emp->etat,emp->Utilisateur_id_utilisateur,emp->Livre_id_livre);

    res = mysql_query(con, querry);


mysql_close(con);

return res ;

}


void deconnecter(GtkWidget *win,gpointer p)
{
//ici on va excuter le button hide interface utlisateur et afficher interface login
 gtk_widget_hide(p);
    gtk_widget_hide(win);
 login_interface(win);
}



int Modifier_Profile(Utilisateur* utili)
{
 int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"update Utilisateur set Nom='%s',Prenom='%s',login='%s',email='%s',mot_passe='%s',adresse='%s',Num_Cin='%s') where id_utilisateur = %d ;",
    utili->Nom,utili->Prenom,utili->login,utili->email,utili->mot_passe,utili->Num_Cin,utili->id_utilisateur);

 res = mysql_query(querry,con);
mysql_close(con);

return res ;
}

//*************************SaveUser*******************************//



//*****************GetCurrentUser******************//

struct Utilisateur  *getLoggedUser(char *titre)
{
 Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));
 return user ;

}



//*****************************Rechercher Livre Titre*********************//
struct Livre  *Rechercher_livre_Titre(char *titre)
{
 Livre *book  = (Livre *)malloc(sizeof(Livre));
 return book ;

}



struct Livre *Rechercher_livre_Auteur(char *auteur)
{

 Livre *book  = (Livre *)malloc(sizeof(Livre));
 return book ;
}



/*struct  Livre *Rechercher_livre_ISBN(char * ISBN)
{
  MYSQL *con = mysql_init(NULL);
    Connectdb(con);
      Livre *book  = (Livre *)malloc(sizeof(Livre));

    char querry[100];
    sprintf(querry,"%s","SELECT * FROM Livre WHERE ISBN_livre='",ISBN,"';");


    mysql_query(con,querry);
    MYSQL_RES *result = mysql_store_result(con);


    if (result == NULL)
    {
        finish_with_error(con);
        book = NULL ;
    }else
    {
MYSQL_ROW row=mysql_fetch_row(result);


printf("value of res %d \n ",res);
printf("value of row %s %s %s  \n ",row[0],row[1],row[8]);




strcpy( book->Titre,row[0]);
strcpy( book->Auteur,row[1]);
strcpy( book->maison_edition,row[2]);
book->prix = row[3];
book->nb_emprunts=row[4];
book->nb_examplaires_disponibles=row[5];
strcpy( book->categorie,row[3]);
strcpy( book->ISBN_livre,row[4]);


    }



    mysql_free_result(result);
    mysql_close(con);

return book;
}*/




//****fonction pour retourner la liste des emprunts


/*
liste des emprunts de lutilisateur courant************
*/


int Nb_emprunts_En_Cours(int iduser)
{


MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
    Connectdb(con);
  int nb_emprunts
=0;

    char query[300];

 sprintf(query,"select * from Emprunt  where Utilisateur_id_utilisateur='%d'",iduser);


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);

 while ((row = mysql_fetch_row(result)))
        {
            nb_emprunts ++ ;
        }
mysql_close(con);
return nb_emprunts  ;
}






void liste_Emprunts_Utilisateurs_En_Cours(int idUser,struct Emprunt liste_emprunts[])
{
MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
    Connectdb(con);
  //int nb_emprunts=0;

//***********Récupere le nombre des empru ts de cette utilisateur***************//

int nb =   Nb_emprunts_En_Cours(idUser);
//struct Emprunt liste_emprunts[nb];
int i =0;


    char query[300];

 sprintf(query,"select * from Emprunt  where Utilisateur_id_utilisateur='%d'",idUser);


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);
 struct Emprunt *emp = malloc(sizeof *emp);

 while ((row = mysql_fetch_row(result)))
        {
                 printf("row est %s ,%s ,%s ,%s ,%s ,%s \n",row[0],row[1],row[2],row[3],row[4],row[5]);
                 //liste_emprunts[i]= row;


liste_emprunts[i].idEmprunt=row[0];
//char c2[100];
//strcpy(c2,row[1]);
//liste_emprunts[i].date_emprunt = *c2 ;
strcpy(liste_emprunts[i].date_emprunt,row[1]);
strcpy(liste_emprunts[i].date_retour,row[2]);
strcpy(liste_emprunts[i].etat,row[3]);
liste_emprunts[i].Utilisateur_id_utilisateur=row[4];
liste_emprunts[i].Livre_id_livre=row[5];

i++ ;
printf(" i will be %d \n", i);
        }


      // printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);

mysql_close(con);

}




int Getsession(){
    int id;
    FILE *fichier;
    fichier = fopen("session/user.txt", "r");
    fscanf(fichier, "%d", &id);
    return id;
}

void SaveUser(int idUser)
{
FILE *fichier;
    fichier = fopen("session/user.txt", "w");
    fprintf(fichier, "%d", idUser);
fclose(fichier);
}


//**************************GetCurrentUser******************************//

struct Utilisateur *getCurrentUser(int idUser)
{

 Utilisateur *user  = (Utilisateur *)malloc(sizeof(Utilisateur));
   MYSQL *con = mysql_init(NULL);
    Connectdb(con);
char query[300];

sprintf(query,"select * from Utilisateur where id_utilisateur='%d'",idUser);

mysql_query(con,query);

MYSQL_RES *result = mysql_store_result(con);
MYSQL_ROW row=mysql_fetch_row(result);

if(row==NULL)
{
user = NULL ;
}else{

printf("we are here niggah %s %s  \n",row[0],row[1]);
user->id_utilisateur = atoi(row[0]);

strcpy(user->Nom,row[1]);
printf("we are here niggah %s   \n",user->Nom);
strcpy(user->Prenom,row[2]);
strcpy(user->login,row[3]);
strcpy(user->email,row[4]);
strcpy(user->mot_passe,row[5]);
strcpy(user->adresse,row[6]);
user->nb_emprunts = atoi(row[7]);
strcpy(user->Num_Cin,row[8]);

strcpy(user->num_tel,row[9]);

}



    mysql_free_result(result);
    mysql_close(con);



 return user ;
}



//***************Valider la liste des données entrées par l'utilisateur


int check_Num_Cin(char * Numcin)
{


return 0;
}


int check_Telephone(char * Numcin)
{


return 0;
}




