/*
 * to_upper.c
 *
 *  Created on: 26 aprile 2018
 *      Author: Gabriele Fortunato
 */

#include "../../../src/get_data/to_upper/to_upper.h"

void to_upper(char* string){
	for (int i=ZERO;i<strlen(string);i++){
		if (isalpha(string[i])){
			string[i] = toupper(string[i]);
		}
	};
}
