/*
 * to_upper.c
 *
 *  Created on: 26 aprile 2018
 *      Author: Gabriele Fortunato
 */

#include "../../../src/get_data/to_upper/to_upper.h"

void to_upper_string(char* string){
	for (int i=ZERO;i<strlen(string);i++)
		string[i] = (islower(string[i]))?toupper(string[i]):string[i];
}
