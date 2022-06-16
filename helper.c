#include "editore.h"
#include "negozio.h"
#include "fornitore.h"
unsigned long getId(editore *e) {
	return e->id;
}

unsigned long getSconto(const editore *e) {
	return e->sconto;
}

const char *getNome(const editore *e) {
	return e->nome;
}


const char *getNote(const editore *e) {
	return e->note;

}
const char *getIndirizzo(negozio *n) {
    return n->indirizzo;
}

const char *getCitta(negozio *n) {
    return n->citta;
}

const char *getTelefono(negozio *n) {
    return n->telefono;
}

const char *getProvincia(const fornitore *f) {
    return f->provincia;

}

const char *getFax(const fornitore *f) {
    return f->fax;
}


const char *geteMail(const fornitore *f) {
    return f->eMail;
}

const char *getSitoWeb(const fornitore *f) {
    return f->sitoWeb;
}

