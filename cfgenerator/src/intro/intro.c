/*
 * intro.c
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/intro/intro.h"

static const char* CLS = "CLS";
static const char* PRINT_INTRO =
		"\n======================================="
		"\nPROGRAMMA DI CALCOLO DEL CODICE FISCALE"
		"\n======================================="
		"\na cura di Gabriele Fortunato\n\n";

void intro(void){
	system(CLS);
	puts(PRINT_INTRO);
}
