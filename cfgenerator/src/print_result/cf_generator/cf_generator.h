/*
 * cf_generator.h
 *
 *  Created on: 21 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_CFGENERATOR_CF_GENERATOR_H_
#define SRC_CFGENERATOR_CF_GENERATOR_H_

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "print_result/is_valid/is_valid.h"

#define ZERO  		  0
#define ONE   		  1
#define TWO	  	      2
#define THREE 		  3
#define FOUR  		  4
#define FIVE  		  5
#define SIX  		  6
#define SEVEN   	  7
#define EIGHT   	  8
#define NINE   	      9
#define TEN   	     10
#define ELEVEN   	 11
#define TWELVE       12
#define THIRTEEN   	 13
#define FOURTEEN  	 14
#define FIFTEEN   	 15
#define SIXTEEN   	 16
#define SEVENTEEN    17
#define EIGHTEEN   	 18
#define NINETEEN   	 19
#define TWENTY   	 20
#define TWENTYONE    21
#define TWENTYTWO    22
#define TWENTYTHREE  23
#define TWENTYFOUR   24
#define TWENTYFIVE   25
#define TWENTYSIX    26
#define THIRTYONE    31
#define ASCII 	     48
#define HUNDRED      100
#define THOUSAND     1000
#define MIN_YEAR     1900
#define MAX_YEAR     2017
#define EOS   	     '\0'
#define A  	         'A'
#define B  	         'B'
#define C  	         'C'
#define D  	         'D'
#define E  	         'E'
#define F  	         'F'
#define G  	         'G'
#define H  	         'H'
#define I  	         'I'
#define J  	         'J'
#define K  	         'K'
#define L  	         'L'
#define M  	         'M'
#define N  	         'N'
#define O  	         'O'
#define P  	         'P'
#define Q  	         'Q'
#define R  	         'R'
#define S  	         'S'
#define T  	         'T'
#define U  	         'U'
#define V            'V'
#define W  	         'W'
#define X            'X'
#define Y  	         'Y'
#define Z  	         'Z'
#define CHAR_0       '0'
#define CHAR_1       '1'
#define CHAR_2       '2'
#define CHAR_3       '3'
#define CHAR_4       '4'
#define CHAR_5       '5'
#define CHAR_6       '6'
#define CHAR_7       '7'
#define CHAR_8       '8'
#define CHAR_9       '9'

/**
 * Codifica il nome
 * @pre la stringa del nome non deve essere vuota
 * @post il nome codificato deve essere una stringa di tre lettere
 * @param name
 * @param code
 * @return
 */
void name_code(char name[],char* code);

/**
 * Codifica il cognome
 * @pre la stringa del cognome non deve essere vuota
 * @post il cognome codificato deve essere una stringa composta da tre lettere
 * @return
 */
void surname_code(char surname[],char* code);

/**
 * Codifica la data di nascita
 * @pre La data deve essere una stringa avente formato GG/MM/AAAA
 * @post la data codificata deve essere una stringa di quattro caratteri
 * @param date
 * @param sex
 * @param code
 * @return
 */
void birth_date_code(char date[],char sex,char code[]);

/**
 * Genera il carattere di controllo
 * @post il carattere di controllo deve essere una lettera maiuscola
 * @param coded_name
 * @param coded_surname
 * @param coded_birth_date
 * @param coded_birth_place
 * @return
 */
char ctrl_code(char coded_name[],char coded_surname[],char coded_birth_date[],char coded_birth_place[]);

/**
 * Genera il codice fiscale
 * @pre la stringa del nome non deve essere vuota
 * @pre la stringa del cognome non deve essere vuota
 * @pre La data deve essere una stringa avente formato GG/MM/AAAA
 * @post il codice generato deve essere una stringa di 16 caratteri
 * @param name
 * @param surname
 * @param birth_date
 * @param coded_town
 * @param sex
 * @param code
 */
void cf_generator(char name[], char surname[], char birth_date[],char coded_town[], char sex, char code[]);

#endif /* SRC_CFGENERATOR_CF_GENERATOR_H_ */
