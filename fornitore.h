#ifndef FORNITORE_H_INCLUDED
#define FORNITORE_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <string.h>

typedef struct fornitore {
    unsigned long idFornitore;
    unsigned int cap;
	char *nome, *indirizzo, *citta, *provincia, *eMail, *sitoWeb, *note, *telefono, *fax;
} fornitore;

const fornitore *CreaFornitore(unsigned long id, const char *nome, const char *indirizzo, const char *citta, const char *provincia,  const char *telefono, const char *fax, const char *email, const char *sitoweb, const char *note);
unsigned long getIdFornitore(const fornitore *f);
const char *getNomeFornitore(const fornitore *f);
const char *getIndirizzoFornitore(const fornitore *f);
const char *getCittaFornitore(const fornitore *f);
const char *getprovinciaFornitore(const fornitore *f);
const char *getTelefonoFornitore(const fornitore *f);
const char *getTelefonoFornitore(const fornitore *f);
const char *geteMailFornitore(const fornitore *f);
const char *getSitoWebFornitore(const fornitore *f);
const char *getNoteFornitore(const fornitore *f);

#endif // FORNITORE_H_INCLUDED
