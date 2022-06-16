#ifndef NEGOZIO_H_INCLUDED
#define NEGOZIO_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <string.h>

typedef struct negozio {
    unsigned long idNegozio;
	char *nome, *indirizzo, *citta, *telefono;
} negozio;

negozio *CreaNegozio(unsigned long id, char *nome, char *indirizzo, char *citta, char *telefono);
void deallocaNegozio(negozio *n);

#endif // NEGOZIO_H_INCLUDED
