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

/**
 * Stampa su file la data e l'ora dell'accesso al programma
 * @pre il file deve essere aperto
 * @param file
 */
void print_access(FILE* file);


#endif /* SRC_ACCESS_ACCESS_H_ */
