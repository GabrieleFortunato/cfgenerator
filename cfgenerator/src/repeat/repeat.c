/*
 * repeat.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/repeat/repeat.h"

static const char* SPEC_INT = "%d";
static const char* REPEAT_STRING =
		"\nCalcolare un altro codice fiscale?\n(1=si,2=no) ";
static const int TWO = 2;
static const int ONE = 1;
static const int ZERO = 0;

static int get_repeat(void){
	int repeat = ZERO;
	do{
		printf(REPEAT_STRING);
		scanf(SPEC_INT, &repeat);
	} while (repeat != ONE && repeat != TWO);
	return repeat;
}

bool repeat(void){
	return get_repeat() == ONE;
}
