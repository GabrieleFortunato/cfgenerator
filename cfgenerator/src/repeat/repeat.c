/*
 * repeat.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "repeat.h"

static const char* SPEC_INT = "%d";
static const char* REPEAT_STRING =
		"\nCalcolare un altro codice fiscale?\n(1=si,2=no) ";
static const int TWO = 2;
static const int ONE = 1;
static const int ZERO = 0;

static int get_repeat(){
	int repeat = ZERO;
	while (repeat != ONE && repeat != TWO){
		printf(REPEAT_STRING);
		scanf(SPEC_INT, &repeat);
	}
	return repeat;
}

bool repeat(){
	return get_repeat() == ONE;
}
