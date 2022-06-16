#ifndef DIPENDENTE_H_INCLUDED
#define DIPENDENTE_H_INCLUDED

#include <malloc.h>
#include <string.h>

typedef struct Dipendente {
	unsigned long idDipendente, idNegozio, cellulare;
	const char *nome, *cognome;
} dipendente;
#endif // DIPENDENTE_H_INCLUDED
