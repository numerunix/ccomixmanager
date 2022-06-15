#include "dipendente.h"

dipendente *CreaDipendente(unsigned long id, char *nome, char *cognome, unsigned long cellulare, unsigned long idnegozio)
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

char *getNomeDipedente(dipendente* d) {
	return d->nome;
}

char *getCognomeDipendente(dipendente *d) {
	return d->cognome;
}

unsigned long getIdDipendente(dipendente *d) {
	return d->idDipendente;
}

unsigned long getIdNegozioDipendente(dipendente *d) {
	return d->idNegozio;
}
