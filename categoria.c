#include "categoria.h"

categoria * creaCategoria(unsigned long mid, char* mnome, char *mnote) {
		categoria *c=malloc(sizeof(categoria));
		c->idCategoria=mid;
        c->nome=calloc(strlen(mnome), sizeof(char));
        strncpy(c->nome, mnome, strlen(mnome));
        c->note=calloc(strlen(mnote), sizeof(char));
        strncpy(c->note, mnote, strlen(mnote));
        return c;
}

unsigned long getIdCategoria(categoria *c) {
	return c->idCategoria;
}

char *getNomeCategoria(categoria *c) {
	return c->nome;
}

char *getNoteCategoria(categoria *c) {
	return c->note;
}
