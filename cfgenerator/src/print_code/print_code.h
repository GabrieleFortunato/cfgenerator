/*
 * print_result.h
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_PRINT_CODE_PRINT_CODE_H_
#define SRC_PRINT_CODE_PRINT_CODE_H_

#include "print_code/cf_generator/cf_generator.h"
#include <stdio.h>
#include <stdlib.h>

#include "../../src/close/close.h"

/**
 * Stampa a video il codice generato
 * @param sex
 * @param coded_town
 * @param birth_date
 * @param surname
 * @param name
 */
void print_code(char* name, char* surname, char* birth_date, char* coded_town, char sex, FILE* towns);

#endif /* SRC_PRINT_CODE_PRINT_CODE_H_ */
