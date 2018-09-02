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
#include <print_code/is_valid/is_valid.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


/**
 * Codifica il nome
 * @pre la stringa del nome non deve essere vuota
 * @post il nome codificato deve essere una stringa di tre lettere
 * @param name
 * @param code
 */
void name_code(char name[], char* code);

/**
 * Codifica il cognome
 * @pre la stringa del cognome non deve essere vuota
 * @post il cognome codificato deve essere una stringa composta da tre lettere
 * @return
 */
void surname_code(char surname[], char* code);

/**
 * Codifica la data di nascita
 * @pre La data deve essere una stringa avente formato GG/MM/AAAA
 * @post la data codificata deve essere una stringa di quattro caratteri
 * @param date
 * @param sex
 * @param code
 * @return
 */
void birth_date_code(char date[], char sex, char code[]);

/**
 * Genera il carattere di controllo
 * @post il carattere di controllo deve essere una lettera maiuscola
 * @param coded_name
 * @param coded_surname
 * @param coded_birth_date
 * @param coded_birth_place
 * @return
 */
char ctrl_code(char coded_name[], char coded_surname[],char coded_birth_date[], char coded_birth_place[]);

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
