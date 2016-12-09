#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "connect_database.h"
#include "../user_structus.h"


typedef struct Utilisateur Utilisateur;
typedef struct Emprunt Emprunt;
typedef struct Livre Livre;


void confirmer_emprunt (Emprunt* emp)
{
int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query1[350];
    char query2[350];
    char query3[350];
    char query4[350];

    sprintf(query1,"update Emprunt set etat='confirmee' where idEmprunt = %d ;",
    emp->idEmprunt);
    int x1 = mysql_query(query1,con);


    if(x1!=-1)
    {
      //incrementer le nombre d'emprunt de cette utilisateur
sprintf(query2,"select * from Utilisateur where id_utilisateur='%d' ",emp->Utilisateur_id_utilisateur);
mysql_query(con,query2);
MYSQL_RES *result_user = mysql_store_result(con);
MYSQL_ROW row_user=mysql_fetch_row(result_user);

if(row_user !=NULL)
{
 sprintf(query3,"update Utilisateur set nb_emprunts=nb_emprunts+1  where id_utilisateur = %d ;",
   emp->Utilisateur_id_utilisateur);
     mysql_query(con,query3);
}


//**********************Méme opération pour le livre incrementer le nombre d'emprunts*****************//
sprintf(query4,"select * from Utilisateur where id_utilisateur='%d' ",emp->Utilisateur_id_utilisateur);
mysql_query(con,query2);
MYSQL_RES *result_livre = mysql_store_result(con);
MYSQL_ROW row_livre=mysql_fetch_row(result_livre);

if(row_livre !=NULL)
{
 sprintf(query4,"update Livre set nb_emprunts=nb_emprunts+1  where id_utilisateur = %d ;",
   emp->Livre_id_livre);
     mysql_query(con,query4);
}


}





mysql_close(con);

return res ;
}



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
    mysql_close(con);

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
    mysql_close(con);

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
    mysql_close(con);

return i;

}


//************************************//

int Nombre_Emprunts_En_Reatrd ()
{
//ici connecter a la base de données et retourner le nombre d'utilisateurs
return 0 ;


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
    mysql_close(con);

return i;

}




int  supprimer_utilisateur(int id_utli)
{
int res =  0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
     char query1[100];
    sprintf(query1,"SELECT * FROM Emprunt WHERE Utilisateur_id_utilisateur='",id_utli,"';");
  MYSQL_RES *result = NULL;
 if (mysql_query(con, query1)) {
     // finish_with_error(con);
     result = mysql_use_result(con);

     printf("hello result  %s \n",result);

     if(result!=NULL)
     {
     //il ya des emprutns déja en cours donc pas de suppression
     res = -1 ;

     }else{

       sprintf(querry,"deletre from Utilisateur where 	id_utilisateur=%d",id_utli,";");
    if (mysql_query(con, querry)) {
      finish_with_error(con);
      res = 1;
     }
     }
}




mysql_close(con);

return res ;

}








//******************************************************//

int supprimer_livre(int id_livre)
{
int res =  0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[100];
     char query1[100];
    sprintf(query1,"SELECT * FROM Emprunt WHERE Livre_id_livre='",id_livre,"';");
  MYSQL_RES *result = NULL;
 if (mysql_query(con, query1)) {
     // finish_with_error(con);
     result = mysql_use_result(con);

     printf("hello result  %s \n",result);

     if(result!=NULL)
     {
     //il ya des emprutns déja en cours donc pas de suppression
     res = -1 ;

     }else{

       sprintf(querry,"deletre from Livre where id_livre=%d",id_livre,"");

   res = mysql_query(querry,con);

     }
}




mysql_close(con);

return res ;

}




//********************************************//

int  Modifier_livre(Livre * book)
{
int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query[350];
    sprintf(query,"update Livre set (Titre='%s',Auteur='%s',maison_edition='%s',prix='%s',nb_examplaires_disponibles='%s',categorie='%s') where id_livre = %d ;",
    book->Titre,book->Auteur,book->maison_edition,book->prix,book->nb_examplaires_disponibles,book->categorie);


  res = mysql_query(query,con);

  printf("the res of modifying the books is %d \n",res);

mysql_close(con);

return res ;
}





//*****une fonction pour Modife un livre les livres***********//
void Ajouter_livre(Livre* book )
{

int res=0;


    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];

    /*
     sprintf(querry,"insert into Utilisateur Values('%d','%s','%s','%s','%s','%s','%d','%s','%s','%s','%d');",
    NULL,utili->Nom,utili->Prenom,utili->login,utili->email,utili->mot_passe,utili->adresse,0,utili->num_tel,utili->Num_Cin,0);*/

    sprintf(querry,"INSERT INTO `Livre` Values('%d','%s','%s','%s','%d','%d','%d','%s','%s');",
    11,book->Titre,book->Auteur,book->maison_edition,book->prix,0,book->nb_examplaires_disponibles,book->categorie,book->ISBN_livre);

    printf("we are here hahahah \n");
   /*res = mysql_query(con, querry);
printf("the result %d \n", res);*/



    mysql_close(con);
return res ;

}









//*****************************une méthode pour voir la liste des Utilisateurs**********************//

void  Liste_Utilisateurs(GtkListStore  *store,GtkTreeIter iter){


    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char query[100];
    if (mysql_query(con, "select * from Utilisateur")) {
      finish_with_error(con);
    }else{
        MYSQL_RES *result = mysql_store_result(con);
        if (result == NULL)
        {
          finish_with_error(con);
        }
        int num_fields = mysql_num_fields(result);
        MYSQL_ROW row;
        char user_info[100];
        while ((row = mysql_fetch_row(result)))
        {
            /*gtk_list_store_append (store, &iter);
            gtk_list_store_set(store, &iter,COL_ID, row[0],COL_NOM, row[4],COL_PRENOM, row[5],COL_ROLE, row[13],-1);*/
        }
        mysql_free_result(result);
    }
    mysql_close(con);
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

mysql_close(con);

}









