#include <mariadb/mysql.h>
#include "negozio.h"

extern MYSQL *conn;

unsigned int negozioDAO(negozio *n) {
    char query[4096];
    sprintf(query, "INSERT INTO Negozi(idNegozio, nome, indirizzo, citta, telefono) VALUES(%lu, \"%s\", \"%s\", \"%s\", \"%s\");",getIdNegozio(n), getNomeNegozio(n), getIndirizzoNegozio(n), getCittaNegozio(n), getTelefonoNegozio(n));
    if (mysql_real_query(conn, query, strlen(query))!=0)
        return mysql_errno(conn);
    return 0;
}
