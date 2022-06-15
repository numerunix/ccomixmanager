#include "articolo.h"

articolo *CreaArticolo(unsigned long mid, char *mdescrizione, char *mcodiceabarre, unsigned int miva, char *mnote, unsigned long midcollana, unsigned long midcategoria, unsigned long mideditore, unsigned long midfornitore, unsigned int mnumero, char* mdatapubblicazione) {
    articolo *a=malloc(sizeof(articolo));
    a->idArticolo=mid;
    a->descrizione=mdescrizione;
    a->codiceABarre=calloc(strlen(mcodiceabarre), sizeof(char));
    strncpy(a->codiceABarre, mcodiceabarre, strlen(mcodiceabarre));
    a->iva=miva;
    a->note=calloc(strlen(mnote), sizeof(char));
    strncpy(a->note, mnote, strlen(mnote));
    a->note=mnote;
    a->idCollana=midcollana;
    a->idCategoria=midcategoria;
    a->idEditore=mideditore;
    a->idFornitore=midfornitore;
    a->numero=mnumero;
    a->dataPubblicazione=(time_t) atol(mdatapubblicazione);
    return a;
}

unsigned long getIdArticolo(articolo *a) {
    return a->idArticolo;
}


char *getDescrizioneArticolo(articolo *a) {
    return a->descrizione;
}



char *getCodiceABarreArticolo(articolo *a) {
    return a->codiceABarre;
}

unsigned int getIvaArticolo(articolo *a) {
    return a->iva;
}

char *getNoteArticolo(articolo *a) {
    return a->note;
}

unsigned long getCollanaArticolo(articolo *a) {
    return a->idCollana;
}

unsigned long getCategoriaArticolo(articolo *a) {
    return a->idCategoria;
}
unsigned long getEditoreArticolo(articolo *a) {
    return a->idEditore;
}

unsigned long getFornitoreArticolo(articolo *a) {
    return a->idFornitore;
}

unsigned int getNumeroArticolo(articolo *a) {
    return a->numero;
}

time_t *getDataPubblicazioneArticolo(articolo *a) {
    return a->dataPubblicazione;
}
