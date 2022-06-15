#include "negozio.h"

	negozio *CreaNegozio(unsigned long id, char *nome, char *indirizzo, char *citta,   unsigned long telefono) {
		negozio *n=malloc(sizeof(negozio));
		n->idNegozio=id;

		n->nome=calloc(strlen(nome), sizeof(char));
        strncpy(n->nome, nome, strlen(nome));

        n->indirizzo=calloc(strlen(indirizzo), sizeof(char));
        strncpy(n->indirizzo, indirizzo, strlen(indirizzo));

        n->citta=calloc(strlen(citta), sizeof(char));
        strncpy(n->citta, citta, strlen(citta));

	n->telefono=telefono;

        return n;
	}

	unsigned long getIdNegozio(negozio *n) {
		return n->idNegozio;
	}

	char *getNomeNegozio(negozio *n) {
		return n->nome;
	}

	char *getIndirizzoNegozio(negozio *n) {
		return n->indirizzo;

	}

	char *getCittaNegozio(negozio *n) {
		return n->citta;

	}

	unsigned long getTelefonoNegozio(negozio *n) {
		return n->telefono;
	}


