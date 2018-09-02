/*
 * to_upper.c
 *
 *  Created on: 26 aprile 2018
 *      Author: Gabriele Fortunato
 */

#include "to_upper.h"

static const int ZERO = 0;

void to_upper_string(char* string){
	for (int i = ZERO; i < strlen(string); i++)
		string[i] = (islower(string[i])) ? toupper(string[i]) : string[i];
}
