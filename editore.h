#ifndef EDITORE_H_INCLUDED
#define EDITORE_H_INCLUDED
#include <malloc.h>
#include <string.h>


typedef struct editore {
	unsigned long id, sconto;
	char *nome, *note;
} editore;

#endif // EDITORE_H_INCLUDED
