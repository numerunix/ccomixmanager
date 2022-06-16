#include "fornitore.h"

fornitore *CreaFornitore(unsigned long id, const char *nome, const char *indirizzo, const char *citta, const char *provincia,  const char *telefono, const char *fax, const char *email, const char *sitoweb, const char *note) {
    fornitore *f=malloc(sizeof(fornitore));
    f->id=id;

    f->nome=calloc(strlen(nome), sizeof(char));
    strncpy(f->nome, nome, strlen(nome));

    f->indirizzo=calloc(strlen(indirizzo), sizeof(char));
    strncpy(f->indirizzo, indirizzo, strlen(indirizzo));

    f->citta=calloc(strlen(citta), sizeof(char));
    strncpy(f->citta, citta, strlen(citta));

    f->provincia=calloc(strlen(provincia), sizeof(char));
    strncpy(f->provincia, provincia, strlen(provincia));

    f->telefono=calloc(strlen(telefono), sizeof(char));
    strncpy(f->telefono, telefono, strlen(telefono));

    f->fax=calloc(strlen(fax), sizeof(char));
    strncpy(f->fax, fax, strlen(fax));

    f->eMail=calloc(strlen(email), sizeof(char));
    strncpy(f->eMail, email, strlen(email));



    f->sitoWeb=calloc(strlen(sitoweb), sizeof(char));
    strncpy(f->sitoWeb, sitoweb, strlen(sitoweb));


    f->note=calloc(strlen(note), sizeof(char));
    strncpy(f->note, note, strlen(note));

    return f;
}

void dellocaFornitore(const fornitore *f) {
    free(f->citta);
    free(f->eMail);
    free(f->fax);
    free(f->indirizzo);
    free(f->note);
    free(f->provincia);
    free(f->sitoWeb);
    free(f->telefono);
    free(f);
}
