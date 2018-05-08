/*
 * print_result.c
 *
 *  Created on: 27 ago 2017
 *      Author: Gabriele Fortunato
 */

#include "../../src/print_result/print_code.h"

static void print_code(char* name, char* surname, char* birth_date, char* coded_town, char sex){
	char code [CODE_LENGTH];
	cf_generator(name,surname,birth_date,coded_town,sex,code);
	printf(BAR_RESULT CODE BAR_RESULT,code);
}

static void not_valid_data(){
	printf(NOT_VALID_DATA);
}

void print_result(char sex, char* coded_town, char* birth_date, char* surname, char* name){
	if (is_valid_data(name, surname, birth_date, coded_town, sex)){
		print_code(name,surname,birth_date,coded_town,sex);
	} else {
		not_valid_data();
	}
}
