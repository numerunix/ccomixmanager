#ifndef NEGOZIO_H_INCLUDED
#define NEGOZIO_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <string.h>

typedef struct negozio {
    unsigned long idNegozio;
	char *nome, *indirizzo, *citta;
    unsigned long telefono;
} negozio;


#endif // NEGOZIO_H_INCLUDED
