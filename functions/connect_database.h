#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

/*void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

void Connectdb(MYSQL *con){
    if (con == NULL)
    {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }
    if (mysql_real_connect(con, "localhost", "root", "root",
          "GRH", 0, NULL, 0) == NULL)
    {
    printf("hehhehhehehhehe");
      finish_with_error(con);
    }
}*/
