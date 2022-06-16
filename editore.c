#include "editore.h"


editore *CreaEditore(unsigned long id, char *nome, unsigned long sconto, char *note) {
    editore *e=malloc(sizeof(editore));
    e->id=id;
	e->nome=calloc(strlen(nome), sizeof(char));
    strncpy(e->nome, nome, strlen(nome));
	e->sconto=sconto;
    e->note=calloc(strlen(note), sizeof(char));
    strncpy(e->note, note, strlen(note));
    return e;
}

unsigned long getIdEditore( editore *e) {
	return e->id;
}

unsigned long getScontoEditore( editore *e) {
	return e->sconto;
}

char *getNomeEditore(editore *e) {
	return e->nome;
}


char *getNoteEditore(editore *e) {
	return e->note;
}

void deallocaEditore(editore *e)  {
    free(e->nome);
    free(e->note);
    free(e);
}
