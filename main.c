#include <stdio.h>
#include <stdlib.h>

#include "types.h"
#include "errors.h"

#define SALIDA "salida.csv"
#define DELIMITER ','
#define MAX_NAME 100
#define MAX_ARTIST 100
#define MAX_GENRE 100

extern char * errors_dictionary[MAX_ERRORS];

status_t export_to_csv(char * name, char * artist, char * genre, FILE * file_out, char del);

int main(int argc, char *argv[]) {
	char name[MAX_NAME] = "Muy Punk";
	char artist[MAX_ARTIST] = "La Polla";
	char genre[MAX_GENRE] = "Punk";
	FILE * file_out;
	status_t st;


	file_out = fopen(SALIDA, "wt");
	if (file_out == NULL) {
		st = ERR_INVALID_OUTPUT_FILE;
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}

	if(export_to_csv(name, artist, genre, file_out, DELIMITER))

	if(fclose(file_out) == EOF) {
		st = ERR_CLOSING_FILE;
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}

	return OK;
}

status_t export_to_csv(char * name, char * artist, char * genre, FILE * file_out, char del) {
	status_t st;

	if(fprintf(file_out, "%s", name) < 0) {
		st = ERR_WRITING_TO_FILE; 
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}
	if (fputc(del, file_out) == EOF) {
		st = ERR_WRITING_TO_FILE; 
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}
	if(fprintf(file_out, "%s", artist) < 0) {
		st = ERR_WRITING_TO_FILE; 
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}
	if (fputc(del, file_out) == EOF) {
		st = ERR_WRITING_TO_FILE; 
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}
	if(fprintf(file_out, "%s", genre) < 0) {
		st = ERR_WRITING_TO_FILE; 
		fprintf(stderr, "%s\n", errors_dictionary[st]);
		return st;
	}
	return OK;
}