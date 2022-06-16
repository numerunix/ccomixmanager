#include "negozio.h"

negozio *CreaNegozio(unsigned long id, char *nome, char *indirizzo, char *citta,   char *telefono) {
    negozio *n=malloc(sizeof(negozio));
    n->idNegozio=id;

    n->nome=calloc(strlen(nome), sizeof(char));
    strncpy(n->nome, nome, strlen(nome));

    n->indirizzo=calloc(strlen(indirizzo), sizeof(char));
    strncpy(n->indirizzo, indirizzo, strlen(indirizzo));

    n->citta=calloc(strlen(citta), sizeof(char));
    strncpy(n->citta, citta, strlen(citta));

    n->telefono=calloc(strlen(telefono), sizeof(char));
    strncpy(n->telefono, telefono, strlen(telefono));

    return n;
}

void deallocaNegozio(negozio *n) {
    free(n->citta);
    free(n->indirizzo);
    free(n->nome);
    free(n->telefono);
    free(n);
}
