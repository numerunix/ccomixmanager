#include "cliente.h"

	cliente *CreaCliente(unsigned long id, char *nome, char *cognome, char *indirizzo, time_t datanascita, unsigned int cap, char *citta, char *provincia,  unsigned long telefono, unsigned long cellulare, unsigned  long fax, char *email, char *sitoweb, time_t datainiziotesseramento, time_t datafinetesseramento, char *note, unsigned long casella, unsigned int sconto) {
		cliente *c=malloc(sizeof(cliente));
		c->idCliente=id;

		c->nome=calloc(strlen(nome), sizeof(char));
        strncpy(c->nome, nome, strlen(nome));

        c->cognome=calloc(strlen(cognome), sizeof(char));
        strncpy(c->cognome, cognome, strlen(cognome));

        c->indirizzo=calloc(strlen(indirizzo), sizeof(char));
        strncpy(c->indirizzo, indirizzo, strlen(indirizzo));

		c->dataNascita=datanascita;

		c->cap=cap;

        c->citta=calloc(strlen(citta), sizeof(char));
        strncpy(c->citta, citta, strlen(citta));

        c->provincia=calloc(strlen(provincia), sizeof(char));
        strncpy(c->provincia, provincia, strlen(provincia));

		c->telefono=telefono;
		c->cellulare=cellulare;
		c->fax=fax;

        c->eMail=calloc(strlen(email), sizeof(char));
        strncpy(c->eMail, email, strlen(email));

        c->sitoWeb=calloc(strlen(sitoweb), sizeof(char));
        strncpy(c->sitoWeb, sitoweb, strlen(sitoweb));

		c->dataInizioTesseramento=datainiziotesseramento;
		c->dataFineTesseramento=datafinetesseramento;


        c->note=calloc(strlen(note), sizeof(char));
        strncpy(c->note, note, strlen(note));

		c->idCasella=casella;
		c->sconto=sconto;
	}

	unsigned long getIdCliente(cliente *c) {
		return c->idCliente;
	}

	char *getNomeCliente(cliente *c) {
		return c->nome;
	}

	char *getCognomeCliente(cliente *c) {
		return c->cognome;

	}


	char *getIndirizzoCliente(cliente *c) {
		return c->indirizzo;

	}

	time_t getDataNascitaCliente(cliente *c) {
            return c->dataNascita;

    }

   	unsigned int getCapCliente(cliente *c) {
		return c->cap;
	}

	char *getCittaCliente(cliente *c) {
		return c->citta;

	}

	char *getprovinciaCliente(cliente *c) {
		return c->provincia;

	}

	unsigned long getTelefonoCliente(cliente *c) {
		return c->telefono;
	}


	unsigned long getCellulareCliente(cliente *c) {
		return c->cellulare;
	}

	unsigned long getFaxCliente(cliente *c) {
		return c->fax;
	}


	char *geteMailCliente(cliente *c) {
		return c->eMail;

	}

    char *getSitoWebCliente(cliente *c) {
        return c->sitoWeb;

	}

	time_t getDataIniziotesseramentoCliente(cliente *c) {
            return c->dataNascita;

    }

	time_t getDataInizioTesseramentoliente(cliente *c) {
            return c->dataInizioTesseramento;

    }
	char *getDataFineTesseramentoCliente(cliente *c) {
		return c->dataFineTesseramento;

	}

	unsigned long getCasellaCliente(cliente *c) {
		return c->idCasella;
	}


	unsigned int getScontoCliente(cliente *c) {
		return c->sconto;
	}
