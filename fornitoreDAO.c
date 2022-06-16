#include <mariadb/mysql.h>
#include "fornitore.h"
#include "helper.h"
extern MYSQL *conn;

unsigned int fornitoreDAO(fornitore *f) {
    char query[4096];
    sprintf(query, "INSERT INTO Fornitori (idFornitore, nome, indirizzo, citta, provincia, email, sitoweb, note, telefono, fax) VALUES(%lu, \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\", \"%s\");",getId(f), getNome(f), getIndirizzo(f), getCitta(f), getProvincia(f), geteMail(f),getSitoWeb(f), getNote(f), getTelefono(f), getFax(f));
    printf("%s\n", query);
    if (mysql_real_query(conn, query, strlen(query))!=0)
        return mysql_errno(conn);
    return 0;
}
