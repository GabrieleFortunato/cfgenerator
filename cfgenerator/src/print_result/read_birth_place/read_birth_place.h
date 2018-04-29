/*
 * read_birth_place.h
 *
 *  Created on: 21 ago 2017
 *      Author: gabriele
 */

#ifndef SRC_READ_BIRTH_PLACE_READ_BIRTH_PLACE_H_
#define SRC_READ_BIRTH_PLACE_READ_BIRTH_PLACE_H_

#include <assert.h>
#include <ctype.h>
#include <print_result/is_valid/is_valid.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "close/close.h"

#define FILE_NOT_FOUND "\nFile dei codici catastali non trovato\n"
#define ERROR		   "Errore di allocazione nella memoria"
#define FILE_NAME  	   "comuni.csv"
#define FILE_MODE      "r"
#define PAUSE		   "PAUSE"
#define EOS			   '\0'
#define NEW_LINE       "\n"
#define VIRGO	       ","
#define ZERO           0
#define FOUR           4
#define FIVE           5
#define FOURTYSIX      46
#define STRLEN         50
#define HUNDRED        100

/**
 * Legge da file il codice catastale del comune di nascita
 * @pre il file deve essere aperto
 * @post il codice risultante deve essere una stringa di 4 caratteri
 *       di cui la prima una lettera e gli altri cifre
 * @param places_file
 * @param birth_place
 * @return
 */
char* read_birth_place_code(FILE* places_file,char* birth_place);

/**
 * Stampa un messaggio di errore se il file non è stato trovato
 */
void file_not_found();

#endif /* SRC_READ_BIRTH_PLACE_READ_BIRTH_PLACE_H_ */
