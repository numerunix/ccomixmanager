#ifndef EDITORE_H_INCLUDED
#define EDITORE_H_INCLUDED
#include <malloc.h>
#include <string.h>


typedef struct editore {
	unsigned long id, sconto;
	char *nome, *note;
} editore;

editore *CreaEditore(unsigned long id, char *nome, unsigned long sconto, char *note);
unsigned long getIdEditore( editore *e);
unsigned long getScontoEditore( editore *e);
char *getNomeEditore(editore *e);
char *getNoteEditore(editore *e);
void deallocaEditore(editore *e);
#endif // EDITORE_H_INCLUDED
