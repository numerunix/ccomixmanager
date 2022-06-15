#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED

#include <malloc.h>
#include <string.h>

typedef struct categoria {
	unsigned long idCategoria;
	char *nome, *note;
} categoria;

#endif // CATEGORIA_H_INCLUDED
