#include <mariadb/mysql.h>
#include "editore.h"

extern MYSQL *conn;

unsigned int editoreDAO(editore *e) {
    char query[4096];
    sprintf(query, "INSERT INTO Editori(idEditore, nome, sconto, note) VALUES(%lu, \"%s\", %lu, \"%s\");",getIdEditore(e), getNomeEditore(e), getScontoEditore(e), getNoteEditore(e));
    if (mysql_real_query(conn, query, strlen(query))!=0)
        return mysql_errno(conn);
    return 0;
}
