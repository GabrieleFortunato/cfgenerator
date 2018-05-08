/*
 * intro.c
 *
 *  Created on: 20 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/intro/intro.h"

void intro(void){
	system(CLS);
	puts(
			NEW_LINE BAR NEW_LINE PRESENTATION_ONE
			NEW_LINE BAR NEW_LINE PRESENTATION_TWO
			NEW_LINE NEW_LINE
	);
}
