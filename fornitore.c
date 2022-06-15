#include "fornitore.h"

	fornitore *CreaFornitore(unsigned long id, char *nome, char *indirizzo, char *citta, char *provincia,  unsigned long telefono, unsigned long fax, char *email, char *sitoweb, char *note) {
		fornitore *f=malloc(sizeof(fornitore));
		f->idFornitore=id;

		f->nome=calloc(strlen(nome), sizeof(char));
        strncpy(f->nome, nome, strlen(nome));

        f->indirizzo=calloc(strlen(indirizzo), sizeof(char));
        strncpy(f->indirizzo, indirizzo, strlen(indirizzo));

        f->citta=calloc(strlen(citta), sizeof(char));
        strncpy(f->citta, citta, strlen(citta));

        f->provincia=calloc(strlen(provincia), sizeof(char));
        strncpy(f->provincia, provincia, strlen(provincia));

		f->telefono=telefono;
		f->fax=fax;

        f->eMail=calloc(strlen(email), sizeof(char));
        strncpy(f->eMail, email, strlen(email));

        f->sitoWeb=calloc(strlen(sitoweb), sizeof(char));
        strncpy(f->sitoWeb, sitoweb, strlen(sitoweb));


        f->note=calloc(strlen(note), sizeof(char));
        strncpy(f->note, note, strlen(note));

        return f;
	}

	unsigned long getIdFornitore(fornitore *f) {
		return f->idFornitore;
	}

	char *getNomeFornitore(fornitore *f) {
		return f->nome;
	}

	char *getIndirizzoFornitore(fornitore *f) {
		return f->indirizzo;

	}

	char *getCittaFornitore(fornitore *f) {
		return f->citta;

	}

	char *getprovinciaFornitore(fornitore *f) {
		return f->provincia;

	}

	unsigned long getTelefonoFornitore(fornitore *f) {
		return f->telefono;
	}


	unsigned long getFaxFornitore(fornitore *f) {
		return f->fax;
	}


	char *geteMailFornitore(fornitore *f) {
		return f->eMail;

	}

    char *getSitoWebFornitore(fornitore *f) {
        return f->sitoWeb;

	}

	    char *getNoteFornitore(fornitore *f) {
        return f->note;

	}
