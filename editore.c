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

unsigned long getIdEditore(const editore *e) {
	return e->id;
}

unsigned long getScontoEditore(const editore *e) {
	return e->sconto;
}

const char *getNomeEditore(const editore *e) {
	return e->nome;
}


const char *getNoteEditore(const editore *e) {
	return e->note;
}

void deallocaEditore(const editore *e)  {
    free(e->nome);
    free(e->note);
    free(e);
}
