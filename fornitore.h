#ifndef FORNITORE_H_INCLUDED
#define FORNITORE_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <string.h>

typedef struct fornitore {
    unsigned long id;
    unsigned int cap;
	char *nome, *indirizzo, *citta, *provincia, *eMail, *sitoWeb, *note, *telefono, *fax;
} fornitore;

fornitore *CreaFornitore(unsigned long id, const char *nome, const char *indirizzo, const char *citta, const char *provincia,  const char *telefono, const char *fax, const char *email, const char *sitoweb, const char *note);
void dellocaFornitore(const fornitore *f);
#endif // FORNITORE_H_INCLUDED
