/*
 * print_result.h
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_PRINT_CODE_PRINT_CODE_H_
#define SRC_PRINT_CODE_PRINT_CODE_H_

#include <stdio.h>
#include "print_code/cf_generator/cf_generator.h"

/**
 * Stampa a video il codice generato
 * @param name
 * @param surname
 * @param birth_date
 * @param coded_town
 * @param sex
 * @param towns
 */
void print_code(const char* name, const char* surname, const char* birth_date, const char* coded_town, char sex, FILE* towns);

#endif /* SRC_PRINT_CODE_PRINT_CODE_H_ */
