/*
 * get_data.h
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_GET_DATA_GET_DATA_H_
#define SRC_GET_DATA_GET_DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include "print_result/is_valid/is_valid.h"
#include "to_upper/to_upper.h"

#define ZERO  				0
#define ONE  				1
#define MAX_LENGTH_NAME     60
#define MAX_LENGTH_SURNAME  MAX_LENGTH_NAME
#define MAX_LENGTH_TOWN     MAX_LENGTH_NAME
#define LENGTH_DATE			11
#define SPEC_CHAR           "%c"
#define INSERT_NAME 		"Inserisci il nome>"
#define INSERT_SURNAME 		"Inserisci il cognome>"
#define INSERT_DATE 		"Inserisci la data di nascita (formato GG/MM/AAAA)>"
#define INSERT_TOWN 		"Inserisci il comune di nascita>"
#define INSERT_SEX 			"Inserisci il sesso (M-F)>"
#define NOT_VALID_DATE 		"Dato inserito non valido"

/**
 * Acquisisce il nome
 * @return
 */
char* get_name();

/**
 * Acquisisce il cognome
 * @return
 */
char* get_surname();

/**
 * Acquisisce la data di nascita
 */
char* get_birth_date();

/**
 * Acquisisce il comune di nascita
 */
char* get_birth_town();

/**
 * Acquisisce il sesso
 * @return
 */
char get_sex();

#endif /* SRC_GET_DATA_GET_DATA_H_ */
