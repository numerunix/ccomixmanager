#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#include <time.h>
#include <malloc.h>
#include <string.h>

typedef struct cliente {
    unsigned long int idCliente, idCasella;
      unsigned int cap, sconto;
	  char *nome, *cognome, *indirizzo, *citta, *provincia, *eMail, *sitoWeb, *note;
      time_t dataNascita, dataInizioTesseramento, dataFineTesseramento;
      unsigned long telefono, cellulare, fax;
} cliente;
#endif // CLIENTE_H_INCLUDED
