/*
 * is_valid.h
 *
 *  Created on: 19 set 2017
 *      Author: gabriele
 */

#ifndef SRC_PRINT_CODE_IS_VALID_IS_VALID_H_
#define SRC_PRINT_CODE_IS_VALID_IS_VALID_H_

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include <print_code/read_birth_place/read_birth_place.h>

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
 * Verifica che il codice abbia il giusto formato
 * @param code
 * @return
 */
bool is_valid_date_code(char* code);


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

#endif /* SRC_PRINT_CODE_IS_VALID_IS_VALID_H_ */