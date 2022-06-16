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
unsigned long getIdNegozio(negozio *n);
char *getNomeNegozio(negozio *n);
char *getIndirizzoNegozio(negozio *n);
char *getCittaNegozio(negozio *n);
char *getTelefonoNegozio(negozio *n);
void deallocaNegozio(negozio *n);

#endif // NEGOZIO_H_INCLUDED
