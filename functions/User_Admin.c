#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include <regex.h>
#include "connect_database.h"
#include "../user_structus.h"


typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;




MYSQL *con ;

void confirmer_emprunt (Emprunt* emp)
{


int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query1[50];
    char query2[350];
    char query3[350];
    char query4[350];
   char query5[350];

   char *p = "hello";


//ajouter date_emprutn new date
  sprintf(query1,"%s%d","update Emprunt SET etat='confirmee' ,`date_emprunt`=NOW() ,date_retour =DATE_ADD(date_emprunt, INTERVAL 15 DAY) WHERE idEmprunt=",emp->idEmprunt,";");


  if (mysql_query(con,query1))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      //exit(1);
  }
  else{
    printf("lemprunt est effectuee \n");
    printf("we are here \n");
      //incrementer le nombre d'emprunt de cette utilisateur

 //incrementer le nombre d'emprunts de l'utilisateur

 sprintf(query3,"%s%d","update Utilisateur set nb_emprunts=nb_emprunts+1 WHERE id_utilisateur=",emp->Utilisateur_id_utilisateur,";");

int  res_user = mysql_query(con, query3);



  if(mysql_query(con,query3))
    {
       finish_with_error(con);
    }



    //incrementer le nombre d'emprunts du livre

// sprintf(query1,"%s%d","update Utilisateur set nb_emprunts=nb_emprunts+1 WHERE id_utilisateur=",emp->Utilisateur_id_utilisateur,";");
 sprintf(query4,"%s%d","update Livre set nb_emprunts=nb_emprunts+1 where id_livre=", emp->Livre_id_livre,";");

    int res_livre =0;
 res_livre = mysql_query(con, query4);


  if(mysql_query(con,query4))
    {
       finish_with_error(con);
    }

  }







 //********************************************************/


    res = 1;


return res ;
}

//***************************************//



int Nombre_utilisateurs_Totale ()
{
MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"SELECT * FROM Utilisateur");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

     MYSQL_RES *result = mysql_store_result(con);

       MYSQL_ROW row;

        int i = 0;

        while ((row = mysql_fetch_row(result)))

        {
           i++;
        }


    mysql_free_result(result);
//finish_with_error(con);

return i;

}


//************************************//

int Nombre_Emprunts_Totale ()
{
MYSQL *con =
mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"SELECT * FROM Emprunt");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

     MYSQL_RES *result = mysql_store_result(con);

       MYSQL_ROW row;

        int i = 0;

        while ((row = mysql_fetch_row(result)))

        {
           i++;
        }


    mysql_free_result(result);
//finish_with_error(con);

return i;

}

//*****************************************************************************//










//************************************//

int Nombre_Emprunts_EnCours ()
{
MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"SELECT * FROM Emprunt where etat='en_cours'");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

     MYSQL_RES *result = mysql_store_result(con);

       MYSQL_ROW row;

        int i = 0;

        while ((row = mysql_fetch_row(result)))

        {
           i++;
        }


    mysql_free_result(result);
//finish_with_error(con);

return i;

}
//**********************************************************


int Nombre_Emprunts_attente ()
{
MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"SELECT * FROM Emprunt where etat='en_attente'");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

     MYSQL_RES *result = mysql_store_result(con);

       MYSQL_ROW row;

        int i = 0;

        while ((row = mysql_fetch_row(result)))

        {
           i++;
        }


    mysql_free_result(result);
//finish_with_error(con);

return i;

}












//************************************//

int Nombre_Emprunts_En_Reatrd ()
{
MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"SELECT * FROM Emprunt where etat='en_attente'");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

     MYSQL_RES *result = mysql_store_result(con);

       MYSQL_ROW row;

        int i = 0;

        while ((row = mysql_fetch_row(result)))

        {
           i++;
        }


    mysql_free_result(result);
//finish_with_error(con);

return i;


}

//************************************//

int Nombre_Livres_Totale ()
{

MYSQL *con = mysql_init(NULL);
    Connectdb(con);

    char querry[100];
    sprintf(querry,"SELECT * FROM Livre");


    if (mysql_query(con,querry))
    {
      finish_with_error(con);
    }

     MYSQL_RES *result = mysql_store_result(con);

       MYSQL_ROW row;

        int i = 0;

        while ((row = mysql_fetch_row(result)))

        {
           i++;
        }


    mysql_free_result(result);
//finish_with_error(con);

return i;

}




int  supprimer_utilisateur(int id_utli)
{
int res =  0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
     char query1[100];


     printf("we are here to delete user \n");


    sprintf(query1,"SELECT * FROM Emprunt WHERE Utilisateur_id_utilisateur=%d",id_utli);

     if (mysql_query(con, query1)) {
     finish_with_error(con);
     }
     // finish_with_error(con);
MYSQL_RES *result = NULL;
result = mysql_use_result(con);
 MYSQL_ROW row;
row = mysql_fetch_row(result);



     if(row!=NULL)
     {

     //il ya des emprutns déja en cours donc pas de suppression
     res = -1 ;

     }else{

     printf("we will delte user \n");
       sprintf(querry,"delete from Utilisateur where id_utilisateur=%d",id_utli);


       //*******************************************//
           if (mysql_query(con, querry)) {
      finish_with_error(con);
             }
       //****************************************//
             res = 1;
           mysql_close(con);


}



return res ;

}








//******************************************************//

int supprimer_livre(int id_livre)
{


int res =  0;
MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query[100];
     char query1[100];
    sprintf(query1,"SELECT * FROM Emprunt WHERE Livre_id_livre=%d",id_livre);
  MYSQL_RES *result = NULL;
  MYSQL_ROW row;


 if (mysql_query(con, query1)) {
  finish_with_error(con);
 }
     // finish_with_error(con);
     result = mysql_use_result(con);
  row = mysql_fetch_row(result);
 printf("we %d \n", row==NULL);

     if(row!=NULL)
     {

     //il ya des emprutns déja en cours donc pas de suppression
     res = -1 ;

     }
     else{

     printf("suprimer le livre \n");
      sprintf(query,"delete from Livre where id_livre =%d ",id_livre);

       if (mysql_query(con, query)) {
      finish_with_error(con);
     }
res = 1;
//mysql_close(con);

     }




//finish_with_error(con);

return res ;

}




//********************************************//

int  Modifier_livre(Livre * book)
{
int res;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query[350];
    sprintf(query,"update Livre set Titre='%s',Auteur='%s',maison_edition='%s',prix=%f,nb_examplaires_disponibles= %d,categorie='%s'  where id_livre = %d;",
    book->Titre,book->Auteur,book->maison_edition,book->prix,book->nb_examplaires_disponibles,book->categorie,book->id_livre);


   if (mysql_query(con, query)) {
      finish_with_error(con);
      res = -1;
    }else{
        res = 1;
}
 printf("we are here to modify bok %d  \n", res);
return res ;
}





//*****une fonction pour Modife un livre les livres***********//
int  Ajouter_livre(Livre* book )
{

int res=0;


    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query[350];


    printf("the book will be added is  %s  \n",book->Titre);
    /*
     sprintf(querry,"insert into Utilisateur Values('%d','%s','%s','%s','%s','%s','%d','%s','%s','%s','%d');",
    NULL,utili->Nom,utili->Prenom,utili->login,utili->email,utili->mot_passe,utili->adresse,0,utili->num_tel,utili->Num_Cin,0);*/

    sprintf(query,"INSERT INTO `Livre` Values('%d','%s','%s','%s','%f','%d','%d','%s','%s');",
    NULL,book->Titre,book->Auteur,book->maison_edition,book->prix,0,book->nb_examplaires_disponibles,book->categorie,book->ISBN_livre);


   if (mysql_query(con, query)) {
      finish_with_error(con);
      res = -1;
    }else{
        res = 1;
    }
mysql_close(con);

return res ;

}









//*****************************une méthode pour voir la liste des Utilisateurs**********************//

void  Liste_Utilisateurs(struct Utilisateur liste_users[]){

MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
Connectdb(con);
int i =0;


    char query[300];

 sprintf(query,"select * FROM Utilisateur");


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);


 while ((row = mysql_fetch_row(result)))
        {
                 printf("row est %s ,%s , %s \n",row[0],row[1],row[2],row[3]);
                 //liste_emprunts[i]= row;


liste_users[i].id_utilisateur= (int)row[0];
strcpy(liste_users[i].Nom,row[1]);
strcpy(liste_users[i].Prenom,row[2]);
strcpy(liste_users[i].Num_Cin,row[3]);
strcpy(liste_users[i].adresse,row[4]);
strcpy(liste_users[i].num_tel,row[5]);
strcpy(liste_users[i].email,row[7]);
i++ ;

        }


      // printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);

//finish_with_error(con);

}




//****************Procedure pour retourner la liste des livres (tous)*****************************//

void liste_Livres(struct Livre liste_Livres[])
{
MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
Connectdb(con);
int i =0;


    char query[300];

 sprintf(query,"select * FROM Livre");


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);


 while ((row = mysql_fetch_row(result)))
        {
                 printf("row est %s ,%s , %s \n",row[0],row[1],row[2],row[3]);
                 //liste_emprunts[i]= row;


liste_Livres[i].id_livre= (int)row[0];
strcpy(liste_Livres[i].Titre,row[1]);
//printf("le titre sera  %s \n",liste_Livres[i].Titre);
strcpy(liste_Livres[i].Auteur,row[2]);
//printf("l'auteur sera  %s \n",liste_Livres[i].Auteur);
strcpy(liste_Livres[i].maison_edition,row[3]);
//printf("l'maison edition sera  %s \n",liste_Livres[i].maison_edition);
liste_Livres[i].prix= atof(row[4]);
//printf(" prix  %f \n",liste_Livres[i].prix);
liste_Livres[i].nb_emprunts= atoi(row[5]);
//printf(" nb emprunts %d \n",liste_Livres[i].nb_emprunts);
liste_Livres[i].nb_examplaires_disponibles=atoi(row[6]);
//printf(" nb exmplaires dipsonibles %d \n",liste_Livres[i].nb_examplaires_disponibles);
strcpy(liste_Livres[i].categorie,row[7]);
//printf(" categorie %s \n",liste_Livres[i].categorie);
strcpy(liste_Livres[i].ISBN_livre,row[8]);
//printf(" isbne est  %s \n",liste_Livres[i].ISBN_livre);
i++ ;

        }


      // printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);

//finish_with_error(con);

}



//***************fonction pour récupere le livre via id

struct Livre *GetLivre(int idLivre)
{

  MYSQL *con = mysql_init(NULL);
    Connectdb(con);
      Livre *book  = (Livre *)malloc(sizeof(Livre));

    char querry[100];
    sprintf(querry,"SELECT * FROM Livre WHERE 	id_livre='%d'", idLivre);

    mysql_query(con,querry);

    MYSQL_RES *result = mysql_store_result(con);


    if (result == NULL)
    {

        book = NULL ;
    }else
    {

MYSQL_ROW row=mysql_fetch_row(result);







book->id_livre= atoi(row[0]);


strcpy( book->Titre,row[1]);
strcpy( book->Auteur,row[2]);
strcpy( book->maison_edition,row[3]);
book->prix = atof(row[4]);
book->nb_emprunts=atoi(row[5]);
book->nb_examplaires_disponibles=atoi(row[6]);
strcpy( book->categorie,row[7]);
strcpy( book->ISBN_livre,row[8]);


printf("value of res  %s  \n ",book->Titre);

    }



    mysql_free_result(result);
//finish_with_error(con);
    return book;
}


//***************************************************//

int refuser_emprunt(int idEmprunt)
{


    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    int res = 0 ;

     char query1[100];


     printf("supprimer emprunt  \n");


    sprintf(query1,"delete from Emprunt where 	idEmprunt=%d",idEmprunt);


    int dd = mysql_query(con, query1);


     if (mysql_query(con, query1)) {
     finish_with_error(con);
     }
     // finish_with_error(con);

  MYSQL_RES *result ;
     result = mysql_use_result(con);

 printf("we %s \n",  result);

res = 1;


return res ;


}


//*********************************************************//


struct Emprunt *GetEmprunt(int id_emprunt)
{

  MYSQL *con = mysql_init(NULL);
    Connectdb(con);
      Emprunt *emp  = (Emprunt *)malloc(sizeof(Emprunt));

    char querry[100];
    sprintf(querry,"SELECT * FROM Emprunt WHERE idEmprunt='%d'",id_emprunt);

    mysql_query(con,querry);

    MYSQL_RES *result = mysql_store_result(con);


    if (result == NULL)
    {

   emp = NULL ;
    }else
    {

MYSQL_ROW row=mysql_fetch_row(result);


emp->idEmprunt =atoi(row[0]);
strcpy(emp->date_emprunt,row[1]);
strcpy(emp->date_retour,row[2]);
emp->Utilisateur_id_utilisateur = atoi(row[3]);
emp->Livre_id_livre = atoi(row[4]);

    }



    mysql_free_result(result);
//finish_with_error(con);
    return emp;
}




//*****************************************************************************//


void liste_Emprunts_en_attente(struct Emprunt liste_emprunts[])
{
MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
    Connectdb(con);
  //int nb_emprunts=0;

//***********Récupere le nombre des empru ts de cette utilisateur***************//

int nb =  Nombre_Emprunts_attente();
//struct Emprunt liste_emprunts[nb];
int i =0;


    char query[300];

 sprintf(query,"select * from Emprunt  where etat='en_attente' ");


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);
 struct Emprunt *emp = malloc(sizeof *emp);

 while ((row = mysql_fetch_row(result)))
        {

                 //liste_emprunts[i]= row;


liste_emprunts[i].idEmprunt= atoi(row[0]);
  printf("admin  %d \n",liste_emprunts[i].idEmprunt);
//char c2[100];
//strcpy(c2,row[1]);
//liste_emprunts[i].date_emprunt = *c2 ;
strcpy(liste_emprunts[i].date_emprunt,row[1]);
strcpy(liste_emprunts[i].date_retour,row[2]);
strcpy(liste_emprunts[i].etat,row[3]);
liste_emprunts[i].Utilisateur_id_utilisateur= atoi(row[4]);
liste_emprunts[i].Livre_id_livre= atoi(row[5]);

        }


      // printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);

mysql_close(con);

}




//****************************************************//

void liste_Emprunts_en_cours(struct Emprunt liste_emprunts[])
{
MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
    Connectdb(con);
  //int nb_emprunts=0;

//***********Récupere le nombre des empru ts de cette utilisateur***************//

int nb =  Nombre_Emprunts_attente();
//struct Emprunt liste_emprunts[nb];
int i =0;


    char query[300];

 sprintf(query,"select * from Emprunt  where etat='en_cours' ");


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);
 struct Emprunt *emp = malloc(sizeof *emp);

 while ((row = mysql_fetch_row(result)))
        {

                 //liste_emprunts[i]= row;


liste_emprunts[i].idEmprunt= atoi(row[0]);
  printf("admin  %d \n",liste_emprunts[i].idEmprunt);
//char c2[100];
//strcpy(c2,row[1]);
//liste_emprunts[i].date_emprunt = *c2 ;
strcpy(liste_emprunts[i].date_emprunt,row[1]);
strcpy(liste_emprunts[i].date_retour,row[2]);
strcpy(liste_emprunts[i].etat,row[3]);
liste_emprunts[i].Utilisateur_id_utilisateur= atoi(row[4]);
liste_emprunts[i].Livre_id_livre= atoi(row[5]);

        }


      // printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);

mysql_close(con);

}









//****************************************************//

void liste_Emprunts_en_retard(struct Emprunt liste_emprunts[])
{
MYSQL *con = mysql_init(NULL);
MYSQL_ROW row;
    Connectdb(con);
  //int nb_emprunts=0;

//***********Récupere le nombre des empru ts de cette utilisateur***************//

int nb =  Nombre_Emprunts_attente();
//struct Emprunt liste_emprunts[nb];
int i =0;


    char query[300];

 sprintf(query,"select * from Emprunt  where etat='en_cours' ");


mysql_query(con,query);
MYSQL_RES *result = mysql_store_result(con);
 struct Emprunt *emp = malloc(sizeof *emp);

 while ((row = mysql_fetch_row(result)))
        {

                 //liste_emprunts[i]= row;


liste_emprunts[i].idEmprunt= atoi(row[0]);
  printf("admin  %d \n",liste_emprunts[i].idEmprunt);
//char c2[100];
//strcpy(c2,row[1]);
//liste_emprunts[i].date_emprunt = *c2 ;
strcpy(liste_emprunts[i].date_emprunt,row[1]);
strcpy(liste_emprunts[i].date_retour,row[2]);
strcpy(liste_emprunts[i].etat,row[3]);
liste_emprunts[i].Utilisateur_id_utilisateur= atoi(row[4]);
liste_emprunts[i].Livre_id_livre= atoi(row[5]);

        }


      // printf("test svp e5dheem %s   \n",liste_emprunts[0].date_emprunt);

mysql_close(con);

}


