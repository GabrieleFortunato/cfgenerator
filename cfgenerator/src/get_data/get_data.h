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
#include <print_code/is_valid/is_valid.h>

#include "../../src/get_data/to_upper/to_upper.h"

/**
 * Acquisisce il nome
 * @return
 */
const char* get_name();

/**
 * Acquisisce il cognome
 * @return
 */
const char* get_surname();

/**
 * Acquisisce la data di nascita
 */
const char* get_birth_date();

/**
 * Acquisisce il comune di nascita
 */
const char* get_birth_town();

/**
 * Acquisisce il sesso
 * @return
 */
char get_sex();

#endif /* SRC_GET_DATA_GET_DATA_H_ */
