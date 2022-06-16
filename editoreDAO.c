#include <mariadb/mysql.h>
#include "editore.h"
#include "helper.h"
extern MYSQL *conn;

unsigned int editoreDAO(editore *e) {
    char query[4096];
    sprintf(query, "INSERT INTO Editori(idEditore, nome, sconto, note) VALUES(%lu, \"%s\", %lu, \"%s\");",getId(e), getNome(e), getSconto(e), getNote(e));
    if (mysql_real_query(conn, query, strlen(query))!=0)
        return mysql_errno(conn);
    return 0;
}
