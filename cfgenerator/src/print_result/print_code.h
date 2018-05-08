/*
 * print_result.h
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_PRINT_RESULT_PRINT_CODE_H_
#define SRC_PRINT_RESULT_PRINT_CODE_H_

#include <stdio.h>
#include <stdlib.h>

#include "../../src/close/close.h"
#include "../../src/print_result/cf_generator/cf_generator.h"
#include "../../src/print_result/read_birth_place/read_birth_place.h"

#define CODE_LENGTH     17
#define BAR_RESULT      "\n================================\n"
#define CODE       	    "Codice fiscale: %s"
#define NOT_VALID_DATA  "\nI dati inseriti non sono tutti corretti\n\n"
#define PAUSE           "PAUSE"

/**
 * Stampa a video il codice generato
 * @param sex
 * @param coded_town
 * @param birth_date
 * @param surname
 * @param name
 */
void print_result(char sex, char* coded_town, char* birth_date, char* surname, char* name);

#endif /* SRC_PRINT_RESULT_PRINT_CODE_H_ */
