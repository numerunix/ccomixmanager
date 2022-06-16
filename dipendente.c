#include "dipendente.h"

dipendente *CreaDipendente(unsigned long id, const char *nome, const char *cognome, unsigned long cellulare, unsigned long idnegozio)
{
    dipendente *d=malloc(sizeof(dipendente));
	d->idDipendente=id;
	d->nome=calloc(strlen(nome), sizeof(char));
    strncpy(d->nome, nome, strlen(nome));

    d->cognome=calloc(strlen(cognome), sizeof(char));
    strncpy(d->cognome, cognome, strlen(cognome));

	d->cellulare=cellulare;
	d->idNegozio=idnegozio;
    return d;
}

const char *getNomeDipedente(const dipendente* d) {
	return d->nome;
}

const char *getCognomeDipendente(const dipendente *d) {
	return d->cognome;
}

unsigned long getIdDipendente(const dipendente *d) {
	return d->idDipendente;
}

unsigned long getIdNegozioDipendente(const dipendente *d) {
	return d->idNegozio;
}
