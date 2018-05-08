/*
 * repeat.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/repeat/repeat.h"

static int get_repeat(void){
	int repeat=0;
	do{
	printf(STRING);
	scanf(SPEC_REP,&repeat);
	} while(repeat!=1&&repeat!=2);
	return repeat;
}

bool repeat(void){
	return get_repeat()==1;
}
