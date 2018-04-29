/*
 * is_valid.h
 *
 *  Created on: 19 set 2017
 *      Author: gabriele
 */

#ifndef SRC_PRINT_RESULT_IS_VALID_IS_VALID_H_
#define SRC_PRINT_RESULT_IS_VALID_IS_VALID_H_

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <print_result/read_birth_place/read_birth_place.h>

#define ZERO           	0
#define ONE        		1
#define TWO        		2
#define THREE      		3
#define FOUR       		4
#define FIVE       		5
#define SIX        		6
#define SEVEN      		7
#define EIGHT      		8
#define NINE       		9
#define TEN        		10
#define TWELVE     		12
#define THIRTEEN        13
#define FOURTEEN        14
#define SIXTEEN         16
#define THIRTYONE  		31
#define ASCII      		48
#define HUNDRED  	  	100
#define THOUSAND   		1000
#define MIN_YEAR   		1900
#define MAX_YEAR   		2017
#define SLASH      		'/'
#define F 	            'F'
#define M 	            'M'
#define SPACE           ' '
#define APOSTROPHE      '\''
#define EMPTY_STRING    ""

/**
 * Verifica che il codice del cognome e del nome siano corretti
 * @param code
 * @return
 */
bool is_valid_coded_surname_name(char* code);

/**
 * Verifica la correttezza del cognome
 * @param name
 * @return
 */
bool is_valid_name(char* name);


/**
 * Verifica la correttezza del cognome
 * @param surname
 * @return
 */
bool is_valid_surname(char* surname);

/**
 * Verifica che la data sia stata inserita nel giusto formato
 * @param date
 * @return
 */
bool is_valid_date(char* date);

/**
 * Verifica che il carattere di controllo sia una lettera maiuscola
 * @param code
 * @return
 */
bool is_valid_ctrl_code(char code);

/**
 * Verifica che il codice catastale sia nel giusto formato
 * @param code
 * @return
 */
bool is_valid_town_code(char* code);

/**
 *
 * @param code
 * @return
 */
bool is_valid_date_code(char* code);

/**
 * Vericfica che il codice catastale abbia il giusto formato
 * @param code
 * @return
 */
bool is_valid_birth_place_code(char* code);

/**
 * Verifica che il sesso sia rappresentato da un M o da una F
 * @param sex
 * @return
 */
bool is_valid_sex(char sex);

/**
 * Verifica che il codice fiscale abbia il giusto formato
 * @param code
 * @return
 */
bool is_valid_cf_code(char* code);

/**
 * Verifica che la stringa non sia vuola
 * @param string
 * @return
 */
bool is_not_empty_string(char* string);

/**
 * Verifica la correttezza dei dati immessi
 * @param name
 * @param surname
 * @param date
 * @param coded_town
 * @param sex
 * @return
 */
bool is_valid_data(char* name, char* surname, char* date, char* coded_town, char sex);

#endif /* SRC_PRINT_RESULT_IS_VALID_IS_VALID_H_ */
