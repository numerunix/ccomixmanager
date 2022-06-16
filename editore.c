#include "editore.h"


const editore *CreaEditore(unsigned long id, const char *nome, unsigned long sconto, const char *note) {
    editore *e=malloc(sizeof(editore));
    e->id=id;
	e->nome=calloc(strlen(nome), sizeof(char));
    strncpy(e->nome, nome, strlen(nome));
	e->sconto=sconto;
    e->note=calloc(strlen(note), sizeof(char));
    strncpy(e->note, note, strlen(note));
    return e;
}

void deallocaEditore(const editore *e)  {
    free(e->nome);
    free(e->note);
    free(e);
}
