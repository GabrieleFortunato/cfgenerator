/*
 * access.c
 *
 *  Created on: 04 mar 2018
 *      Author: Gabriele Fortunato
 */

#include "access.h"

void print_access(FILE* file){
	time_t ora = time(NULL);
	fprintf(
			file,
			ACCESS,
			asctime(localtime(&ora))
	);
}
