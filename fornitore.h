#ifndef FORNITORE_H_INCLUDED
#define FORNITORE_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <string.h>

typedef struct fornitore {
    unsigned long idFornitore;
    unsigned int cap;
	char *nome, *indirizzo, *citta, *provincia, *eMail, *sitoWeb, *note;
    unsigned long telefono, fax;
} fornitore;

#endif // FORNITORE_H_INCLUDED
