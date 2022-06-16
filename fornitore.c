#include "fornitore.h"

const fornitore *CreaFornitore(unsigned long id, const char *nome, const char *indirizzo, const char *citta, const char *provincia,  const char *telefono, const char *fax, const char *email, const char *sitoweb, const char *note) {
    fornitore *f=malloc(sizeof(fornitore));
    f->idFornitore=id;

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

unsigned long getIdFornitore(const fornitore *f) {
    return f->idFornitore;
}

const char *getNomeFornitore(const fornitore *f) {
    return f->nome;
}

const char *getIndirizzoFornitore(const fornitore *f) {
    return f->indirizzo;

}

const char *getCittaFornitore(const fornitore *f) {
    return f->citta;
}

const char *getprovinciaFornitore(const fornitore *f) {
    return f->provincia;

}

const char *getTelefonoFornitore(const fornitore *f) {
    return f->telefono;
}


const char *getFaxFornitore(const fornitore *f) {
    return f->fax;
}


const char *geteMailFornitore(const fornitore *f) {
    return f->eMail;
}

const char *getSitoWebFornitore(const fornitore *f) {
    return f->sitoWeb;
}

const char *getNoteFornitore(const fornitore *f) {
    return f->note;

}

