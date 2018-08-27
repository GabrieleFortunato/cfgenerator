/*
 * access.c
 *
 *  Created on: 04 mar 2018
 *      Author: Gabriele Fortunato
 */

#include "access.h"

static const char* PRINT_ACCESS = "%s";

void print_access(FILE* file){
	time_t ora = time(NULL);
	fprintf(file, PRINT_ACCESS, asctime(localtime(&ora)));
}
