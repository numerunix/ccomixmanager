#include "collana.h"

collana * CreaCollana(unsigned long idcollana, char *nome, char *note, unsigned long ideditore) {
    collana *c=malloc(sizeof(collana));
    c->idCollana=idcollana;
	c->nome=calloc(strlen(nome), sizeof(char));
    strncpy(c->nome, nome, strlen(nome));
    c->note=calloc(strlen(note), sizeof(char));
    strncpy(c->note, note, strlen(note));
    c->idEditore=ideditore;
    return c;
}


unsigned long getIdCollana(collana *c) {
	return c->idCollana;
}

char *getNomeCollana(collana *c) {
    return c->nome;
}

char *getNoteCollana(collana *c) {
    return  c->note;
}

unsigned long getIdEditoreCollana(collana *c) {
    return c->idEditore;
}
