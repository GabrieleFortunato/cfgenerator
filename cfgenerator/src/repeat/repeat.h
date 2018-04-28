/*
 * repeat.h
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#ifndef SRC_REPEAT_REPEAT_H_
#define SRC_REPEAT_REPEAT_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STRING   "\nCalcolare un altro codice fiscale?\n(1=si,2=no) "
#define SPEC_REP "%d"
/**
 * Verifica l'intenzione dell'utente di calcolare un altro codice fiscale
 * @return
 */
bool repeat(void);

#endif /* SRC_REPEAT_REPEAT_H_ */
