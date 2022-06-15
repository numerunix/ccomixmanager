#ifndef OGGETTO_H_INCLUDED
#define OGGETTO_H_INCLUDED


#include <malloc.h>
#include <time.h>-

typedef struct oggetto {
    unsigned long idOggetto, quantita, idDipendente, idNegozio, idArticolo;
    unsigned int sconto, minimo, vendita;
    time_t dataOrdine;
	float prezzo;
} oggetto;

#endif // OGGETTO_H_INCLUDED
