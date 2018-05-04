/*
 * access.h
 *
 *  Created on: 04 mar 2018
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_ACCESS_ACCESS_H_
#define SRC_ACCESS_ACCESS_H_

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "intro/intro.h"

#define ZERO              0
#define ONE               1
#define FILE_ACCESS_NAME  "accessi.txt"
#define ACCESS            "%s"
#define FILE_ACCESS_MODE  "a"

/**
 * Stampa su file la data e l'ora dell'accesso al programma
 */
void print_access(FILE* file);


#endif /* SRC_ACCESS_ACCESS_H_ */
