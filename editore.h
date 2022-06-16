#ifndef EDITORE_H_INCLUDED
#define EDITORE_H_INCLUDED
#include <malloc.h>
#include <string.h>


typedef struct editore {
	unsigned long id, sconto;
	const char *nome, *note;
} editore;

const editore *CreaEditore(unsigned long id, const char *nome, unsigned long sconto, const char *note);
unsigned long getIdEditore(const editore *e);
unsigned long getScontoEditore(const editore *e);
const char *getNomeEditore(const editore *e);
const char *getNoteEditore(const editore *e);
void deallocaEditore(const editore *e);
#endif // EDITORE_H_INCLUDED
