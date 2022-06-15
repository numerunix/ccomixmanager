#include "oggetto.h"

oggetto *CreaOggetto(unsigned long id, unsigned long quantita, float prezzo, unsigned int sconto, unsigned long iddipendente, unsigned long idnegozio, unsigned long idarticolo, time_t dataordine, unsigned int minimo) {
    oggetto *o=malloc(sizeof(oggetto));
    o->idOggetto=id;
    o->quantita=quantita;
    o->prezzo=prezzo;
    o->sconto=sconto;
    o->idDipendente=iddipendente;
    o->idNegozio=idnegozio;
    o->idArticolo=idarticolo;
    o->dataOrdine=dataordine;
    o->minimo=minimo;
    o->vendita=0;
    return 0;
}

unsigned long getIdOggetto(oggetto *o) {
		return o->idOggetto;
}

unsigned long getQuantitaOggetto(oggetto *o) {
		return o->quantita;
}

float getPrezzoOggetto(oggetto *o) {
		return o->prezzo;
}

unsigned int getScontoOggetto(oggetto *o) {
		return o->sconto;
}

unsigned long getIdDipendenteOggetto(oggetto *o) {
		return o->idDipendente;
}

unsigned long getIdNegozioOggetto(oggetto *o) {
		return o->idNegozio;
}

unsigned long getIdArticoloOggetto(oggetto *o) {
		return o->idArticolo;
}

time_t getDataOrdineOggetto(oggetto *o) {
    return o->dataOrdine;
}

unsigned int getMinimoOggetto(oggetto *o) {
		return o->minimo;
}

unsigned int getVenditaOggetto(oggetto *o) {
		return o->vendita;
}

