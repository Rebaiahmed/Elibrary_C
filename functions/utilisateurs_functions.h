#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "connect_database.h"
#include "../user_structus.h"

//**************************Défenir nos fonctions ici *************************//









//*******************************************//


int login(char * email , char * pwd)
{

int result
MYSQL *con = mysql_init(NULL);
Connectdb(con);
//****excuter la requete*************//
 char req[300];
        sprintf(req,"select * from Utilisateur where email ='%s' and mot_passe='%s'",log,pass);
        mysql_query(mysql,req);

        MYSQL_RES *result = NULL;
        MYSQL_ROW row;
         int x = mysql_num_rows(result);

        //On met le jeu de résultat dans le pointeur result
        result = mysql_use_result(mysql);
        row = mysql_fetch_row(result);

          if (x == 0){

            result = -1;


   }else if (x == 1)
        {

        //on doit vérifier le role de l'utlisateur(etudiant ou Admin)
          nom=row[3];
            prenom=row[4];
            role=row[5];

            printf("the columns are %s %s %s \n",row[0],row[1],row[9]);
        result = 1;
        }


return result ;
}




void Creer_Emprunt(Emprunt* emp)
{
int res=0;
    MYSQL *con = mysql_init(NULL);
    Connectdb(con);
    char querry[350];
    sprintf(querry,"insert into Emprunt Values(NULL,'%s','%s','%s','%d','%d');",
    emp.id,emp.date_emprunt, emp.date_retour,emp.etat,emp.Utilisateur_id_utilisateur,emp.Livre_id_livre);
    if (mysql_query(con, querry)) {
      finish_with_error(con);
      res = -1;
    }else{
        res = 1;
    }

mysql_close(con);

}


void deconnecter()
{
//ici on va excuter le button hide interface utlisateur et afficher interface login

}



int Modifier_Profile(Utilisateur* utili)
{
//ici connecter a l base et mdofiier enregister les modifications

return 0 ;
}



