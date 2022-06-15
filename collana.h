#ifndef COLLANA_H_INCLUDED
#define COLLANA_H_INCLUDED

#include <malloc.h>
#include <string.h>

typedef struct collana {
	unsigned long idCollana, idEditore;
	char * nome, note;
} collana;

#endif // COLLANA_H_INCLUDED
