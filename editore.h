#ifndef EDITORE_H_INCLUDED
#define EDITORE_H_INCLUDED
#include <malloc.h>
#include <string.h>


typedef struct editore {
	unsigned long id, sconto;
	const char *nome, *note;
} editore;

const editore *CreaEditore(unsigned long id, const char *nome, unsigned long sconto, const char *note);
void deallocaEditore(const editore *e);
#endif // EDITORE_H_INCLUDED
