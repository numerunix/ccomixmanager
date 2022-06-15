#ifndef ARTICOLO_H_INCLUDED
#define ARTICOLO_H_INCLUDED

#include <malloc.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

typedef struct articolo {
    unsigned long idArticolo, idCollana, idCategoria, idEditore, idFornitore;
    char *descrizione, *codiceABarre, *note;
    unsigned int iva, numero;
    time_t dataPubblicazione;
} articolo;

#endif // ARTICOLO_H_INCLUDED
